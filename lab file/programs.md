### 1.  Drawing objects like circle, rectangle, polygon etc using graphic function 
```c
// Part 1 - circle 

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

