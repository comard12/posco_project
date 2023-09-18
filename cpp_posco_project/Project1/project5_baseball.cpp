#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <math.h>


using namespace std;

void mk_num(vector <int> &com_num) {
	int randnum = 0;
	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		randnum = rand()%10;
		com_num.push_back(randnum);
	}
}

int main() {
	int comnum[3];
	int input[3];
	vector <int> same;
	int strike = 0;
	int ball = 0;
	cin >> input[0] >> input[1] >> input[2];

	for (int i : input) {
		cout << input;
	}



}