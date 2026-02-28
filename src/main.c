#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

/* function prototypes */
void readLetterDemo(void);
void moveCursorDemo(void);
void moveCursorDemo2(void);

int main(void)
{
    moveCursorDemo2();
    return 0;
}

void readLetterDemo(void)
{
    char letter;

    initscr();

    printw("Type a letter and press Enter: ");
    refresh();

    letter = getch();

    clear();

    printw("You typed: %c", letter);
    refresh();

    getch();

    endwin();
}

void moveCursorDemo(void)
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

void moveCursorDemo2(void)
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