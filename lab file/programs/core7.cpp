// Scaling in 2D

#include <graphics.h>
#include <cmath>
#include <iostream>

struct Point {
    int x, y;
};

void drawTriangle(const Point& p1, const Point& p2, const Point& p3) {
    line(p1.x, p1.y, p2.x, p2.y);
    line(p2.x, p2.y, p3.x, p3.y);
    line(p3.x, p3.y, p1.x, p1.y);
}

void scalePoint(Point& p, double sx, double sy) {
    p.x *= sx;
    p.y *= sy;
}

void scaleTriangle(Point& p1, Point& p2, Point& p3, double sx, double sy) {
    scalePoint(p1, sx, sy);
    scalePoint(p2, sx, sy);
    scalePoint(p3, sx, sy);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Point p1 = {100, 100};
    Point p2 = {200, 200};
    Point p3 = {300, 100};

    std::cout << "Original Triangle: \n (" << p1.x << ", " << p1.y << "), (" << p2.x << ", " << p2.y << "), (" << p3.x << ", " << p3.y << ")\n";

    drawTriangle(p1, p2, p3);
    scaleTriangle(p1, p2, p3, 2.0, 2.0);

    std::cout << "Scaled Triangle: \n (" << p1.x << ", " << p1.y << "), (" << p2.x << ", " << p2.y << "), (" << p3.x << ", " << p3.y << ")\n";

    drawTriangle(p1, p2, p3);
    getch();
    closegraph();
    return 0;
}