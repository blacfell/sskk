//INCLUDES
#include <ncurses.h>
#include <stdlib.h>

#include "main.h"
#include "input.h"

//DEFINITIONS
struct Objects objs[] = {
{"you", "the kitty reading this :flushed:", "@", NULLSTR, 0, 0, &objs[1]},
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
}

//say Goodbye to stdscr
void exit_game(int code) {
    endwin();
    exit(code);
}

int main(void) {
    initialise();
    while (1) {
        refresh();
        get_input();
    }
    exit_game(0);
    exit(EXIT_SUCCESS); //exit_game does this also but this is here to be safe
}
