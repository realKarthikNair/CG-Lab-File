// Making an Analog Clock

#include <graphics.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

void drawClock() {
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int radius = 200;

    circle(centerX, centerY, radius);
    circle(centerX, centerY, 5);

    for (int i = 0; i < 12; i++) {
        int x = centerX + radius * cos(PI / 2 - i * PI / 6);
        int y = centerY - radius * sin(PI / 2 - i * PI / 6);
        circle(x, y, 5);
    }
}

void drawHourHand() {
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int radius = 200;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int x = centerX + radius * cos(PI / 2 - (ltm->tm_hour % 12) * PI / 6);
    int y = centerY - radius * sin(PI / 2 - (ltm->tm_hour % 12) * PI / 6);

    line(centerX, centerY, x, y);
}

void drawMinuteHand() {
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int radius = 200;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int x = centerX + radius * cos(PI / 2 - ltm->tm_min * PI / 30);
    int y = centerY - radius * sin(PI / 2 - ltm->tm_min * PI / 30);

    line(centerX, centerY, x, y);
}

void drawSecondHand() {
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int radius = 200;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int x = centerX + radius * cos(PI / 2 - ltm->tm_sec * PI / 30);
    int y = centerY - radius * sin(PI / 2 - ltm->tm_sec * PI / 30);

    line(centerX, centerY, x, y);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    while (true) {
        cleardevice();
        drawClock();
        drawHourHand();
        drawMinuteHand();
        drawSecondHand();
        delay(1000);
    }

    getch();
    closegraph();
    return 0;
}
