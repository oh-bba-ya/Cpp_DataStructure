#pragma once
#include <iostream>
using namespace std;

const int MAX_STRING = 100;

class Student {
private:
	int id;							//학번.
	string name;			//이름.
	string dept;			//소속 학과.

public:
	Student(int i=0,string n="", string d=""):id(i),name(n),dept(d){}	//원래 책과 다르게 사용한이유는 char* n = "" 이 오류가 확인이 되서이다.

	void display() {
		cout << "학번: " << id << ", 이름: " << name << ", 소속학과: " << dept << endl;
	}
};

/*
이 오류는 Chapter3에서는 문제가 없지만 Chapter05 Node에서 문제가 생긴다 또 적어 놓겠다.
14라인을 확인 하면 오류가 난다고 했었는데 char* n = ""   -> char* n =(char*) "" 로 바꾸게 되면은 해결이 된다. 
이유는  char *에 문자열 리터럴을 담는 방식은 C 스타일이며, C++에서는 잘못된 코딩방법이기 때문에 라고나와있다.
{출처:http://egloos.zum.com/kim0522ms/v/6438724dl}
*/

