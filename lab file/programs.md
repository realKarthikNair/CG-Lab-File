### 1.  Drawing objects like circle, rectangle, polygon etc using graphic function 
```c
// Part 1 - circle 

# include <graphics.h>
// # include <ncurses.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    circle(400, 250, 100);
    getch();
    closegraph();
}
```

### 2.  Drawing objects like circle, rectangle, polygon etc using graphic function 
```c
// Part 2 - rectangle

# include <graphics.h>
// # include <ncurses.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    rectangle(100, 100, 300, 200);
    getch();
    closegraph();
}
```

### 3.  Drawing objects like circle, rectangle, polygon etc using graphic function 
```c
// Part 3 - polygon

# include <graphics.h>
// # include <ncurses.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    line(100, 100, 200, 0);
    line(200, 0, 300, 100);
    line(100, 100, 300, 100);
    line(100, 100, 100, 300);
    line(100, 300, 300, 300);
    line(300, 100, 300, 300);
    getch();
    closegraph();
}
```

### 4.  Drawing objects like circle, rectangle, polygon etc using graphic function 
```c
// Part 4 - hut with circle inside 

# include <graphics.h>
// # include <ncurses.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    line(100, 100, 200, 0);
    line(200, 0, 300, 100);
    line(100, 100, 300, 100);
    line(100, 100, 100, 300);
    line(100, 300, 300, 300);
    line(300, 100, 300, 300);
    circle(200, 200, 50);
    getch();
    closegraph();
}
```

### 5.  Graphics Inbuilt functions
```c

#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    line(100, 100, 200, 200);
    circle(300, 150, 50);
    rectangle(400, 100, 500, 200);
    ellipse(600, 150, 0, 360, 50, 25);
    getch();
    closegraph();
}
```

### 6.  Line Drawing Algorithms (DDA & Bresenham‟s Algorithm)
```c
// Part 1 : DDA Line Drawing Algorithm

#include <graphics.h>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <string>

void DDA_Algo(int x1, int y1, int x2, int y2, int delay_time)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int iter = std::max(abs(dx), abs(dy)); // argggggh
    float x_inc = dx / (float)iter;
    float y_inc = dy / (float)iter;
    float x = x1;
    float y = y1;
    char buffer[50];
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4); 
    for (int i = 0; i < iter; i++)
    {
        printf("(%lf, %lf)\n", x, y);
        putpixel(round(x), round(y), WHITE);
        sprintf(buffer, "(%d, %d)", static_cast<int>(round(x)), static_cast<int>(round(y)));
        outtextxy(10, 10, buffer);
        x += x_inc;
        y += y_inc;
        delay(delay_time);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    DDA_Algo(100, 200, 400, 300, 20);
    getch();
    closegraph();
}
```

### 7.  Line Drawing Algorithms (DDA & Bresenham‟s Algorithm)
```c
// Part 2 : Bresenham‟s Line Drawing Algorithm

#include <graphics.h>
#include <stdio.h>
#include <cmath>

void Bresenham_Algo(int x1, int y1, int x2, int y2, int delay_time) {
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int x, y;

    int x_inc = (x2 > x1) ? 1 : -1;
    int y_inc = (y2 > y1) ? 1 : -1;

    char buffer[50];
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4); 

    int p, two_dy_dx, two_dy, two_dx;
    if (dx > dy) {
        p = 2 * dy - dx;
        two_dy_dx = 2 * (dy - dx);
        two_dy = 2 * dy;
        two_dx = 2 * dx;

        if (x2 < x1) {
            x = x2;
            y = y2;
            x2 = x1;
        } else {
            x = x1;
            y = y1;
        }
        putpixel(x, y, WHITE);
    } else {
        p = 2 * dx - dy;
        two_dy_dx = 2 * (dx - dy);
        two_dy = 2 * dy;
        two_dx = 2 * dx;

        if (y2 < y1) {
            x = x2;
            y = y2;
            y2 = y1;
        } else {
            x = x1;
            y = y1;
        }
        putpixel(x, y, WHITE);
    }

    for (int k = 0; k < std::max(dx, dy); k++) {
        if (dx > dy) {
            if (p < 0) {
                x += x_inc;
                p += two_dy;
            } else {
                x += x_inc;
                y += y_inc;
                p += two_dy_dx;
            }
        } else {
            if (p < 0) {
                y += y_inc;
                p += two_dx;
            } else {
                x += x_inc;
                y += y_inc;
                p += two_dy_dx;
            }
        }
        sprintf(buffer, "(%d, %d)", x, y);
        outtextxy(10, 10, buffer);
        printf("(%d, %d)\n", x, y);
        putpixel(x, y, WHITE);
        delay(delay_time);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    Bresenham_Algo(100, 200, 400, 300, 20);
    getch();
    closegraph();
    return 0;
}

```

