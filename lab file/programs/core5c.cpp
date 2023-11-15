// Translation in 2D
// Part 3: Translation of a polygon (triangle)

#include <graphics.h>
#include <iostream>

struct Point {
    int x, y;
};

struct Triangle {
    Point p1, p2, p3;
};

void translateTriangle(Triangle& triangle, int Tx, int Ty) {
    triangle.p1.x += Tx;
    triangle.p1.y += Ty;
    triangle.p2.x += Tx;
    triangle.p2.y += Ty;
    triangle.p3.x += Tx;
    triangle.p3.y += Ty;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    Triangle myTriangle = {{100, 100}, {200, 200}, {300, 100}};
    std::cout << "Original Triangle: (" << myTriangle.p1.x << ", " << myTriangle.p1.y << "), (" << myTriangle.p2.x << ", " << myTriangle.p2.y << "), (" << myTriangle.p3.x << ", " << myTriangle.p3.y << ")\n";
    line(myTriangle.p1.x, myTriangle.p1.y, myTriangle.p2.x, myTriangle.p2.y);
    line(myTriangle.p2.x, myTriangle.p2.y, myTriangle.p3.x, myTriangle.p3.y);
    line(myTriangle.p3.x, myTriangle.p3.y, myTriangle.p1.x, myTriangle.p1.y);
    int Tx = 30, Ty = 40;
    translateTriangle(myTriangle, Tx, Ty);
    std::cout << "Translated Triangle: (" << myTriangle.p1.x << ", " << myTriangle.p1.y << "), (" << myTriangle.p2.x << ", " << myTriangle.p2.y << "), (" << myTriangle.p3.x << ", " << myTriangle.p3.y << ")\n";
    line(myTriangle.p1.x, myTriangle.p1.y, myTriangle.p2.x, myTriangle.p2.y);
    line(myTriangle.p2.x, myTriangle.p2.y, myTriangle.p3.x, myTriangle.p3.y);
    line(myTriangle.p3.x, myTriangle.p3.y, myTriangle.p1.x, myTriangle.p1.y);
    getch();
    closegraph();
    return 0;
}