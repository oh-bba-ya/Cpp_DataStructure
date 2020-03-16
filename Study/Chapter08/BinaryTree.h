#pragma once
#include "BinaryNode.h"


class BinaryTree {
	BinaryNode* root;

public:
	BinaryTree():root(NULL){}
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
	void levelorder();

	// 이진트리의 추가 연산.
	int getCount();
	int getHeight();
	int getLeafCount();
};
