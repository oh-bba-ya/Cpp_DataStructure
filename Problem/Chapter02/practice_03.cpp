//연습문제03
//크기가 10인 배열 twop[]를 선언하고 여기에 2의 제곱 값들을 저장하고 출력해보자.(for 루프 이용)
int main() {

	int two[10];

	for (int i = 0; i < 10; i++) {
		two[i] = pow(2, i);
	}

	for (int j = 0; j < 10; j++) {
		cout << two[j] << endl;
	}

	return 0;
}
