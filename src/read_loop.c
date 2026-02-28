#include <ncurses.h>

void readLoop(void)
{
    char ch;
    initscr();

    noecho();
    while ((ch = getch()) != '\n')
    {
        printw("You typed: %c\n", ch);
        refresh();
    }
    endwin();

}