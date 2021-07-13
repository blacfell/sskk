#include <ncurses.h>

#include "main.h"
#include "input.h"
#include "draw.h"

//read input from user
void get_input(void) {
    int c = getch(); //this is the character input

    switch (c) {
        case 'h':
            move_object(&PLAYER, PLAYER.xpos - 1, PLAYER.ypos);
            break;
        case 'j':
            move_object(&PLAYER, PLAYER.xpos, PLAYER.ypos + 1);
            break;
        case 'k':
            move_object(&PLAYER, PLAYER.xpos, PLAYER.ypos - 1);
            break;
        case 'l':
            move_object(&PLAYER, PLAYER.xpos + 1, PLAYER.ypos);
            break;

        case 'q':
            exit_game(0);
        default:
            break;
    }
}
