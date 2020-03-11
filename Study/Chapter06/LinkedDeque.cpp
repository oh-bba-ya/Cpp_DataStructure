#include "LinkedDeque.h"

//LinkeDeque.cpp
void main() {
	LinkedDeque deq;
	for (int i = 1; i < 10; i++) {
		if (i % 2) deq.addFront(new Node2(i));		// 홀수.
		else deq.addRear(new Node2(i));				// 짝수.
	}

	deq.display();
	delete deq.deleteFront();
	delete deq.deleteRear();
	delete deq.deleteFront();
	deq.display();

}
