#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>


using namespace std;

class Cal {
public:
	int answer;
	int get_answer() { return answer; };
	Cal() {};
	Cal(int input) { answer = input; };
	void set_a(int a) {
		this->a = a;
	}
	void add() {
		answer += a ;
	}
	void mul() {
		answer *= a ;
	}
	void mi() {
		answer -= a ;
	}
	void devi() {
		if ((a != 0)) answer /= a ;
		else cout << "0으로 나눌 수 없습니다.";
	}
	void back() {
		answer = 0;
	}

protected:
	int a;
	int answer_before;

};


int main() {

	string oper = "";
	string selec = "";
	int input1 = 0;
	int answer = 0;
	cout << "첫 번째 값 : ";
	cin >> input1;
	cout << "두 번째 값 : ";
	cin >> answer;
	Cal c(answer);
	c.set_a(input1);

	while (selec != "EXIT") {
		cout << "연산자를 입력해주세요 :";
		cin >> oper;
		if (oper == "+") {
			c.add();
		}
		else if (oper == "-") {
			c.mi();
		}
		else if (oper == "*") {
			c.mul();
		}
		else if (oper == "/") {
			c.devi();
		}
		cout << "결과 : " << c.get_answer() << endl;
		cout << "연산을 계속 진행 하시겠습니까?(Y: 계속, AC: 초기화, EXIT : 종료) : ";
		cin >> selec;
		if (selec == "AC") {
			c.back();
			cout << "결과 : " << c.get_answer() << endl;
			cout << "숫자를 입력해주세요 : ";
			cin >> input1;
			c.set_a(input1);
		}
		else if (selec == "Y") {
			cout << "숫자를 입력해주세요 : ";
			cin >> input1;
			c.set_a(input1);
		}
	}

}