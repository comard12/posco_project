#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <math.h>
using namespace std;

int N_size(int num_of_square); // �� �ڸ����� �˷��� (��� ��� �� �ʿ�)
void Say(int** array, int n); // ������
bool is_it_odd(int n); // Ȧ������ �Ǻ�
int** arraymk(int** array, int n); // �迭 ����
int** magicmk(int** array, int n); // ������ ����


int main() {
	int n = 0;
	int num_of_square = 0;

	cout << "N�� ��(Ȧ��) : ";
	cin >> n;
	if (!is_it_odd(n)) {
		while (!is_it_odd(n))
		{
			cout << "Ȧ���� �Է��ϼ���" << endl;
			cout << "N�� ��(Ȧ��) : ";
			cin >> n;
		}
	}

	num_of_square = n * n; // ������ ũ��

	int** array = new int* [n]; //���� ����
	arraymk(array, n); // ���� ����, 0���� �ʱ�ȭ
	array = magicmk(array,n); // ������ ����

	N_size(n * n);
	Say(array, n); // ��� ���
	delete array;
	return 0;
}

bool is_it_odd(int n) {
	if (n % 2 == 0) {
		return false;
	}
	else
		return true;
}

int N_size(int num_of_square) {
	int si = 10;
	int size = 1;
	int stop = 0;
	while (stop == 0) {
		if (num_of_square / si != 0) {
			size++;
		}
		else {
			stop = 1;
		}
		si *= 10;
	}
	return size;
}


void Say(int** array,int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num = N_size(array[i][j]);
			int max = N_size(n * n);
			while (num < max) {
				cout << " ";
				num++;
			}
			cout <<" " << array[i][j];
		}
		cout << endl;
	}

}
int** arraymk(int** array, int n) {
	for (int i = 0; i < n; i++) { //���λ���
		array[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {	// 0 ���� �ʱ�ȭ
		for (int j = 0; j <= n; j++) {
			array[i][j] = 0;
		}
	}
	return array;
}
int** magicmk(int** array, int n) {
	int count = 1;
	int num_of_square = n * n;
	int strx = (n + 1) / 2 - 1; // x ��
	int stry = n - 1;           // y ��
	while (num_of_square > 0) { // ������ Ǫ�� ��
		if (stry > n - 1) {
			stry = 0;
		}
		if (strx > n - 1) {
			strx = 0;
		}
		if (array[stry][strx] != 0) {
			stry--;
		}
		array[stry][strx] = count;
		strx++;
		stry++;
		count++;
		num_of_square--;
	}
	return array;
}

