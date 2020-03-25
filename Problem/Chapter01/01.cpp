//문제 1
// sum = n(n+1)/2 공식을 사용하여 int sumAlgorithmA를 구현하라.

#include <iostream>
using namespace std;

int sumAlgorithmA(int n);

void main() {
	int num;
	cout << "숫자를 입력해주세요: ";
	cin >> num;

	cout << "결과 : ";
	cout << sumAlgorithmA(10) << endl;



}

int sumAlgorithmA(int n) {
	int result;
	result = n*(n + 1) / 2;
	return result;
}
