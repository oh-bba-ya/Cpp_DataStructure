#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define MAX_STRING 100
using namespace std;



class Student {
	int id;							//학번.
	char name[MAX_STRING];			//이름.
	char dept[MAX_STRING];			//소속 학과.

public:
	Student(int i = 0,const char* n = (char*)"",const char* d = (char*)"") { set(i, n, d); }		//Chapter03과 달리 const추가.

	void set(int i,const char* n,const char* d) {				//chapter03과 달리 const 추가 책대로 하면 오류.
		id = i;
		strcpy_s(name, n);			//문자열 복사 함수.
		strcpy_s(dept, d);
	}

	void display() {
		cout << "학번: " << id << ", 이름: " << name << ", 소속학과: " << dept << endl;
	}
};


/*
이 오류는 Chapter3에서는 문제가 없지만 Chapter05 Node에서 문제가 생긴다 또 적어 놓겠다.
17라인을 확인 하면 오류가 난다고 했었는데 char* n = ""   -> char* n =(char*) "" 로 바꾸게 되면은 해결이 된다. 
이유는  char *에 문자열 리터럴을 담는 방식은 C 스타일이며, C++에서는 잘못된 코딩방법이기 때문에 라고나와있다.
{출처:http://egloos.zum.com/kim0522ms/v/6438724dl}
*/

/*
Node.h 파일 6번 라인에서 오류가 날텐데 그 이유는 17라인이랑 같다 그렇기에 const를 추가했다.
{출처:https://blog.naver.com/PostView.nhn?blogId=helicopter55&logNo=221519318260}
*/

