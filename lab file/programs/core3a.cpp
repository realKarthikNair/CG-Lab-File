// Line Drawing Algorithms (DDA & Bresenham‟s Algorithm)
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