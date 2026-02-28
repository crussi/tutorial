#include <ncurses.h>

void readChar(void)
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