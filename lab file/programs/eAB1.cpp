// Program to rotate a circle outside another circle

#include <graphics.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x_center = 300, y_center = 300;
    int outer_radius = 100;
    int inner_radius = 30;
    int angle = 0;

    for (int i = 0; i < 100; ++i) {
        cleardevice();
        circle(x_center, y_center, outer_radius); // Outer circle
        int x_inner = static_cast<int>(x_center + outer_radius * cos(angle * (M_PI / 180)));
        int y_inner = static_cast<int>(y_center + outer_radius * sin(angle * (M_PI / 180)));
        circle(x_inner, y_inner, inner_radius); // Inner circle
        delay(50); 
        angle = (angle + 5) % 360; 
    }

    getch();
    closegraph();
    return 0;
}
