// Translation in 2D
// Part 2: Translation of a line

#include <graphics.h>
#include <iostream>

struct Line {
    int x1, y1, x2, y2;
};

void translateLine(Line& line, int Tx, int Ty) {
    line.x1 += Tx;
    line.y1 += Ty;
    line.x2 += Tx;
    line.y2 += Ty;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    Line myLine = {100, 100, 200, 200};
    std::cout << "Original Line: (" << myLine.x1 << ", " << myLine.y1 << ") to (" << myLine.x2 << ", " << myLine.y2 << ")\n";
    line(myLine.x1, myLine.y1, myLine.x2, myLine.y2);
    int Tx = 30, Ty = 40;
    translateLine(myLine, Tx, Ty);
    std::cout << "Translated Line: (" << myLine.x1 << ", " << myLine.y1 << ") to (" << myLine.x2 << ", " << myLine.y2 << ")\n";
    line(myLine.x1, myLine.y1, myLine.x2, myLine.y2);
    delay(5000); // Wait for 5 seconds
    closegraph();
    getch();
    return 0;
}
