#include <iostream>
#include <ctime>
using namespace std;

//문제02
// 비교적 작은 n에 대해 각 함수를 호출하여 세 알고리즘의 계산 결과가 동일함을 확인하라.


int sumAlgorithmA(int n) {
	int result;
	result = n * (n + 1) / 2;
	return result;
}

int sumAlgorithmB(int n) {
	int result=0;
	for (int i = 1; i <= n; i++) {
		result += i;
	}
	return result;
}

int sumAlgorithmC(int n) {
	int result = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			result += 1;
		}
	}
	return result;
}


void main() {
	int num,A(0),B,C;
	int total_sum1 = 0;
	int total_sum2 = 0;
	int total_sum3 = 0;
	clock_t start, finish;
	double duration;

	cout << " 숫자를 입력하세요: ";
	cin >> num;

	cout << endl;

	
	
	start = clock();
	sumAlgorithmA(num);
	finish = clock();
	cout << "알고리즘 A의 결과: " << sumAlgorithmA(num) << endl;
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "알고리즘 A의 시간측정(sec) : " << duration <<"s" << endl;

	start = clock();
	sumAlgorithmB(num);
	finish = clock();
	cout << "알고리즘 B의 결과: " << sumAlgorithmB(num) << endl;
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "알고리즘 B의 시간측정(sec) : " << duration<<"s" << endl;

	start = clock();
	sumAlgorithmB(num);
	finish = clock();
	cout << "알고리즘 C의 결과: " << sumAlgorithmC(num) << endl;
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "알고리즘 C의 시간측정(sec) : " << duration << "s" << endl;


}
