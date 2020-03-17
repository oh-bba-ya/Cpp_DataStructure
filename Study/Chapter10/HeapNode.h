#pragma once
#include <iostream>
#include <cstdio>
using namespace std;

class HeapNode {
	int key;			// key 값.

public:
	HeapNode(int k = 0) :key(k) {}
	void setKey(int k) { key = k; }
	int getKey() { return key; }
	void display() { printf("%4d", key); }
};
