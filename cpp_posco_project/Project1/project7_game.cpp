#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


class character {
public:
	string tool;
	character(string name) {
		this->name = name;
	};
	string get_name() {
		return name;
	}
	int get_hp() {
		return hp;
	}
	int get_item() {
		return item;
	}
	 bool getitem() {
		if (item > 0) {
			this->set_item();
			return true;
		}
		else {
			cout << "아이템 창이 꽉 찼습니다." << endl;
			return false;
		}
	}
	void set_hp(int a) {
		hp -= a;
	}
	void set_level() {
		level++;
	}
	void set_item() {
		this->item--;
	}

private:
	string name;
	int hp = 100;
	int level = 0;
	int item = 5;
};

class tool {
public:
	string name;
	int power;
	int hp;
	tool() {};
	virtual void attack(character c) {

	}
};

class knife : tool {
public:
	knife(string name) { this->name = name; power = 5; hp = 3; };
	string get_name() {
		return name;
	}
	void attack(character *c) {
		if (hp > 0) {
			cout << "찌르기" << endl;
			c->set_hp(power);
			this->hp--;
		}
		else {
			cout << "무기의 내구도가 0 입니다." << endl;
		}
	}
};

class gun : tool {
public:
	gun(string name) { this->name = name; power = 10; hp = 1; };
	string get_name() {
		return name;
	}
	void attack(character *c) {
		if (hp > 0) {
			cout << "총쏘기" << endl;
			c->set_hp(power);
			this->hp--;
		}
		else {
			cout << "무기의 내구도가 0 입니다." << endl;
		}
	}
};

int main() {
	vector <character> t;
	vector <gun> chong;
	vector <knife> kal;
	for (int i = 0; i < 3; i++) {
		cout << i+1 << " 번 캐릭터 닉네임 : ";
		bool same = false;
		string input;
		getline(cin, input);
		character c(input);
		for (auto o : t) {
			if (o.get_name() == input) {
				same = true;
			}
		}
		if(!same){
			t.push_back(c);
		}
		else {
			cout << "다시입력하세요" << endl;
			i--;
		}
	}
	srand(time(NULL));
	while (1) {
		int randnum = rand()%2+1;
		bool same = false;
		string input;
		int d;
		bool is = false;
		int num = 0;
		cout << "==========상태창=========="<<endl;
		for (auto i : t) {
			
			cout << i.get_name() << " ";
			cout <<"hp :" << i.get_hp() << " ";
			cout << "item :" << i.get_item() << endl;
			
		}
		cout << "======================" << endl;
		cout << "캐릭터를 고르세요 : ";
		cin >> input;
		for (auto &o : t) {
			if (o.get_name() == input) {
				is = true;
				cout << o.get_name() << "의 행동 (1: 공격, 2: 무기줍기) : ";
				cin >> d;
				switch (d)
				{
				case 1:
					if (o.get_item() == 5) {
						cout << "무기가 없습니다." << endl;
					}
					else {
						cout << "무기 리스트" << endl;
						for (auto w : chong) {
							if (w.get_name() == o.get_name()) {
								cout << "총 ";
							}
						}
						for (auto y : kal) {
							if (y.get_name() == o.get_name()) {
								cout << "칼 ";
							}
						}
						cout << endl;
						cout << "공격 대상 : ";
						string att;
						cin >> att;
						for (auto& q : t) {
							if (q.get_name() == att) {
								cout << "타깃확인" << endl;
								cout << "무기를 고르세요(1: 총 2: 칼) : ";
								int p = 0;
								while (!(p == 1 || p == 2)) {
									cin >> p;
								}
								if (p == 1) {
									for (auto &f : chong) {
										if (f.get_name() == o.get_name()) {
											f.attack(&q);
										}
									}
								}
								else if (p == 2) {
									for (auto &k : kal) {
										if (k.get_name() == o.get_name()) {
											k.attack(&q);
										}
									}
								}
							}
						}
					}

					break;
				case 2:
					cout << "무기줍기 " << endl;
					if (rand() % 2 + 1 == 1) {
						if (o.getitem()) {
							knife k(o.get_name());
							kal.push_back(k);
							cout << "칼획득" << endl;
						}
					}
					else {
						if (o.getitem()) {
							gun g(o.get_name());
							chong.push_back(g);
							cout << "총획득" << endl;
						}
					}
					break;
				}
			
				
				cout << "행동 끝" << endl;
				break;
			}
			num++;
		}
		if (!is) {
			cout << "로그인 실패" << endl;
		}

	}

}