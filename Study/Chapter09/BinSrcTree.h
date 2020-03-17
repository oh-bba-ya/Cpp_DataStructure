#pragma once
#include "BinaryTree.h"

class BinSrchTree :public BinaryTree {                      // 아직 succp에서 오류가 발견되서 해결할 방법을 못찾았기에 h 파일만 올린다.
public:
	BinSrchTree(void) {}
	~BinSrchTree(void) {}


	// 이진 탐색 트리의 탐색 연산.
	BinaryNode* search(int key) {
		BinaryNode* node = searchRecur(root, key);
		if (node != NULL) {
			printf("탐색 성공: 키 값이 %d 인노드 = 0x%x\n", node->getData(), node);
		}
		else
			printf("탐색 실패: 키 값이 %d인 노드 없음\n", key);
		return node;
	}


	//이진 트리의 삽입 연산.
	void insert(BinaryNode* n) {
		if (n == NULL) return;
		if (isEmpty()) root = n;
		else insertRecur(root, n);
	}


	// 이진 탐색 트리의 삭제 연산.
	void remove(int key) {
		if (isEmpty()) return;

		//없애 노드와 그 노드의 부모 노드를 찾는다.
		BinaryNode* parent = NULL;			// 없앨 노드의 부모.
		BinaryNode* node = root;			// 없앨 노드.
		while (node != NULL && node->getData() != key) {
			parent = node;
			node = (key < node->getData())
				? node->getLeft() : node->getRight();
		}
		//없앨 노드가 트리에 없음.
		if (node == NULL) {
			printf(" Error: key is not in the tree!\n");
			return;
		}
		// 없앨 노드가 트리에 있음.
		else remove(parent, node);
	}
	
	// 키 값으로 노드를 탐색하는 함수(순환적인 방법).
	BinaryNode* searchRecur(BinaryNode* n, int key) {
		if (n == NULL) return NULL;				// n is NULL.
		
		if (key == n->getData()) {				// key == 현재 노드의 data.
			return n;
		}

		else if (key < n->getData())			// key < 현재 노드의 data.
			return searchRecur(n->getLeft(), key);

		else                                            // key > 현재 노드의 data.
			return searchRecur(n->getRight(), key);
	}

	// 키 값으로 노드를 탐색하는 함수(반복적인 방법).
	BinaryNode* searchIter(BinaryNode* n, int key) {    // Iter -> I( 대문자 i)
		while (n != NULL) {
			if (key == n->getData())							// key == 현재노드의 data.
				return n;

			/*
				73 ~ 76 행: key가 N의 key 보다 작으면 왼쪽 자식으로 이동 후 while문 반복.
			*/
			else if (key < n->getData())						// data < key
				n = n->getLeft();

			/*
				81 ~ 82 행: key가 N의 key 보다 크면 오른쪽 자식으로 이동 후 while문 반복.
			*/
			else                                               // data > key
				n = n->getRight();
		}
		return NULL;						// 탐색에 실패한경우 NULL 반환.
	}


	// 이진 탐색 트리의 삽입 함수(순환적인 방법)
	void insertRecur(BinaryNode* r, BinaryNode* n) {			// r = 루트. n = 삽입할 노드.
		if (n->getData() == r->getData())
			return;
		else if (n->getData() < r->getData()) {
			if (r->getLeft() == NULL)
				r->setLeft(n);
			else
				insertRecur(r->getLeft(), n);

		}
		else
		{
			if (r->getRight() == NULL)
				r->setRight(n);
			else
				insertRecur(r->getRight(), n);
		}
	}


	// 이진 탐색 트리의 삭제 함수(순환적인 방법)
	void remove(BinaryNode* parent, BinaryNode* node) {
		// case1 : 삭제하려는 노드가 단말 노드일 경우.
		if (node->isLeaf()) {
			if (parent == NULL)				// node == root인 경우 => 공백상태가 됨.
				root = NULL;
			else {
				if (parent->getLeft() == node)
					parent->setLeft(NULL);
				else
					parent->setRight(NULL);
			}
		}

		//case2 : 삭제하려는 노드가 왼쪽이나 오른쪽 자신만 갖는 경우.
		else if (node->getLeft() == NULL || node->getRight() == NULL) {
			// 삭제할 노드의 유일한 자식 노드 => child.
			BinaryNode* child = (node->getLeft() != NULL)
				? node->getLeft() : node->getRight();

			// 삭제할 노드가 루트이면 ==> child의 새로운 root가 됨.
			if (node == root) root = child;
			// 아니면 ==> 부모 노드의 자식으로 자식 노드 child를 직접 연결.
			else {
				if (parent->getLeft() == node)
					parent->setLeft(child);
				else
					parent->setRight(child);
			}
		}

		// case3 : 삭제하려는 노드가 두개의 자식이 모두 있는 경우.
		else {
			// 삭제하려는 노드의 오른쪽 서브트리에서 가장 작은 노드를 탐색.
			// succ => 후계 노드 : 오른쪽 서브트리에서 가장 key가 작은 노드.
			// succp => 후계 노드의 부모 노드.
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();
			while (succ->getLeft() != NULL) {	// 후계 노드 탐색.
				succp = succ;				// 후계 노드의 부모 노드.
				succ = succ->getLeft();		// 후계 노드.
			}
			// 후계 노드의 부모와 후계 노드의 오른쪽 자식을 직접 연결.
			if (succp->getLeft() = succ)
				succp->setLeft(succ->getRight());
			else								// 후계 노드가 삭제할 노드의 바로 오른쪽 자식인 경우.
				succp->setRight(succ->getRight());
			// 후계 노드 정보를 삭제할 노드에 복사.
			node->setData(succ->getData());
			// 삭제할 노드를 후계 노드로 변경 : 실제로는 후계 노드가 제거됨.
			node = succ;
		}
		delete node;				//메모리 동적 해제.
	}
};



// 키 값으로 노드를 탐색하는 함수( 순환적인 방법).
BinaryNode* BinaryNode::search(int key) {
	if (key == data)
		return this;
	else if (key < data && left != NULL)		// key < 현재 노드의 data
		return left->search(key);
	else if (key > data&& right != NULL)		// key > 현재 노드의 data.
		return right->search(key);
	else
		return NULL;

}
