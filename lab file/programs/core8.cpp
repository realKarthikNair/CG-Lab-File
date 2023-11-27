#include <graphics.h>

void drawOriginalShape() {
    setcolor(RED);
    rectangle(100, 100, 200, 200);
}

void drawReflectedShape() {
    setcolor(BLUE);
    rectangle(100, getmaxy() - 100, 200, getmaxy() - 200);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    drawOriginalShape(); 
    delay(2000); 
    cleardevice(); 
    drawReflectedShape();  
    getch();
    closegraph();
    return 0;
}
