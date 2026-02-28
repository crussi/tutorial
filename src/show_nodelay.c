#include <ncurses.h>

void showNodelay(void)
{
    initscr();

    addstr("hello world");
    refresh();
    napms(1000);  // wait 1 second
    nodelay(stdscr, TRUE);  // make getch non-blocking
    getch();  // will return ERR immediately if no input
    endwin();
}