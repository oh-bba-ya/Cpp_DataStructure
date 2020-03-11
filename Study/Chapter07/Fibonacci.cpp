#include <iostream>
using namespace std;

/*
 fib() 함수를 이용하면 구현은 쉽지만 굉장히 비효율적이다
 그 이유는 중간에 계산되었던 값을 기억하지 못하여 다시 한번 호출 하게 된다
 EX)
                                    fib(6)
                    fib(4)                          fib(5)
                fib(3) fib(2)                   fib(4)    fib(3)
등처럼 똑같은것을 중복하여 계산하기 때문에 파라미터 안에 들어가는 N의 값이 커질수록 계산은 불가능해진다.
 */

int fib(int n) {			

	if (n == 0) return 0;				// 순환을 멈추는 부분
	if (n == 1) return 1;				// 순환을 멈추는 부분.
	return (fib(n - 1) + fib(n - 2));	// 순환을 호출하는 부분.

}


/*
    반복문을 이용한 피보나치
*/

int fibIter(int n) {
    if (n < 2) return n;
    else {
        int tmp, current = 1, last = 0;
        for (int i = 2; i <= n; i++) {
            tmp = current;
            current += last;
            last = tmp;
        }
        return current;
    }
}

int main() {
	cout << fib(8) << endl;
    cout << fibIter(8) << endl;
}
