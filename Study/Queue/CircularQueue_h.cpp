#pragma once
#include <iostream>
using namespace std;


const int MAX_QUEUE_SIZE = 100;

class CircularQueue {
protected:
	int front;					//첫번째 요소 앞의 위치.
	int rear;					//마지막 요소 위치.
	int data[MAX_QUEUE_SIZE];	//요소의 배열.

public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue(int val) {			//큐에 삽입.
		if (isFull()) {
			cout << "큐가 포화 상태입니다." << endl;
			exit(1);
		}
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	int dequeue() {			//첫 항목을 큐에서 빼서 반환.
		if (isEmpty()) {
			cout << "큐가 공백 상태입니다." << endl;
			exit(1);
		}
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}

	int peek() {				//첫 항목을 큐에서 뺴지 앟고 반환.
		if (isEmpty()) {
			cout << "큐가 공백 상태입니다." << endl;
			exit(1);
		}
		else {
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}

	void display() {			//큐의 모든 내용을 순서대로 출력.
		cout << "큐 내용: " << endl;
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i <= maxi; i++) {
			cout << data[i % MAX_QUEUE_SIZE] << endl;
		}
	}

};
