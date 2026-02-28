#include <ncurses.h>

void printCursorPosition(void)
{
    int row, col;
    initscr();
    getyx(stdscr, row, col);  // get current cursor position
    printw("Current cursor position: (%d, %d)\n", row, col);

}

void cursorManipulation(void)
{
    initscr();
    printCursorPosition();
    printCursorPosition();
    refresh();
    getch();
    endwin();
} 