#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

#define delay 10000  //������ 30��
void History(vector <string> box) {
	for (string i : box) {
		cout << i<<"->";
	}
	cout << endl;
}

int Turn(int turn) {
	if (turn == 1) {
		return 0;
	}
	else
		return 1;
}
string get() {
	string vowl;
	cout << "�ܾ� �Է� : ";
	cin >> vowl;
	return vowl;
}
vector <string> start(vector <string> box, string vowl,int turn) {
	box.push_back(get());
	return box;
}
bool Check(vector <string> box, string element) {
	for (string i : box) {
		if (i == element) {
			return true;
		}
	}
	return false;
}

int main() {
	vector <string> box;
	vector <string> box_before;
	string vowl;
	char last;
	bool ctn = true;
	int turn = 0; // 1 or 0
	time_t new_time, old_time;
	new_time = clock();
	old_time = clock();
	cout << "�� Ȧ�� �����ձ� ��ŸƮ..!!" << endl;
	box = start(box, vowl, turn);
	History(box);
	turn = Turn(turn);
	while (old_time- new_time < delay) {
		old_time = clock();
		last = box.back().back();
		box_before = box;
		box.push_back(get());

		if (last != box.back().front()) { // ����üũ
			box.pop_back();
			cout << "������ �°� �ۼ��ؾ� �մϴ�!!" << endl;
		}

		else if (Check(box_before, box.back())) { // �ߺ�üũ
			box.pop_back();
			cout << "�ߺ��� �ܾ��Դϴ�!!" << endl;
		}

		History(box);
	}
	cout << "���ѽð� �ʰ� !! " << endl;
	box.pop_back();
	cout <<"�� �ܾ� " << box.size() << endl;
	return 0;
}