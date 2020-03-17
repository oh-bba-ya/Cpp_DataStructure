#include "Maxheap.h"

// 우선 순위 큐인 힙을 이용한 정렬.
void heapSort(int a[], int n) {
	MaxHeap h;
	for (int i = 0; i < n; i++) {
		h.insert(a[i]);
	}
	// 최대 힙에서는 삭제시 가장 큰 값이 반환되므로.
	// 오름차순으로 정렬하기 위한 삭제한 항목을 배열의 끝부터 앞으로 채워나감.
	for (int i = n - 1; i >= 0; i--)
		a[i] = h.remove().getKey();
}

void main() {
	MaxHeap heap;
	int data[10];

	// 랜덤으로 데이터 생성.
	for (int i = 0; i < 10 ; i++) data[i] = rand() % 100;
	// 정렬전 결과 출력.
	printf("\n정렬전");
	for (int i = 0; i < 10; i++) printf("%3d", data[i]);
	// 힙 정렬.
	heapSort(data, 10);
	// 정렬 후 결과 출력.
	printf("\n정렬후: ");
	for (int i = 0; i < 10; i++) printf("%3d", data[i]);
	printf("\n");
}

