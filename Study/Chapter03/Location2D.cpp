#include "Location2D.h"			//위치 클래스 포함.
#include <stack>				//STL의 stack 템플릿 파일 포함.

const int MAZE_SIZE = 6;			//미로 맵 크기 고정.
char map[MAZE_SIZE][MAZE_SIZE] = {		//미로 맵 데이터.
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};

//(r,c)가 갈 수 있는 위치인지를 검사하는 함수.
//(r,c)가 배열안에 있고, 값이 갈 수 있는 위치 '0'이거나 출구 'x'이어야 함.

bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';				//여기가 이해하기 어려웠지만 결국 r,c: 1~5사이면 false 반환. 

}

//미로 탐색 프로그램 주 함수.
void main() {
	stack<Location2D> locStack;			//위치 스택 객체 생성.
	Location2D entry(1, 0);				//입구 객체.
	locStack.push(entry);				//스택에 입구 삽입.

	while (locStack.empty() == false) {			//스택이 비어있지 않는 동안.
		Location2D here = locStack.top();		//스택에 상단 객체 복사.
		locStack.pop();							//스택에 상단 객체 삭제.

		int r = here.row;			
		int c = here.col;
		cout << "(" << r << ", " << c << ")" << endl;			//현재 위치 화면에 출력.
		if (map[r][c] == 'x') {				//출구이면 -> 탐색성공.
			cout << "미로탐색 성공" << endl;
			return ;
		}
		else {								//출구가 아니면.
			map[r][c] = '.';				//현재 위치를 "지나옴"처리.

			//45~48에서  isValidLoc(x,y) -> x,y에 대입 한값이 17번 함수에 의해 false 값이 나오는 경우는  map[r][c] = 1~5 || (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE 이때이다.  map[r][c] 그러므로 0 || x 가 아닌경우에는 조건문이 실행되지 않는다.

			if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c));				
			if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c));
			if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1));
			if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1));
		}
	}
	cout << "미로 탐색 실패" << endl;

}
