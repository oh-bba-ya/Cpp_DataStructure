#pragma once
#include <iostream>
#include <cstdio>
using namespace std;

class BinaryNode {
protected:
	int data;				//트리에 저장할 데이터.
	BinaryNode* left;		// 왼쪽 자식 노드의 포인터.
	BinaryNode* right;		// 오른쪽 자식 노드의 포인터.
public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL) :
		data(val), left(l), right(r) {}
	void setData(char val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	char getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return left == NULL && right == NULL; }
	BinaryNode* search(int key);
};



