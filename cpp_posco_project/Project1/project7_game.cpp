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
			cout << "������ â�� �� á���ϴ�." << endl;
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
			cout << "���" << endl;
			c->set_hp(power);
			this->hp--;
		}
		else {
			cout << "������ �������� 0 �Դϴ�." << endl;
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
			cout << "�ѽ��" << endl;
			c->set_hp(power);
			this->hp--;
		}
		else {
			cout << "������ �������� 0 �Դϴ�." << endl;
		}
	}
};

int main() {
	vector <character> t;
	vector <gun> chong;
	vector <knife> kal;
	for (int i = 0; i < 3; i++) {
		cout << i+1 << " �� ĳ���� �г��� : ";
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
			cout << "�ٽ��Է��ϼ���" << endl;
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
		cout << "==========����â=========="<<endl;
		for (auto i : t) {
			
			cout << i.get_name() << " ";
			cout <<"hp :" << i.get_hp() << " ";
			cout << "item :" << i.get_item() << endl;
			
		}
		cout << "======================" << endl;
		cout << "ĳ���͸� ������ : ";
		cin >> input;
		for (auto &o : t) {
			if (o.get_name() == input) {
				is = true;
				cout << o.get_name() << "�� �ൿ (1: ����, 2: �����ݱ�) : ";
				cin >> d;
				switch (d)
				{
				case 1:
					if (o.get_item() == 5) {
						cout << "���Ⱑ �����ϴ�." << endl;
					}
					else {
						cout << "���� ����Ʈ" << endl;
						for (auto w : chong) {
							if (w.get_name() == o.get_name()) {
								cout << "�� ";
							}
						}
						for (auto y : kal) {
							if (y.get_name() == o.get_name()) {
								cout << "Į ";
							}
						}
						cout << endl;
						cout << "���� ��� : ";
						string att;
						cin >> att;
						for (auto& q : t) {
							if (q.get_name() == att) {
								cout << "Ÿ��Ȯ��" << endl;
								cout << "���⸦ ������(1: �� 2: Į) : ";
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
					cout << "�����ݱ� " << endl;
					if (rand() % 2 + 1 == 1) {
						if (o.getitem()) {
							knife k(o.get_name());
							kal.push_back(k);
							cout << "Įȹ��" << endl;
						}
					}
					else {
						if (o.getitem()) {
							gun g(o.get_name());
							chong.push_back(g);
							cout << "��ȹ��" << endl;
						}
					}
					break;
				}
			
				
				cout << "�ൿ ��" << endl;
				break;
			}
			num++;
		}
		if (!is) {
			cout << "�α��� ����" << endl;
		}

	}

}