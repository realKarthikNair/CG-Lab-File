// Graphics Inbuilt functions

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