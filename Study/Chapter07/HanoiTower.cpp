#include <iostream>
using namespace std;

//머리 순환 사용.
void hanoiTower(int n, char from, char tmp, char to) {
	if (n == 1)														//순환을 멈추는 부분.
		printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
	else {
		hanoiTower(n - 1, from, to, tmp);							// 순환 호출 부분.
		printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
		hanoiTower(n - 1, tmp, from, to);							// 순환 호출 부분.
	}
}

void main() {
	hanoiTower(4, 'A', 'B', 'C');
}
