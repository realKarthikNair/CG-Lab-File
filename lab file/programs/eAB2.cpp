// Program to draw Flying Balloons

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
