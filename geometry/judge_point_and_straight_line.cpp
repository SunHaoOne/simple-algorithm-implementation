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

bool SameSide(Vector A, Vector B, Vector P) {
	Vector AB = B - A;
	Vector AP = P - A;


	float v1 = AB.cross(AP);

	return v1 > 0;
}



int main() {
	// input:
	// n
	// ax, ay
	// bx, by
	// px, py

	// output: left/right
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	int n = 0;
	float ax, ay, bx, by, px, py;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ax >> ay;
		cin >> bx >> by;
		cin >> px >> py;
		Vector A(ax, ay);
		Vector B(bx, by);
		Vector P(px, py);
		bool res = SameSide(A, B, P);

		if (res) {
			cout << "left" << endl;
		}
		else {
			cout << "right" << endl;
		};
	}

}

