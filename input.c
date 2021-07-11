#include <ncurses.h>

#include "main.h"
#include "input.h"

//read input from user
void get_input(void) {
    int c = getch(); //this is the character input

    switch (c) {
        case 'q':
            exit_game(0);
        default:
            break;
    }
}
