#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define Max 31


bool Under(int input) {
	if (input < 4&& 0<input ) {
		return true;
	}
	else{
		cout << "3���ϸ� �Է��ϼ���" << endl;;
		return false;
	}
}

int Say(int array[], int current, int input) {
	int cnt = 1;
	for (int i = current; i < current + input; i++) {
		if (array[i]== Max) {
			cnt = 0;
			cout << array[i] << endl;
			return -1;
			break;
		}
		cout << array[i] << endl;
	}
	if (cnt != 0) {
		current += input;
		return current;
	}
}
int com() {
	srand(time(NULL));
	int com_num = rand() % 3;
	while (com_num == 0) { com_num = rand() % 3; }
	return com_num;
}

// �����ʸ� 1, ��ǻ�����ʸ� 2
int Turn(int turn) {
	if (turn == 1) {
		return 2;
	}
	else {

		return 1;
	}
}

void Chat_end(int turn) {
	if (turn == 1) {
		cout << "�й� �ϼ̽��ϴ� �Ф�" << endl;
	}
	else {
		cout << "**********************" << endl;
		cout << "  �¸��ϼ̽��ϴ�!!" << endl;
		cout << "**********************" << endl;
	}

}

void Chat_start() {
		cout << "**********************" << endl;
		cout << "      31 game!!" << endl;
		cout << "**********************" << endl;

}


int main() {
	Chat_start();
	int cnt = 1;
	int current = 0;
	int input = 0;
	int array[Max];
	int turn = 0;
	for (int &i : array) {
		i = cnt;
		cnt++;
	}


	while(current != -1){
		int com_num = com();
		cout << "1~3�� �Է��ϼ��� : ";
		cin >> input;
		if (Under(input) == true && current != -1) {
			turn = Turn(turn);
			current = Say(array, current, input);
			if (current != -1) {
				turn = Turn(turn);
				cout << "��ǻ�� ���� : " << com_num << endl;
				current = Say(array, current, com_num);
			}
		}
	}
	Chat_end(turn);
	return 0;
}