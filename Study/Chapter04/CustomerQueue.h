#pragma once
#pragma once
#include <iostream>
#include <cstdlib>
#include "Customer.h"
using namespace std;


const int MAX_QUEUE_SIZE = 100;

class CustomerQueue {
protected:
	int front;					//첫번째 요소 앞의 위치.
	int rear;					//마지막 요소 위치.
	Customer data[MAX_QUEUE_SIZE];	//요소의 배열.

public:
	CustomerQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue(Customer val) {			//큐에 삽입.
		if (isFull()) {
			cout << "큐가 포화 상태입니다." << endl;
			exit(1);
		}
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	Customer dequeue() {			//첫 항목을 큐에서 빼서 반환.
		if (isEmpty()) {
			cout << "큐가 공백 상태입니다." << endl;
			exit(1);
		}
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}

	Customer peek() {				//첫 항목을 큐에서 뺴지 앟고 반환.
		if (isEmpty()) {
			cout << "큐가 공백 상태입니다." << endl;
			exit(1);
		}
		else {
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}

	

};
