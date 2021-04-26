#ifndef _GOTOXY_H__
#define _GOTOXY_H__
#include <windows.h>
void gotoXY(int x, int y)
{
static HANDLE h = NULL;
if(!h)
h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD c = { x, y };
SetConsoleCursorPosition(h,c);
}

#endif
