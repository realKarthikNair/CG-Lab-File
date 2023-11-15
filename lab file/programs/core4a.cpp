// Circle Algorithms
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
