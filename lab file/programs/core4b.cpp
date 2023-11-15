// Circle Algorithms
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
