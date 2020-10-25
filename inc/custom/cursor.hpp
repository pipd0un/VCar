#ifndef CURSOR_HPP
#define CURSOR_HPP

#ifdef _WIN32
#include <windows.h>
COORD GetCursorPosition();
void SetCursorPosition(int XPos, int YPos);
#elif _linux_
#include <stdio.h>
void SetCursorPosition(int XPos, int YPos);
void getCursor(int* x, int* y);
// Or platform independent using (n)curses
#include <curses.h> // similar name for windows
initscr(); // is required before getxy call
getyx(curscr, y, x);
void getyx(WINDOW *win, int y, int x);
#endif



#endif //..