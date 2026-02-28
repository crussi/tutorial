#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

void moveCursor2(void)
{
    int max_rows, max_cols;

    initscr();
    clear();
    curs_set(0);  // hide cursor (optional, looks nicer)

    /* Seed random number generator */
    srand((unsigned int)time(NULL));

    /* Get screen size */
    getmaxyx(stdscr, max_rows, max_cols);

    /* Blink cycle: repeat 5 times */
    for (int cycle = 0; cycle < 5; cycle++)
    {
        clear();

        /* Plot 5 random stars */
        for (int i = 0; i < 5; i++)
        {
            int y = rand() % max_rows;
            int x = rand() % max_cols;

            move(y, x);
            addch('*');
        }

        /* Message at bottom */
        move(max_rows - 1, 0);
        printw("Blink cycle %d/5", cycle + 1);

        refresh();

        /* Wait 400 milliseconds */
        napms(400);
    }

    /* Final message */
    move(max_rows - 1, 0);
    printw("Done. Press any key to exit.");
    refresh();

    getch();

    curs_set(1);  // restore cursor
    endwin();
}
