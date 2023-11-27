// Show Moving Car Animation

#include <graphics.h>


void drawCar(int x, int y) {
    setcolor(RED);
    rectangle(x, y, x + 100, y + 50);
    rectangle(x + 20, y - 20, x + 80, y);
    circle(x + 30, y + 50, 10);
    circle(x + 70, y + 50, 10);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x = 0;
    int y = getmaxy() / 2;

    while (x < getmaxx()) {
        cleardevice();
        drawCar(x, y);
        delay(10);
        x++;
    }

    getch();
    closegraph();
    return 0;
}
