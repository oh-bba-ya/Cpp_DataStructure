#pragma once
#include "BinaryNode.h"
#include "CircularQueue.h"


class BinaryTree {
public:
	BinaryNode* root;

public:
	BinaryTree() :root(NULL) {}
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	//이진트리의 순회 연산.
	void inorder() { printf("\n  inorder: ");  inorder(root); }
	void inorder(BinaryNode* node) {			//순환적인 트리의 순회 함수.
		if (node != NULL) {
			inorder(node->getLeft());
			printf(" [%c] ", node->getData());
			inorder(node->getRight());
		}
	}

	// 이진트리의 preorder 순회 연산.
	void preorder() { printf("\n  preorder: "); preorder(root); }
	void preorder(BinaryNode* node) {
		if (node != NULL) {
			printf(" [%c] ", node->getData());
			preorder(node->getLeft());
			preorder(node->getRight());
		}
	}

	//이진트리의 postorder 순회 연산.
	void postorder() { printf("\n postorder: "); postorder(root); }
	void postorder(BinaryNode* node) {
		if (node != NULL) {
			postorder(node->getLeft());
			postorder(node->getRight());
			printf(" [%c] ", node->getData());
		}
	}

	// 이진트리의 레벨 순회 연산.
	void levelorder() {
		printf("\nlevelorder: ");
		if (!isEmpty()) {
			CircularQueue q;
			q.enqueue(root);
			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();
				if (n != NULL) {
					printf(" [%c] ", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
		printf("\n");
	}

	// 이진트리의 추가 연산.

	// 트리의 노드 개수를 구하는 함수.
	int getCount() { return isEmpty() ? 0 : getCount(root); }
	// 순환 호출에 의해 node를 루트로 하는 서브트리의 노드 수 계산 함수.
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft())
			+ getCount(node->getRight());
	}


	// 트리의 높이를 구하는 함수.
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }

	// 순환 호출에 의해 node를 루트로 하는 서브트리의 높이 계산 함수.
	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}

	// 트리의 단말 노드 개수를 구하는 함수.
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }

	// 순환 호출에 의해 node를 루트로 하는 서브트리의 단말 노드 수 계산 함수.
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0;
		if (node->isLeaf()) return 1;
		else return getLeafCount(node->getLeft())
			+ getLeafCount(node->getRight());
	}
};
