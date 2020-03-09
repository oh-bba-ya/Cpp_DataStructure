#pragma once
#include "Student.h"
class Node : public Student {			//Student를 상속하여 구현함.
	Node* link;				//다음 노드를 가리키는 포인터 변수.
public:
	Node(int id = 0, const char* name = (char*)"", const char* dept = (char*)"") : Student(id, name, dept) { link = NULL; }
	~Node(void) {}
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};
