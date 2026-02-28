#include <ncurses.h>

void showNodelay2(void)
{
    int counter = 0;
    initscr();
    nodelay(stdscr, TRUE);  // make getch non-blocking
    while (getch() == ERR)  // loop until a key is pressed
    {
        clear();
        printw("Program running for: %d seconds\n", ++counter);
        refresh();
        napms(1000);  // wait 1 second
    }

    nodelay(stdscr, FALSE);  // restore blocking behavior
    printw("You pressed a key after : %d seconds\n", counter);
    refresh();
    getch();
    endwin();
}
