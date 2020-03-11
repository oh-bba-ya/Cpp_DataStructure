#pragma once
#include "Node2.h"

class DblLinkedList {				//Dbl(소문자 엘).
	Node2 org;				//헤드 노드.

public:
	DblLinkedList() :org(0) {}										//생성자.
	~DblLinkedList() { while (!isEmpty()) delete remove(0); }		//소멸자.
	Node2* getHead() {return org.getNext(); }
	bool isEmpty() { return getHead() == NULL; }

	Node2* getEntry(int pos) {			//pos번째 노드 반환.
		Node2* n = &org;
		for (int i = -1; i < pos; i++, n = n->getNext())
			if (n == NULL) break;
		return n;
	}

	void insert(int pos, Node2* n) {			//pos 위치에 노드 삽입.
		Node2* prev = getEntry(pos - 1);
		if (prev != NULL) {
			prev->insertNext(n);
		}

	}

	Node2* remove(int pos){			//pos 위치의 노드 삭제.
		Node2* n = getEntry(pos);
		return n->remove();
	}

	Node2* find(int val) {			// 값이 val인 노드 탐색.
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			if (p->hasData(val)) return p;
		return NULL;

	}

	void replace(int pos, Node2* n) {		// pos 위치의 노드 교체.
		Node2* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->getNext()->remove();
			prev->insertNext(n);
		}
	}

	int size() {			//리스트의 전체 노드 수 반환.
		int count = 0;
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			count++;
		return count;
	}

	void display() {
		printf("[이중연결리스트 항목 수 = %2d] : ", size());
		for (Node2* p = getHead() ; p != NULL; p = p->getNext())
			p->display();
		printf("\n");
	}

	void clear() { while (!isEmpty()) delete remove(0); }
};
