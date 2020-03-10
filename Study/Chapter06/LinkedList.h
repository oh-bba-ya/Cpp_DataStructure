#pragma once
#include "Node.h"

class LinkedList {
	Node org;			//헤드 노드( 헤드 포인터가 아니다).

public:
	LinkedList():org(0){}		//생성자.
	~LinkedList() { clear(); }		//소멸자.
	void clear() { while (!isEmpty()) delete remove(0); }
	Node* getHead() { return org.getLink(); }
	bool isEmpty() { return getHead() == NULL; }

	//pos번째 항목을 반환함.
	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink()) {
			if (n == NULL) break;
		}
		return n;
	}

	//리스트의 어떤 위치에 항목 삽입.
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	//리스트의 어떤 위치의 항목 삭제.
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	//탐색 함수.
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			if (p->hasData(val)) return p;
		}
		return NULL;
	}

	//리스트의 pos번째 노드를 다른 노드로 교체.
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	//리스트의 항목 개수를 반환.
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			count++;
		}
		return count;
	}

	//화면에 보기 좋게 출력.
	void display() {
		printf("[전체 항목 수 = %2d] : ", size());
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}

};
