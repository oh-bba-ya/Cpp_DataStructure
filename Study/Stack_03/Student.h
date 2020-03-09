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
	Student(int i=0,string n="", string d=""):id(i),name(n),dept(d){}

	void display() {
		cout << "학번: " << id << ", 이름: " << name << ", 소속학과: " << dept << endl;
	}
};
