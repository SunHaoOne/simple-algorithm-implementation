#include <iostream>
#include <vector>
#include <utility>

using namespace std;


// 求点到曲线的最短距离，用牛顿迭代法，曲线方程也可以使用参数的方法
/*
x1 = x0 - f(x0) / f'(x0)
y - f(x0) = f'(x0) (x - x0)，令y = 0
*/

/*
如果是参数方程，需要按照参数方程求导的方式来处理
x = f(t)
y = h(t)

dy/dx = dy/dt / dx/dt = h'(t) / x'(t)
d(dy/dx)/dx =...

*/
double f(double x) {
    return x * x;
}

double df(double x) {
    return 2 * x;
}

double ddf(double x) {
    return 2;
}

double g(double x, double xp, double yp) {
    return x - xp + (f(x) - yp) * df(x);
}

double dg(double x, double xp, double yp) {
    return 1 + (f(x) - yp) * ddf(x) + df(x) * df(x);
}


double newton(double x, double xp, double yp) {
    while (true) {
        if (abs(g(x, xp, yp)) < 1e-6) return x;
        x = x - g(x, xp, yp) / dg(x, xp, yp);
    }
    return -1;
}

double distance(double x, double xp, double yp) {
    // x为迭代的起始点
    double x_target = newton(x, xp, yp);
    double y_target = f(x_target);
    return sqrt(pow(x_target - xp, 2) + pow(y_target - yp, 2));
}


/*
给定的定点坐标为P(xp,yp)，曲线上的点坐标为(x, y)
目标函数 g(x) = (x - xp)^2 + (y - yp)^2
目标函数的梯度 dg = 2(x - xp) + 2(y - yp)* df(x) 
因此也就是找梯度为0的点，作为一个可能的候选点

令 
h(x) = x - xp + (y - yp) * df(x) 求解该函数的零点，考虑用牛顿法
dh(x) = 1 + (y - yp) * ddf(x) + df(x) * df(x)
其更新公式为 x -> x - h(x) / dh(x)

*/


int main()
{

    cout << distance(10, 0, 1) << endl;

}
