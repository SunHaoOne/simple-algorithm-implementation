#include<iostream>
#include<vector>
using namespace std;

/*
y = w * x + b
J(w, b) = (y - w * x - b)^2
dw = 2(y - w * x + b) * -x
db = 2(y = w * x + b * -1

Steps:

1. error = y - w * x - b
2. dw = -x* error, db = -error
3. w = w - dw, b = b - db
*/

void gradientDescend(vector<int>& x, vector<int>& y) {
	double w = 0, b = 0, dw = 0, db = 0, error = 0;
	double lr = 0.01;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < x.size(); j++) {
			error = y[j] - w * x[j] - b;
			dw = -x[j] * error;
			db = -error;
			w = w - lr * dw;
			b = b - lr * db;
		}
		if (i%100==0) cout << "ERROR:" << error << endl;
	}
	cout << "w = " << w << "b = " << b << endl;
}


int main() {
	vector<int> y = { 1,2,3,4,5,6,7,8,9,9 };
	vector<int> x = { 1,2,3,3,5,6,6,8,9,9 };

	gradientDescend(x, y);

}
