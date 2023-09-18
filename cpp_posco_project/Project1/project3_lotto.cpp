#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

vector <int> lottomk(); // 로또번호 생성기
int counter(vector <int> lotto); // 맞춘개수 세기
void Say(vector <int> lotto); // 로또번호 공개
void Win(int count); // 등수 산출


int main() {
	vector <int> lotto;
	int input = 0;
	int count = 0;
	srand(time(NULL));

	lotto = lottomk();
	count = counter(lotto);
	Say(lotto);
	Win(count);

}

vector <int> lottomk() {
	vector <int> lotto;
	for (int i = 0; i < 6; i++) {
		int j = 0;
		j = rand() % 25;
		lotto.push_back(j);
	}
	return lotto;
}

int counter(vector <int> lotto) {
	int count = 0;
	int input = 0;
	vector <int> check;
	for (int x = 0; x < 6; x++) {
		cout << x + 1 << "번째 값을 입력해주세요 : ";
		cin >> input;
		auto it1 = find(check.begin(), check.end(), input);
		if(it1 != check.end()){
			cout << "중복입니다" << endl;
			x--;
		}
		else {
			check.push_back(input);
			auto it2 = find(lotto.begin(), lotto.end(), input);
			if (it2 == lotto.end()) {
			}
			else {
				count++;
			}
		}
	}
	return count;
}

void Say(vector <int> lotto) {
	cout << "*************************" << endl;
	cout << "당첨번호 공개!" << endl;
	for (int y : lotto) {
		cout << y << " ";
	}
	cout << endl;
}

void Win(int count) {
	switch (count) {
	case(0):
		cout << "7등 입니다." << endl;
		break;
	case(1):
		cout << "6등 입니다." << endl;
		break;
	case(2):
		cout << "5등 입니다." << endl;
		break;
	case(3):
		cout << "4등 입니다." << endl;
		break;
	case(4):
		cout << "3등 입니다." << endl;
		break;
	case(5):
		cout << "2등 입니다." << endl;
		break;
	case(6):
		cout << "1등 입니다." << endl;
		break;
	}
}