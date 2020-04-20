Chapter03 Problem
================

#### 01. 순서가 A,B,C,D로 정해진 입력 자료를 스택에 입력하였다가 출력할 때, 가능한 출력 순서의 결과가 아닌것은?   (1)
(1) D,A,B,C            (2) A,B,C,D         (3) A,B,D,C       (4) B,C,D,A   
   
임의로 stack s 생성   
Sol)   
(2) s.Push(A) , s.Pop(),  s.Push(B) , s.Pop() , s.Push(C) , s.Pop() , s.Push(D) , s.Pop()  -> 출력결과 : A ,B ,C ,D   
(3)  s.Push(A) , s.Pop(),  s.Push(B) , s.Pop() , s.Push(C), s.Push(D) , s.Pop(),  s.Pop() -> 출력결과 : A ,B , D, C   
(4) s.Push(A),  s.Push(B) , s.Pop() , s.Push(C) , s.Pop() , s.Push(D) , s.Pop(),  s.Pop() -> 출력결과 : B ,C ,D ,A   

#### 02. Stack의 응용 분야로 거리가 먼 것은? (3)    
(1) 미로 찾기     (2) 수식 계산 및 수식 표기법   (3) 운영체제의 작업 스케줄링      (4) 서브루틴의 복귀번지 저장   
   
#### 03. Stack에 대한 설명으로 틀린 것은? (2)   
(1) 입출력이 한쪽 끝으로만 제한된 리스트이다.   (2) head(front) 와 tail(rear)의 2개 포인터를 갖고 있다.       (3) LIFO 구조이다.       (4) 배열로도 구현이 가능하다.   
   
#### 04. Stack의 자료 삭제 알고리즘이다. ( ) 안 내용으로 가장 적합한 것은? (단, Top: 스택 포인터, S: 스택의 이름)  (3)   
(1) Overflow         (2) Top = Top +1        (3) Underflow           (4) Top = Top-2


    

