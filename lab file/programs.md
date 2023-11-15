### 1.  Drawing objects like circle, rectangle, polygon etc using graphic function 
```c
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
```

### 2.  Drawing objects like circle, rectangle, polygon etc using graphic function 
```c
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
```

### 3.  Drawing objects like circle, rectangle, polygon etc using graphic function 
```c
// Part 3 - polygon

# include <graphics.h>
// # include <ncurses.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    line(100, 100, 200, 0);
    line(200, 0, 300, 100);
    line(100, 100, 300, 100);
    line(100, 100, 100, 300);
    line(100, 300, 300, 300);
    line(300, 100, 300, 300);
    getch();
    closegraph();
}
```

### 4.  Drawing objects like circle, rectangle, polygon etc using graphic function 
```c
// Part 4 - hut with circle inside 

# include <graphics.h>
// # include <ncurses.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    line(100, 100, 200, 0);
    line(200, 0, 300, 100);
    line(100, 100, 300, 100);
    line(100, 100, 100, 300);
    line(100, 300, 300, 300);
    line(300, 100, 300, 300);
    circle(200, 200, 50);
    getch();
    closegraph();
}
```

### 5.  Graphics Inbuilt functions
```c

#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    line(100, 100, 200, 200);
    circle(300, 150, 50);
    rectangle(400, 100, 500, 200);
    ellipse(600, 150, 0, 360, 50, 25);
    getch();
    closegraph();
}
```

### 6.  Line Drawing Algorithms (DDA & Bresenham‟s Algorithm)
```c
// Part 1 : DDA Line Drawing Algorithm

#include <graphics.h>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <string>

void DDA_Algo(int x1, int y1, int x2, int y2, int delay_time)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int iter = std::max(abs(dx), abs(dy)); // argggggh
    float x_inc = dx / (float)iter;
    float y_inc = dy / (float)iter;
    float x = x1;
    float y = y1;
    char buffer[50];
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4); 
    for (int i = 0; i < iter; i++)
    {
        putpixel(round(x), round(y), WHITE);
        sprintf(buffer, "(%d, %d)", static_cast<int>(round(x)), static_cast<int>(round(y)));
        outtextxy(10, 10, buffer);
        x += x_inc;
        y += y_inc;
        delay(delay_time);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    DDA_Algo(100, 200, 400, 300, 20);
    getch();
    closegraph();
}
```

