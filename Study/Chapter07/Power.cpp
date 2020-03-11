#include <iostream>
using namespace std;

double power(double x, int n) {
	if (n == 0)							//순환을 멈추는 부분.
		return 1;
	else if ((n % 2) == 0)							// N이 짝수인경우.
		return power(x * x, n / 2);					// 순환을 호출하는 부분.
	else
		return x * power(x * x, (n - 1) / 2);			// N이 홀수인경우. 순환을 호출하는 부분.
		
}

int main() {
	cout << power(3, 9) << endl;
}
