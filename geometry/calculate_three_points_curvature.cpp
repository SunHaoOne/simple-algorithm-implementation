#include <iostream>
using namespace std;

class Vector2D {
public:
	Vector2D(float _x, float _y) {
		x = _x;
		y = _y;
	}
	Vector2D operator - (Vector2D& v) {
		return Vector2D(x - v.x, y - v.y);
	}
	double cross(Vector2D& v) {
		return x * v.y - v.x * y;
	}
	double norm() {
		return sqrt(x * x + y * y);
	}
private:
	double x;
	double y;
};


/*
Point A, B, C
cosB = (a * a + c * c - b * b) / (2 * a * c)
r = 2 * sinB / b
kappa = 1 / r

*/
double threePointCurvature(float a_x, float a_y, float b_x, float b_y, float c_x, float c_y)
{
	double kappa = 0;
	Vector2D A(a_x, a_y);
	Vector2D B(b_x, b_y);
	Vector2D C(c_x, c_y);

	Vector2D AB = A - B;
	Vector2D BC = B - C;
	Vector2D CA = C - A;

	double a = BC.norm();
	double b = CA.norm();
	double c = AB.norm();

	double cosB = (a * a + c * c - b * b) / (2 * a * c);

	kappa = 2 * sin(acos(cosB)) / b;

	return kappa;
}


int main()
{

	double a_x = 0.0;
	double a_y = 4.0;
	double b_x = 0.0;
	double b_y = 0.0;
	double c_x = 3.0;
	double c_y = 0.0;

	cout << threePointCurvature(a_x, a_y, b_x, b_y, c_x, c_y) << endl;

	return 0;
}
