#include "ncurses_wrapper.h"
#include <ncurses.h>
void ncursesInitscr()
{
    initscr();
}
void ncursesPrintw(const char *str)
{
    printw("%s", str);
}
void ncursesEndwin()
{
    endwin();
}