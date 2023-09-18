#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>


using namespace std;


int main() {
	int input_int = 0;
	int cnt = 0;
	int strike = 0;
	int ball = 0;
	int count = 0;
	vector <string> same;
	srand(time(NULL));
	int comnum[3][1] = { {rand() % 10},{rand() % 10},{rand() % 10} };
	for (int* i : comnum) {
		cout << *i << endl;
	}
	while (cnt == 0) {
		vector <int> input;
		strike = 0;
		ball = 0;
		cout << endl << "입력 : ";
		for (int i = 0; i < 3; i++) {
			cin >> input_int;
			input.push_back(input_int);
		}

		for (int i = 0; i < 3; i++) {
			if (comnum[i][0] == input[i])
				strike++;
			for (int j = 0; j < 3; j++) {
				if (input[j] == comnum[i][0] && comnum[i][0] != input[i])
					ball++;
			}
		}
		if (strike == 3)
			cnt = 1;
		else {
			cout << endl << "--------" << endl;
			cout << "strike = " << strike;
			cout << "  ball = " << ball << endl;
			cout << "--------" << endl;
		}
		count++;
	}

	cout << count << "번 만에 맞췄습니다." << endl;
}