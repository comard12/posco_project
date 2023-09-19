#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>


using namespace std;

class Cal {
public:
	static int answer;
	virtual int get_answer() { return answer; };
	int back() { answer = answer_before; };
	Cal() {};
	Cal(int input) { answer = input; };
protected:
	int answer_before;

};

class Plus : public Cal {
	int get_answer(){
		return answer;
	}
	Plus(int input) {
		answer += input;
	}
};

class multi : public  Cal {
	int get_answer() {
		return this->answer;
	}
	multi(int input) {
		answer *= input;
	}
};

class minus : public  Cal {
	int get_answer() {
		return answer;
	}
	minus(int input) {
		answer *= input;
	}

};

class divi : public  Cal {
	int get_answer() {
		return answer;
	}
	divi(int input) {
		answer *= input;
	}

};

int Cal::answer = 0;

int main() {

	int input1;
	int input2;
	string oper;
	cout << "숫자를 입력하세요 : ";
	cin >> input1;
	Cal cal(input1);
	cout << "연산자를 입력하세요 : ";
	cin >> oper;
	cout << "숫자를 입력하세요 : ";
	cin >> input2;
	while (oper != "EXIT") {
		if (oper == "+") {
			Plus plus();
		}
		else if (oper == "-") {

		}
		else if (oper == "*") {

		}
		else if (oper == "/") {

		}
		else if (oper == "AC") {

		}
		else if (oper == "Y") {

		}
		cout << "연산을 계속 진행 하시겠습니까?(Y: 계속, AC: 초기화, EXIT : 종료) : ";
		cin >> oper;
	}

}