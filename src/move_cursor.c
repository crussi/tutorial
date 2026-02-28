#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

void moveCursor(void)
{
    int max_rows, max_cols;

    initscr();
    clear();

    /* Seed random number generator */
    srand((unsigned int)time(NULL));

    /* Get screen size */
    getmaxyx(stdscr, max_rows, max_cols);

    /* Plot 5 random points */
    for (int i = 0; i < 5; i++)
    {
        int y = rand() % max_rows;
        int x = rand() % max_cols;

        move(y, x);
        addch('*');   // faster than printw for single char
    }

    /* Move cursor to bottom and show message */
    move(max_rows - 1, 0);
    printw("5 random points plotted. Press any key to exit.");
    refresh();

    getch();
    endwin();
}