### 8.  Circle Algorithms
```c
// Part 1 : Midpoint Circle Drawing Algorithm

#include <graphics.h>
#include <stdio.h>
#include <string>
#include <iostream>

void MidpointCircle(int xc, int yc, int radius, int delay_time) {
    int x = radius;
    int y = 0;
    int p = 1 - radius;
    char buffer[50];
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    while (x > y) {
        putpixel(xc + x, yc - y, WHITE);
        std::cout << "Putpixel at (" << xc + x << ", " << yc - y << ")" << std::endl;
        putpixel(xc - x, yc - y, WHITE);
        std::cout << "Putpixel at (" << xc - x << ", " << yc - y << ")" << std::endl;
        putpixel(xc + x, yc + y, WHITE);
        std::cout << "Putpixel at (" << xc + x << ", " << yc + y << ")" << std::endl;
        putpixel(xc - x, yc + y, WHITE);
        std::cout << "Putpixel at (" << xc - x << ", " << yc + y << ")" << std::endl;
        putpixel(xc + y, yc - x, WHITE);
        std::cout << "Putpixel at (" << xc + y << ", " << yc - x << ")" << std::endl;
        putpixel(xc - y, yc - x, WHITE);
        std::cout << "Putpixel at (" << xc - y << ", " << yc - x << ")" << std::endl;
        putpixel(xc + y, yc + x, WHITE);
        std::cout << "Putpixel at (" << xc + y << ", " << yc + x << ")" << std::endl;
        putpixel(xc - y, yc + x, WHITE);
        std::cout << "Putpixel at (" << xc - y << ", " << yc + x << ")" << std::endl;
        y++;

        if (p <= 0)
            p = p + 2 * y + 1;
        else {
            x--;
            p = p + 2 * y - 2 * x + 1;
        }

        if (x < y)
            break;
        putpixel(xc + x, yc - y, WHITE);
        std::cout << "Putpixel at (" << xc + x << ", " << yc - y << ")" << std::endl;
        putpixel(xc - x, yc - y, WHITE);
        std::cout << "Putpixel at (" << xc - x << ", " << yc - y << ")" << std::endl;
        putpixel(xc + x, yc + y, WHITE);
        std::cout << "Putpixel at (" << xc + x << ", " << yc + y << ")" << std::endl;
        putpixel(xc - x, yc + y, WHITE);
        std::cout << "Putpixel at (" << xc - x << ", " << yc + y << ")" << std::endl;
        putpixel(xc + y, yc - x, WHITE);
        std::cout << "Putpixel at (" << xc + y << ", " << yc - x << ")" << std::endl;
        putpixel(xc - y, yc - x, WHITE);
        std::cout << "Putpixel at (" << xc - y << ", " << yc - x << ")" << std::endl;
        putpixel(xc + y, yc + x, WHITE);
        std::cout << "Putpixel at (" << xc + y << ", " << yc + x << ")" << std::endl;
        putpixel(xc - y, yc + x, WHITE);
        std::cout << "Putpixel at (" << xc - y << ", " << yc + x << ")" << std::endl;
        delay(delay_time);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    MidpointCircle(400, 250, 100, 10);
    getch();
    closegraph();
    return 0;
}

```

### 9.  Circle Algorithms
```c
// Part 2 : Bresenham‟s Circle Drawing Algorithm

#include <graphics.h>
#include <iostream>

void BresenhamCircle(int xc, int yc, int radius, int delay_time) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    char buffer[50];
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);

    while (x <= y) {
        putpixel(xc + x, yc - y, WHITE);
        std::cout << "Putpixel at (" << xc + x << ", " << yc - y << ")" << std::endl;

        putpixel(xc - x, yc - y, WHITE);
        std::cout << "Putpixel at (" << xc - x << ", " << yc - y << ")" << std::endl;

        putpixel(xc + x, yc + y, WHITE);
        std::cout << "Putpixel at (" << xc + x << ", " << yc + y << ")" << std::endl;

        putpixel(xc - x, yc + y, WHITE);
        std::cout << "Putpixel at (" << xc - x << ", " << yc + y << ")" << std::endl;

        putpixel(xc + y, yc - x, WHITE);
        std::cout << "Putpixel at (" << xc + y << ", " << yc - x << ")" << std::endl;

        putpixel(xc - y, yc - x, WHITE);
        std::cout << "Putpixel at (" << xc - y << ", " << yc - x << ")" << std::endl;

        putpixel(xc + y, yc + x, WHITE);
        std::cout << "Putpixel at (" << xc + y << ", " << yc + x << ")" << std::endl;

        putpixel(xc - y, yc + x, WHITE);
        std::cout << "Putpixel at (" << xc - y << ", " << yc + x << ")" << std::endl;

        if (d < 0)
            d = d + 4 * x + 6;
        else {
            d = d + 4 * (x - y) + 10;
            y--;
        }

        x++;

        delay(delay_time);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    BresenhamCircle(400, 250, 100, 10);

    getch();
    closegraph();
    return 0;
}

```

