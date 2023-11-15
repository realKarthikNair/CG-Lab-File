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
