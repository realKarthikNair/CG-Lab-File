// Drawing objects like circle, rectangle, polygon etc using graphic function 
// Part 2 - rectangle

# include <graphics.h>
// # include <ncurses.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    rectangle(100, 100, 300, 200);
    getch();
    closegraph();
}