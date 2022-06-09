class Vector2d():
    def __init__(self, x = 0, y = 0):
        self.x = x;
        self.y = y;
    def cross(self, vector):
        return self.x * vector.y - vector.x * self.y;
    def minus(self, vector):
        res = Vector2d();
        res.x = self.x - vector.x;
        res.y = self.y - vector.y;
        return res;


class Triangle():
    def __init__(self, A, B, C):
        self.A = Vector2d(A[0], A[1]);
        self.B = Vector2d(B[0], B[1]);
        self.C = Vector2d(C[0], C[1]);

    def isIntriangle(self, P):
        PA = self.A.minus(P);
        PB = self.B.minus(P);
        PC = self.C.minus(P);

        t1 = PA.cross(PB);
        t2 = PB.cross(PC);
        t3 = PC.cross(PA);

        return t1 * t2 >= 0 and t1 * t3 >= 0;


def main():
    A = [0, 0];
    B = [0, 3];
    C = [4, 0];

    t = Triangle(A, B, C)
    p = Vector2d();

    p.x = 2;
    p.y = 2;

    print(t.isIntriangle(p))

    p.x = 1;
    p.y = 1;

    print(t.isIntriangle(p))


main()