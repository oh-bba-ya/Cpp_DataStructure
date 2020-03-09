#pragma once
#include <iostream>
using namespace std;

class Customer {
public:
	int id;			//고객번호.
	int tArrival;		//고객이 도착한 시간.
	int tService;		//이 고객이 서비스에 필요한 시간.
public:
	Customer(int i = 0, int tArr = 0, int tServ = 0) :id(i), tArrival(tArr), tService(tServ) {}


};

