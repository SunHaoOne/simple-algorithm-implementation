#include <iostream>
#include <math.h>
using namespace std;

double f(double x) {
    return pow(x,5) + x + sin(x) - 1;
}

double df(double x) {
    return 5 * pow(x, 4) + 1 + cos(x);
}

double solution() {
    double left = 0.0;
    double right = 1.0;
    while (true) {
        double mid = left + (right - left) / 2.0;
        if (abs(f(mid)) < 0.00001) return mid;
        else if (f(mid) > 0.0) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

double solution2() {
    // gradient descent
    double lr = 0.01;
    double x = 1;
    int max_step = 1000;
    int step = 0;
    while (step < max_step) {
        // cout << "x = " << x << ", f(x) = " << f(x) << endl;
        if (abs(f(x)) < 0.01) return x;
        x = x - lr * df(x);
        step += 1;
    }
    return -1;
}

double solution3() {
    // newton  y = f(x0) + df(x0)(x - x0) then y = 0, x = x0 - f(x0)/df(x0);
    double x = 1;
    while (true) {
        if (abs(f(x)) < 1e-6) return x;
        x = x - f(x) / df(x);
    }
    return -1;
}
int main() {
    // x^5 + x + sin(x) = 1
    // 单调递增的函数，f =  x^5 + x + sin(x) - 1， f(0) = -1, f(1) > 0;

    cout << solution() << endl;
    cout << solution2() << endl;
    cout << solution3() << endl;
}
