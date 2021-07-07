//INCLUDES
#include <ncurses.h>
#include <stdlib.h>
#include <errno.h>

//PROTOTYPES
static void initialise(void);

//DEFINITIONS
struct Objects {
    const char *name;
    const char *desc;
    struct Objects *loc;
} objs[] = {
{"you", "the kitty reading this :flushed:", &objs[1]},
{"start", "the Beginning", NULL},
};


//get everything set up
static void initialise(void) {
    initscr(); //initialise ncurses screen
    raw(); //let us use C-c and others
    noecho(); //don't write keys to the screen
    nonl(); //this is something to do with newlines. i dont understand
    intrflush(stdscr, FALSE); //disables an interrupt key Fucking Shit Up
    keypad(stdscr, TRUE); //allow use of the 'keypad' (like arrow keys and shit)
}

int main(void) {
    initialise();
}
