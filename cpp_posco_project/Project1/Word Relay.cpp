#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

#define delay 30000  //딜레이 30초
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
	cout << "단어 입력 : ";
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
			return false;
		}
		else {
			return true;
		}
	}
}

int main() {
	vector <string> box;
	string vowl;
	char last;
	bool ctn = true;
	int turn = 0; // 1 or 0
	time_t new_time, old_time;
	new_time = clock();
	old_time = clock();
	cout << "나 홀로 끝말잇기 스타트..!!" << endl;
	box = start(box, vowl, turn);
	History(box);
	turn = Turn(turn);
	while (old_time- new_time < delay) {
		old_time = clock();
		last = box.back().back();
		vowl = get();
		box.push_back(vowl);
		if (last == vowl.front()&& Check(box,vowl)) {
		}
		else {
			box.pop_back();
			cout << "다시 입력하세요" << endl;
		}
		History(box);
	}
	cout << "제한시간 초과 !! " << endl;
	box.pop_back();
	cout <<"총 단어 " << box.size() << endl;
	return 0;
}