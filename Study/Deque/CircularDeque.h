#pragma once
#include "CircularQueue.h"

class CircularDeque : public CircularQueue {
public:
	CircularDeque() {}

	void addRear(int val) { enqueue(val); }			//enqueue() 호출.

	int deleteFront() { return dequeue(); }			//dequeue() 호출.

	int getFront() { return peek(); }				//peek() 호출.

	void addFront(int val) {				//전단에 삽입.
		if (isFull()) {
			cout << "덱이 포화상태입니다" << endl;
			exit(1);
		}
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}

	int deleteRear() {			//후단에서 삭제.
		if (isEmpty()) {
			cout << "덱이 공백 상태입니다." << endl;
			exit(1);
		}
		else {
			int ret = data[rear];
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}

	int getRear() {					//후단에서 peek
		if (isEmpty()) {
			cout << "덱이 공백 상태입니다." << endl;
			exit(1);
		}
		else {
			return data[rear];
		}
	}


	void display() {			//CircularQueue::display()를 재정의.
		cout << "덱의 내용: " << endl;		//이출력 코드만 다름.
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;

		for (int i = front + 1; i <= maxi; i++) {
			cout << data[i % MAX_QUEUE_SIZE] << endl;
		}
	}
};
