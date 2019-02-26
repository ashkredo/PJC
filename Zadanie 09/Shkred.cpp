/**
*
*  @author Shkred Artur S15444
*
*/

#include <iostream>

using namespace std;

//---------------------------------------------------------//
class Segment {
	double A, B;
public:
	Segment(double A, double B) : A(A), B(B) { }

	friend ostream& operator<<(ostream& str, const Segment&);
	friend const Segment operator-(const Segment&, int);
	friend const Segment operator/(const Segment&, int);
	friend const Segment operator+(const Segment&, const Segment&);
	friend const Segment operator*(int, const Segment&);
	friend const Segment operator+(int, const Segment&);

	bool operator()(double d) {
		if (d >= A && d <= B) {
			return true;
		} else {
			return false;
		}
	}
};

ostream& operator<<(ostream& str, const Segment& s) {
	return str << "[" << s.A << "," << s.B << "]";
}

const Segment operator-(const Segment& s, int d) {
	return Segment(s.A - d, s.B - d);
}

const Segment operator/(const Segment& s, int d) {
	if (s.A <= 0 && s.B > 0) {
		return Segment((s.A / (1 / d)), (s.B / (1 / d)));
	}
	return Segment((int)(s.A / d), (int)(s.B / d));
}

const Segment operator+(const Segment& s, const Segment& s2) {
	if ((s.B - s.A) < (s2.B - s2.A)) {
		return Segment(s.A, s.B);
	} else { 
		return Segment(s2.A, s2.B);
	}
}

const Segment operator*(int d, const Segment& s) {
	return Segment(s.A * d, s.B * d);
}

const Segment operator+(int d, const Segment& s) {
	return Segment(s.A, s.B + d);
}
//---------------------------------------------------------//

//........................Zadanie_09.......................// 
int main() {
	using std::cout; using std::endl;
	Segment seg{ 2,3 }, s = 1 + 2 * ((seg - 2) / 2 + seg) / 3;
	cout << s << endl << std::boolalpha;
	for (double x = 0.5; x < 4; x += 1)
		cout << "x=" << x << ": " << s(x) << endl;

	system("pause");
	return 0; }
//---------------------------------------------------------//