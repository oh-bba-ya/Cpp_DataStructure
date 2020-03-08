#pragma once
#include "Student.h"

const int MAX_STACK_SIZE = 100;		//스택의 최대 크기 설정.

class StudentStack {
private:
	int top;							//요소의 개수.
	Student data[MAX_STACK_SIZE];		//요소의 배열.

public:
	StudentStack() { top = -1; }
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(Student e) {		//맨위 항목 삽입.
		if (isFull()) {
			cout << "스택 포화 에러" << endl;
		}
		else
			data[++top] = e;
	}

	Student pop() {		//맨 위의 요소를 삭제하고 반환.
		if (isEmpty())
			cout << "스택 공백 에러" << endl;
		else
			return data[top--];
	}

	Student peek() {		//맨 위의 요소를 반환.
		if (isEmpty())
			cout << "스택 공백 에러" << endl;
		else
			return data[top];
	}

	void display() {
		cout << "[전체 학생의 수 = " << top + 1 << "]" << endl;
		for (int i = 0; i <= top; i++) {
			data[i].display();			//각 학생 정보 출력.
			cout << endl;
		}
	}

};
