#pragma once
#include <iostream>
using namespace std;

#define MAX_LIST_SIZE 100

class ArrayList {
	int data [MAX_LIST_SIZE];				//실제로 항목 값들이 들어감.
	int length;

public:
	ArrayList(void) { length = 0; }			//생성자 ==> length를 초기화.

	//삽입연산: 리스트의 pos번째에 항목 e 추가.
	void insert(int pos, int e);

	//삭제 연산: pos번째에 항목을 제거.
	void remove(int pos);

	int getEntry(int pos) { return data[pos]; }			//pos번째의 항목을 반환.

	bool isEmpty() { return length == 0; }
	bool isFull() { return length == MAX_LIST_SIZE; }

	bool find(int item) {				//항목의 아이템이 있는지 검사.
		for (int i = 0; i < length; i++) {
			if (data[i] == item)
				return true;
		}
		return false;
	}

	void replace(int pos, int e) {				//pos위치의 요소 변경.
		data[pos] = e;
	}

	int size() { return length; }			//리스트 길이 반환.

	void display() {			// 화면에 보기 좋게 출력.
		printf("[배열로구현한리스트 전체 항목 수 = %2d] : ", size());
		for (int i = 0; i < length; i++) {
			printf("[%2d]", data[i]);
		}
		printf("\n");
	}

	void clear() { length = 0; }				//모든 요소 제거.

};

void ArrayList::insert(int pos, int e) {
	if (!isFull() && pos >= 0 && pos <= length) {
		for (int i = length; i > pos; i--) {
			data[i] = data[i - 1];
		}
		data[pos] = e;
		length++;
	}
	else
		cout << "포화상태 오류 또는 삽입 위치 오류" << endl;
}


void ArrayList::remove(int pos) {
	if (!isEmpty() && pos >= 0 && pos < length) {
		for (int i = pos + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}
	else
		cout << "공백 상태 오류 또는 삭제 위치 오류" << endl;
}




/*
//insert 메소드 나만의 방법을 구현해봄.
void ArrayList::insert(int pos, int e) {
	if (!isFull() && pos >= 0 && pos <= length) {
		for (int i = pos; i <length-1 ; i++) {        // 책과 달리 오히려 시작위치를 pos부터 시작하여 한칸씩 증가시킴.
			data[i+1] = data[i];        //pos위치의 다음부터 값이 pos부터 복사된다.
		}
		data[pos] = e;
		length++;
	}
	else
		cout << "포화상태 오류 또는 삽입 위치 오류" << endl;
}
*/


/*
//remove 메소드를 나만의 방법을 구현해봄.
void ArrayList::insert(int pos, int e) {
	if (!isFull() && pos >= 0 && pos <= length) {
  
  //책과 달리 시작위치를 pos로 설정, length-2를 하게 된이유는 length-1의 값을 복사하기 위해서는 그것보다 한단계 전인 위치에서 끝나야 하기 때문.
		for (int i = pos; i < length-2; i++) {        
			data[i] = data[i + 1];      //pos위치의 값에 한칸 뒤인 데이터가 복사된다.
		}
		data[pos] = e;
		length++;
	}
	else
		cout << "포화상태 오류 또는 삽입 위치 오류" << endl;
}
*/
