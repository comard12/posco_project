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
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> input1;
	Cal cal(input1);
	cout << "�����ڸ� �Է��ϼ��� : ";
	cin >> oper;
	cout << "���ڸ� �Է��ϼ��� : ";
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
		cout << "������ ��� ���� �Ͻðڽ��ϱ�?(Y: ���, AC: �ʱ�ȭ, EXIT : ����) : ";
		cin >> oper;
	}

}