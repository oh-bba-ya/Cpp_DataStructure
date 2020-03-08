#include <iostream>

using namespace std;

/*
	배열로 스택을 구현.
*/


const int MAX_STACK_SIZE = 20;			//스택의 최대 크기 설정.

class ArrayStack {
private:
	int top;			//요소의 개수.
	int data[MAX_STACK_SIZE];		//요소의 배열.

public:
	ArrayStack() { top = -1; }				//배열안의 공백시 디폴트 -1 설정.
	~ArrayStack() {}			//소멸자.

	bool isEmpty() { return top==-1 ; }		//배열안의 요소가 한개도 없을시.

	bool isFull() { return top == MAX_STACK_SIZE - 1; }		//배열안의 요소가 꽉찼을때.

	void push(int e) {		//배열의 맨 위 주소에 항목 삽입.
		if (isFull()) {
			cout << "스택 포화 에러" << endl;
			exit(1);
		}
		else {
			data[++top] = e;
			
		}
		
	}

	int pop() {		//맨위의 요소를 삭제하고 반환.
		if (isEmpty()) {
			cout << "스택 공백 에러" << endl;
			exit(1);
		}
		else {
			
			return data[top--];
		}
		
	}

	int peek() {		//삭제하지 않고 요소 반환.
		if (isEmpty()) {
			cout << "스택 공백 에러" << endl;
			exit(1);
		}
		else {
			return data[top];
		}
		
	}

	void display() {		//스택 내용을 화면에 출력.
		cout << "[스택 항목의 수 = " << top + 1 << "]" << endl;
		for (int i = 0; i <= top; i++) {
			cout << data[i]<<", ";
		}
	}
};
