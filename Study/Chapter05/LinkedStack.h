#pragma once
#include "Node.h"

class LinkedStack {
	Node* top;			//헤드 포인터.
public:
	LinkedStack() { top = NULL; }								//생성자.
	
	~LinkedStack() { while (!isEmpty()) delete pop(); }			//소멸자.
	
	bool isEmpty() { return top == NULL; }
	
	void push(Node* p) {
		if (isEmpty()) top = p;
		else {
			p->setLink(top);			
			top = p;
		}
	}

	Node* pop() {
		if (isEmpty()) return NULL;
		Node* p = top;
		top = top->getLink();
		return p;
	}

	Node* peek() { return top; }

	void display() {			//화면 출력.
		printf("[LinkedStack]\n");
		for (Node* p = top; p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}

};
