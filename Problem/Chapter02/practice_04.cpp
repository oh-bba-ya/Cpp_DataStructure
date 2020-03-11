//연습문제04.
//복소수를 나타내는 클래스를 만들어보자.

class Complex {
private:
	int real;		//실수.
	int image;		//허수.

public:
	Complex(int r, int i) : real(r),image(i){}

	Complex operator+(const Complex& c2) {
		Complex result(real + c2.real, image + c2.image);
		return result;
	}

	Complex operator-(const Complex& c2) {
		Complex result(real - c2.real, image - c2.image);
		return result;
	}

	Complex operator*(const Complex& c2) {
		Complex result(real * c2.real, image * c2.image);
		return result;
	}

	Complex operator/(const Complex& c2) {
		Complex result(real / c2.real, image / c2.image);
		return result;
	}


	void ShowComplex() {
		cout << "real: " << real << ", image: " << image << endl;
	}

	friend ostream& operator<<(ostream& os, const Complex&);

};


ostream& operator<<(ostream& os, const Complex& c) {
	os << "real: " << c.real << ", image: " << c.image<< endl;
	return os;
}

int main() {
	Complex c1(10, 4);
	Complex c2(5, 2);
	

	cout << "c1: ";
	c1.ShowComplex();
	cout << "c2: ";
	c2.ShowComplex();
	cout << "Complex Add(+): "<<c1 + c2 << endl;
	cout << " Complex Subtract(-): " << c1 - c2 << endl;
	cout << " Complex multiply(*): " << c1 * c2 << endl;
	cout << " Complex Division(/): " << c1 / c2 << endl;

	return 0;
}
