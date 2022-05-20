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

	float dot(Vector& v) {
		return x * v.x + y * v.y;
	}
};

int PointRelations(Vector A, Vector B, Vector P) {
	Vector AB = B - A;
	Vector AP = P - A;

	float v1 = AB.dot(AP);
	float v2 = AB.dot(AB);
	if (v1 < 0) return 0;
	else {
		if (v1 < v2) return 1;
		else return 2;
	}
	return -1;

}



int main() {
// input:
// n
// ax, ay
// bx, by
// px, py

// output: left/right/middle
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
		int res = PointRelations(A, B, P);

		if (res == 0) {
			cout << "left" << endl;
		}
		else if (res == 1) {
			cout << "middle" << endl;
		}
		else if (res == 2) {
			cout << "right" << endl;
		}
		else {
			cout << "Value Error: Please check the dimension of input parameters." << endl;
		}
	}
}

