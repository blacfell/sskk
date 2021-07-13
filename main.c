//INCLUDES
#include <ncurses.h>
#include <stdlib.h>

#include "main.h"
#include "input.h"
#include "draw.h"

//DEFINITIONS
OBJ objs[] = {
{"you", "the kitty reading this :flushed:", "@", ".", 1, 1, &objs[1]},
{"start", "the Beginning", NULLSTR, NULLSTR, 0, 0, NULL},
};

//get everything set up
void initialise(void) {
    initscr(); //initialise ncurses screen
    raw(); //let us use C-c and others
    noecho(); //don't write keys to the screen
    nonl(); //this is something to do with newlines. i dont understand
    intrflush(stdscr, FALSE); //disables an interrupt key Fucking Shit Up
    keypad(stdscr, TRUE); //allow use of the 'keypad' (like arrow keys and shit)
    curs_set(0); //hide cursor
}

//say Goodbye to stdscr
void exit_game(int code) {
    endwin();
    exit(code);
}

int main(void) {
    initialise();
    get_map(&PLAYER);
    move_object(&PLAYER, PLAYER.xpos, PLAYER.ypos);
    while (1) {
        refresh();
        get_input();
    }
    exit_game(0);
    exit(EXIT_SUCCESS); //exit_game does this also but this is here to be safe
}
