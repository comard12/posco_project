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
		while (comnum[0][0] == comnum[1][0] || comnum[1][0] == comnum[2][0] || comnum[2][0] == comnum[0][0]) {
			for (int* i : comnum) {
				*i = rand()%10;
			}
	}
		cout << "�߱�����" << endl;

	while (cnt == 0) {
		vector <int> input;
		strike = 0;
		ball = 0;
		cout << "1~9 ������ ���� 3���� �Է� �Ͻÿ� ( ���� : �̿��� ���� ) : ";
		for (int i = 0; i < 3; i++) {
			cin >> input_int;
			input.push_back(input_int);
			if (input_int > 9 || input_int <= 0) {
				cnt = 1;
			}
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
			cnt = 2;

		else if (cnt != 1){
			cout << "strike = " << strike;
			cout << "   ball = " << ball << endl;
		}
		count++;
	}
	if (cnt == 2) {
		cout << count << "�� ���� ������ϴ�." << endl;
	}
	else {
		cout << "���� ����" << endl;
	}
}