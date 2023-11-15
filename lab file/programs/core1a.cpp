// Drawing objects like circle, rectangle, polygon etc using graphic function 
// Part 1 - circle 

# include <graphics.h>
// # include <ncurses.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    circle(400, 250, 100);
    getch();
    closegraph();
}