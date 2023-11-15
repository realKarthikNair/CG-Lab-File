// Rotation in 2D

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

void rotatePoint(Point& p, double angle) {
    double const PI = 3.14159265358979323;
    double radians = angle * (PI / 180.0);
    double x = p.x;
    double y = p.y;
    
    p.x = x * cos(radians) - y * sin(radians);
    p.y = x * sin(radians) + y * cos(radians);
}

void rotateTriangle(Point& p1, Point& p2, Point& p3, double angle) {
    rotatePoint(p1, angle);
    rotatePoint(p2, angle);
    rotatePoint(p3, angle);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Point p1 = {100, 100};
    Point p2 = {200, 200};
    Point p3 = {300, 100};

    std::cout << "Original Triangle: \n (" << p1.x << ", " << p1.y << "), (" << p2.x << ", " << p2.y << "), (" << p3.x << ", " << p3.y << ")\n";

    drawTriangle(p1, p2, p3);
    rotateTriangle(p1, p2, p3, 45.0);

    std::cout << "Rotated Triangle: \n (" << p1.x << ", " << p1.y << "), (" << p2.x << ", " << p2.y << "), (" << p3.x << ", " << p3.y << ")\n";

    drawTriangle(p1, p2, p3);
    getch();
    closegraph();
    return 0;
}

