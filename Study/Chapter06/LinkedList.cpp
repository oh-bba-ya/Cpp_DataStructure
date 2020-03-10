#include "LinkedList.h"

void main() {
	LinkedList list;				//리스트 객체 생성.
	list.insert(0, new Node(10));			//리스트 맨 앞에 10 삽입.
	list.insert(0, new Node(20));			//리스트 맨 앞에 20 삽입.
	list.insert(1, new Node(30));			//리스트 1위치에 30 삽입.
	list.insert(list.size(), new Node(40));			//리스트 마지막에 40 삽입.
	list.insert(2, new Node(50));			//리스트 2위치에 50 삽입.
	list.display();
	list.remove(2);				//리스트 2위치의 항목 삭제.
	list.remove(list.size() - 1);		//리스트 마지막 항목 삭제.
	list.remove(0);
	list.replace(1, new Node(90));		//리스트 1위치 항목 값 변경(대체).
	list.display();
	list.clear();					//리스트 내 항목 모두 삭제.
	list.display();


	//리스트 20을 0번째에 삽입 함으로서 10 사라질줄 알아겠지만 그렇지 않고 뒤로 한칸씩 밀리게된다. 그렇기에 10의 위치가 index=4 에  존재한다.
	
}
