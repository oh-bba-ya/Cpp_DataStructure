#include "LinkedStack.h"

void main() {
	LinkedStack stack;
	/*
		8번라인에서 
		C++ 인수 목록이 일치하는 생성자의 인스턴스가 없습니다.
		인수 형식이 (int, const char [7], const char [14])입니다.
		라고 하는 오류가 있을것이다 Node.h 파일에서 생성자에 const를 입력하지 않는다면 오류가난다.
		(리터럴: 변수에 넣는 변하지 않는 데이터를 의미하는것이다.)
		출처:https://hashcode.co.kr/questions/6267/c-생성자-관련-질문
	*/
	stack.push(new Node(2015130007, "홍길동", "컴퓨터 공학과"));
	stack.push(new Node(2015130100, "이순신", "기계공학과"));
	stack.push(new Node(2015130135, "황희", "법학과"));
	stack.display();

	Node* node = stack.pop();
	printf("[Pop항목]\n");
	node->display();
	printf("\n");
	delete node;
	stack.display();
}
