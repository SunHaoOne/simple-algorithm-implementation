#include <iostream>;
using namespace std;
class Vector2D{
public:
    Vector2D(float x, float y) {
        mx = x;
        my = y;
    }
    Vector2D operator - (Vector2D v) {
        return Vector2D(mx - v.mx, my - v.my);
    }
    float cross(Vector2D v) {
        return mx * v.my - v.mx * my;
    }

private:
    float mx;
    float my;
};


bool isInTriangle(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Px, float Py) {
    Vector2D A = Vector2D(Ax, Ay);
    Vector2D B = Vector2D(Bx, By);
    Vector2D C = Vector2D(Cx, Cy);
    Vector2D P = Vector2D(Px, Py);
    Vector2D PA = A - P;
    Vector2D PB = B - P;
    Vector2D PC = C - P;
    float t1 = PA.cross(PB);
    float t2 = PB.cross(PC);
    float t3 = PC.cross(PA);

    return t1 * t2 >= 0 && t1 * t3 >= 0;

}



int main() {
    bool res = isInTriangle(0, 0, 0, 3, 4, 0, 2, 2);
    cout << res << endl;
}