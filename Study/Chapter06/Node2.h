#pragma once
#include <iostream>
using namespace std;

class Node2 {
	Node2* prev;		// 선행 노드를 가리키기 위한 포인터 변수.
	Node2* next;		// 후속 노드를 가리키기 위한 포인터 변수.
	int data;			// 데이터 필드.

public:
	Node2(int val=0): data(val),prev(NULL),next(NULL){}
	Node2* getPrev() { return prev; }
	Node2* getNext() { return next; }
	void setPrev(Node2* p) { prev = p; }
	void setNext(Node2* n) { next = n; }
	void display() { printf("<%2d>", data); }
	bool hasData(int val) { return data == val; }

	//자신의 다음에 새로운 노드 n을 삽입하는 함수.
	void insertNext(Node2* n) {
		if (n != NULL) {
			n->prev = this;			//삽입할 N의 선행 노드를 현재 노드로 설정(B , C 사이에 삽입할때에 B에 설정).
			n->next = next;			//N의 후속노드를 C(B와 연결된 후속노드)와 설정.
			if (next != NULL) next->prev = n;		//C의 선행노드를 N으로 설정.
			next = n;				//B의 후속노드를 N으로 설정.
		}
	}

	//현재노드를 연결 리스트에서 제거하는 함수.
	Node2* remove() {										// B 와 C 사이에 삽입되있던 N을 제거하는 경우.
		if (prev != NULL) prev->next = next;				// B의 후속노드를 C로 설정.
		if (next != NULL) next->prev = prev;				// C의 선행노드를 B로 설정.
		return this;										// 삭제한 N 반환.
	}

};
