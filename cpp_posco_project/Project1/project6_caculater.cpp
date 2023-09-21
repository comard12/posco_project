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
		else cout << "0���� ���� �� �����ϴ�.";
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
	cout << "ù ��° �� : ";
	cin >> input1;
	cout << "�� ��° �� : ";
	cin >> answer;
	Cal c(answer);
	c.set_a(input1);

	while (selec != "EXIT") {
		cout << "�����ڸ� �Է����ּ��� :";
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
		cout << "��� : " << c.get_answer() << endl;
		cout << "������ ��� ���� �Ͻðڽ��ϱ�?(Y: ���, AC: �ʱ�ȭ, EXIT : ����) : ";
		cin >> selec;
		if (selec == "AC") {
			c.back();
			cout << "��� : " << c.get_answer() << endl;
			cout << "���ڸ� �Է����ּ��� : ";
			cin >> input1;
			c.set_a(input1);
		}
		else if (selec == "Y") {
			cout << "���ڸ� �Է����ּ��� : ";
			cin >> input1;
			c.set_a(input1);
		}
	}

}