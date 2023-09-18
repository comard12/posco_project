#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <math.h>
using namespace std;

int N_size(int num_of_square); // 몇 자리인지 알려줌 (결과 출력 시 필요)
void Say(int** array, int n); // 결과출력
bool is_it_odd(int n); // 홀수인지 판별
int** arraymk(int** array, int n); // 배열 생성
int** magicmk(int** array, int n); // 마방진 생성


int main() {
	int n = 0;
	int num_of_square = 0;

	cout << "N의 값(홀수) : ";
	cin >> n;
	if (!is_it_odd(n)) {
		while (!is_it_odd(n))
		{
			cout << "홀수를 입력하세요" << endl;
			cout << "N의 값(홀수) : ";
			cin >> n;
		}
	}

	num_of_square = n * n; // 마방진 크기

	int** array = new int* [n]; //세로 생성
	arraymk(array, n); // 가로 생성, 0으로 초기화
	array = magicmk(array,n); // 마방진 생성

	N_size(n * n);
	Say(array, n); // 결과 출력
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
	for (int i = 0; i < n; i++) { //가로생성
		array[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {	// 0 으로 초기화
		for (int j = 0; j <= n; j++) {
			array[i][j] = 0;
		}
	}
	return array;
}
int** magicmk(int** array, int n) {
	int count = 1;
	int num_of_square = n * n;
	int strx = (n + 1) / 2 - 1; // x 값
	int stry = n - 1;           // y 값
	while (num_of_square > 0) { // 마방진 푸는 법
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

