#pragma once
#include <iostream>
using namespace std;

class Node {
	Node* link;			//다음 노드를 가리키기 위한 포인터 변수.
	int data;			//노드의 데이터 필드.

public:
	Node(int val = 0) :data(val), link(NULL) {}

	Node* getLink() { return link; }

	void setLink(Node* next) { link = next; }

	void display() { printf(" <%2d>", data); }

	bool hasData(int val) { return data == val; }

	//자신의 다음에 새로운 노드  n을 삽입하는 함수.
	void insertNext(Node* n) {
		if (n != NULL) {		//마지막 노드가 아니라면.
			n->link = link;			//삽입할 노드가 후속 노드랑 연결.
			link = n;				//현재 노드를 삽입할 노드랑 연결.
		}
	}

	// 자신의 다음 노드를 리스트에서 삭제하는 함수.
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL) {
			link = removed->link;		//현재 노드가 삭제할 노드 다음의 후속 노드를 가리킴.
		}
		return removed;
	}
};
