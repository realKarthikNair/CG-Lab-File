// Show Bouncing Ball Animation

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
