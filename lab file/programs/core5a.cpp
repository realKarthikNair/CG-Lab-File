// Translation in 2D
// Part 1: Translation of a point

#include <iostream>

struct Point {
    int x;
    int y;
};

void translatePoint(Point& p, int Tx, int Ty) {
    p.x += Tx;
    p.y += Ty;
}

int main() {
    Point myPoint = {10, 20};
    std::cout << "Original Point: (" << myPoint.x << ", " << myPoint.y << ")\n";
    translatePoint(myPoint, 5, 8);
    std::cout << "Translated Point: (" << myPoint.x << ", " << myPoint.y << ")\n";
    return 0;
}
