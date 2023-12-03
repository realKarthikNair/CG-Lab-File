// Shearing in 2D

#include <graphics.h>

void drawOriginalShape() {
    setcolor(RED);
    rectangle(100, 100, 200, 200);
}

void drawShearedShape() {
    setcolor(BLUE);

    int shearX = 1; 
    int shearY = 0; 
    int x1 = 100 + shearX * 100;
    int y1 = 100 + shearY * 100;
    int x2 = 200 + shearX * 100;
    int y2 = 200 + shearY * 100;

    rectangle(x1, y1, x2, y2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    drawOriginalShape();
    delay(2000);
    cleardevice();
    
    drawShearedShape();

    getch();
    closegraph();
    return 0;
}
