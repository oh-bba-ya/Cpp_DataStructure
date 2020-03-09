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
	Student(int i = 0,const char* n = (char*)"",const char* d = (char*)"") { set(i, n, d); }

	void set(int i,const char* n,const char* d) {
		id = i;
		strcpy_s(name, n);			//문자열 복사 함수.
		strcpy_s(dept, d);
	}

	void display() {
		cout << "학번: " << id << ", 이름: " << name << ", 소속학과: " << dept << endl;
	}
};
