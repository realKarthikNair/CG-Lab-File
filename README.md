The code files are in [lab file](/lab%20file/) directory.

Setup instructions for Linux are in [setting_up](setting_up.md) file. Vscode launch and task files for Fedora Linux are in [.vscode](.vscode/) directory.

These programs were written and tested on Linux. 

But to make them work on Windows, 

- Depending on your implementation of graphics.h, you may need to add to conio.h header file in every program. 
- You may need to replace `NULL`  with the appropriate path in `initgraph(&gd, &gm, NULL);` and wherever applicable. 

