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

### 8. core4a.cpp
```c
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

