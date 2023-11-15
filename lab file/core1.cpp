// Drawing objects like circle, rectangle, polygon etc using graphic function 

# include <graphics.h>
// # include <ncurses.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    circle(100, 100, 50);
    getch();
    closegraph();
}