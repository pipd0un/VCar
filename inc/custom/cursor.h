#ifndef CURSOR_H
#define CURSOR_H

#ifdef _WIN32
#include <windows.h>
COORD GetCursorPosition() {
   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
   GetConsoleScreenBufferInfo(h, &bufferInfo);
   return bufferInfo.dwCursorPosition;
}
void SetCursorPosition(int XPos, int YPos) {
   COORD coord;
   coord.X = XPos; coord.Y = YPos;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}//tamam
#elif _linux_
#include <stdio.h>
void SetCursorPosition(int XPos, int YPos) {
    printf("\033[%d;%dH",YPos+1,XPos+1);
}
void getCursor(int* x, int* y) {
   printf("\033[6n");  /* This escape sequence !writes! the current
                          coordinates to the terminal.
                          We then have to read it from there, see [4,5].
                          Needs <termios.h>,<unistd.h> and some others */
   scanf("\033[%d;%dR", x, y);
}
// Or platform independent using (n)curses
#include <curses.h> // similar name for windows
initscr(); // is required before getxy call
getyx(curscr, y, x);
void getyx(WINDOW *win, int y, int x);//bu ne
#endif



#endif //..