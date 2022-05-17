#include <iostream>;
using namespace std;
class Vector {
public:
	// position: (x, y) --> (v.x, v.y)
	float x;
	float y;
	Vector(float _x, float _y) {
		x = _x;
		y = _y;
	}

	Vector operator - (Vector& v) {
		return Vector(x - v.x, y - v.y);
	}

	float cross(Vector& v) {
		return x * v.y - y * v.x;
	}
};

bool SameSide(Vector A, Vector B, Vector C, Vector P) {
	Vector AB = B - A;
	Vector AC = C - A;
	Vector AP = P - A;

	float v1 = AB.cross(AC);
	float v2 = AB.cross(AP);

	return v1 * v2 >= 0;
}

bool PointinTriangle1(Vector A, Vector B, Vector C, Vector P)
{
	return SameSide(A, B, C, P) &&
		SameSide(B, C, A, P) &&
		SameSide(C, A, B, P);
}

int main() {
// input:
// n
// ax, ay
// bx, by
// cx, cy
// px, py

// output: yes/no
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	int n = 0;
	float ax, ay, bx, by, px, py;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ax >> ay;
		cin >> bx >> by;
		cin >> cx >> cy;
		cin >> px >> py;
		Vector A(ax, ay);
		Vector B(bx, by);
		Vector C(cx, cy);
		Vector P(px, py);
		bool res = PointinTriangle1(A, B, C, P);

		if (res) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		};
	}

}

