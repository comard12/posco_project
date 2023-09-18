#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <math.h>
using namespace std;

int N_size(int num_of_square); // 몇 자리인지 알려줌 (결과 출력 시 필요)
void Say(int** array, int n); // 결과출력




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

int main() {
	int n = 0;
	int num_of_square = 0;
	int count = 1;
	cout << "N의 값(홀수) : ";
	cin >> n;
	num_of_square = n*n;

	int** array = new int* [n] ; //세로 생성
	
	for (int i = 0; i < n; i++) { //가로생성
		array[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {	// 0 으로 초기화
		for (int j = 0; j <= n; j++) {
			array[i][j] = 0;
		}
	}


	int strx = (n + 1) / 2 - 1; // x 값
	int stry = n - 1;           // y 값

	while (num_of_square > 0) { // 마방진 푸는 법
		if (stry > n - 1) {
			stry = 0;
		}
		if (strx > n - 1 ) {
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

	N_size(n*n);
	Say(array,n);
	
	delete array;



	return 0;
}