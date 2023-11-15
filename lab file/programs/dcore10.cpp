// Cohen Sutherland's Algorithm

#include <graphics.h>
#include <iostream>

const int INSIDE = 0;  // 0000
const int LEFT = 1;    // 0001
const int RIGHT = 2;   // 0010
const int BOTTOM = 4;  // 0100
const int TOP = 8;     // 1000

const int xmin = 50, ymin = 50, xmax = 300, ymax = 200; // the region to be clipped against

struct Point {
    int x, y;
};

int computeCode(const Point& p) {
    int code = INSIDE;

    if (p.x < xmin)
        code |= LEFT;
    else if (p.x > xmax)
        code |= RIGHT;

    if (p.y < ymin)
        code |= BOTTOM;
    else if (p.y > ymax)
        code |= TOP;

    return code;
}

void cohenSutherland(Point& p1, Point& p2) {
    int code1 = computeCode(p1);
    int code2 = computeCode(p2);
    bool accept = false;

    printf("Initial coordinates: P1(%d, %d), P2(%d, %d)\n", p1.x, p1.y, p2.x, p2.y);

    while (true) {
        if (!(code1 | code2)) { // both inside
            accept = true;
            break; 
        } else if (code1 & code2) { // both outside
            break;
        } else {
            int codeOut = code1 ? code1 : code2; 

            Point newPoint;
            if (codeOut & TOP) {
                newPoint.x = p1.x + (p2.x - p1.x) * (ymax - p1.y) / (p2.y - p1.y);
                newPoint.y = ymax;
            } else if (codeOut & BOTTOM) {
                newPoint.x = p1.x + (p2.x - p1.x) * (ymin - p1.y) / (p2.y - p1.y);
                newPoint.y = ymin;
            } else if (codeOut & RIGHT) {
                newPoint.y = p1.y + (p2.y - p1.y) * (xmax - p1.x) / (p2.x - p1.x);
                newPoint.x = xmax;
            } else if (codeOut & LEFT) {
                newPoint.y = p1.y + (p2.y - p1.y) * (xmin - p1.x) / (p2.x - p1.x);
                newPoint.x = xmin;
            }

            if (codeOut == code1) {
                printf("Clipping P1 to (%d, %d)\n", newPoint.x, newPoint.y);
                p1 = newPoint;
                code1 = computeCode(p1);
            } else {
                printf("Clipping P2 to (%d, %d)\n", newPoint.x, newPoint.y);
                p2 = newPoint;
                code2 = computeCode(p2);
            }
        }
    }

      if (accept) {
        printf("Final coordinates after clipping: P1(%d, %d), P2(%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
        line(p1.x, p1.y, p2.x, p2.y);
    } else {
        printf("Line rejected. Both endpoints are outside the clip window.\n");
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    Point p1 = {10, 150};
    Point p2 = {400, 10};
    // rectangle(xmin, ymin, xmax, ymax);
    // line(p1.x, p1.y, p2.x, p2.y);
    cohenSutherland(p1, p2);
    getch();
    closegraph();
    return 0;
}