### 10.  Translation in 2D
```c
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

```

### 11.  Translation in 2D
```c
// Part 2: Translation of a line

#include <graphics.h>
#include <iostream>

struct Line {
    int x1, y1, x2, y2;
};

void translateLine(Line& line, int Tx, int Ty) {
    line.x1 += Tx;
    line.y1 += Ty;
    line.x2 += Tx;
    line.y2 += Ty;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    Line myLine = {100, 100, 200, 200};
    std::cout << "Original Line: (" << myLine.x1 << ", " << myLine.y1 << ") to (" << myLine.x2 << ", " << myLine.y2 << ")\n";
    line(myLine.x1, myLine.y1, myLine.x2, myLine.y2);
    int Tx = 30, Ty = 40;
    translateLine(myLine, Tx, Ty);
    std::cout << "Translated Line: (" << myLine.x1 << ", " << myLine.y1 << ") to (" << myLine.x2 << ", " << myLine.y2 << ")\n";
    line(myLine.x1, myLine.y1, myLine.x2, myLine.y2);
    getch();
    closegraph();
    return 0;
}

```

### 12.  Translation in 2D
```c
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
```

### 13.  Rotation in 2D
```c

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


```

### 14.  Scaling in 2D
```c

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
```

### 15.  Cohen Sutherland's Algorithm
```c

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

```

### 16.  Program to rotate a circle outside another circle
```c

#include <graphics.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x_center = 300, y_center = 300;
    int outer_radius = 100;
    int inner_radius = 30;
    int angle = 0;

    for (int i = 0; i < 100; ++i) {
        cleardevice();
        circle(x_center, y_center, outer_radius); // Outer circle
        int x_inner = static_cast<int>(x_center + outer_radius * cos(angle * (M_PI / 180)));
        int y_inner = static_cast<int>(y_center + outer_radius * sin(angle * (M_PI / 180)));
        circle(x_inner, y_inner, inner_radius); // Inner circle
        delay(50); 
        angle = (angle + 5) % 360; 
    }

    getch();
    closegraph();
    return 0;
}

```

### 17.  Program to draw Flying Balloons
```c

#include <graphics.h>
#include <stdlib.h>

void drawBalloon(int x, int y, int radius) {
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(x, y, radius);
    floodfill(x, y, YELLOW);
}

void moveBalloon(int &x, int &y, int speed) {
    x += speed;

    if (x > getmaxx() + 50) { // reset if balloon goes out of screen
        x = -50;
        y = rand() % (getmaxy() - 50) + 50;  // Randomize the y coordinate
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 50, y1 = 100; 
    int x2 = 150, y2 = 200;

     for (int i = 0; i < 1000; ++i) {
        cleardevice(); // Clear the screen

        drawBalloon(x1, y1, 20);
        drawBalloon(x2, y2, 30);

        moveBalloon(x1, y1, 2);
        moveBalloon(x2, y2, 1);

        delay(10); // Adjust the delay for animation speed
    }

    getch();
    closegraph();
    return 0;
}

```

### 18.  Show Bouncing Ball Animation
```c

#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x = 20, y = 200, dy = 2, uplimit = 250;

    while (true) {
        cleardevice();
        setcolor(3);
        line(0, 400, 679, 400);

        y += dy;
        x += 1;

        if (y >= 385 && dy > 0) {
            dy = -dy;
        } else if (y <= uplimit && dy < 0) {
            dy = -dy;
            uplimit += 20;
        }

        setcolor(15);
        fillellipse(x, y, 15, 15);
        delay(15);

        setcolor(0);
        setfillstyle(1, 10);
        fillellipse(x, y, 15, 15);
    }

    getch();
    closegraph();
    return 0;
}

```

