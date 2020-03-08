//연습문제 05.
//사각형을 나타내는 클래스 Rectangle을 만들자. 가로(w), 세로(h)를 가지며, 사각형 넓이를 반환하는 area(), 사각형 둘레를 반환하는 perimeter() 메소드를 만들어라

class Rectangle {
private:
	int width;		//가로.
	int height;		//세로.


public:
	Rectangle(int w, int h):width(w),height(h){}

	void area() {
		cout << "area: " << width * height << endl;
	}

	void perimeter() {
		cout << "perimeter: " << 2 * width + 2 * height << endl;
	}

	void Show() {
		cout << "Width: " << width << ", Height: " << height<<endl;
	}
};

int main() {
	Rectangle r1(10,5);

	r1.area();
	r1.perimeter();

	return 0;

}
