//INCLUDES
#include <ncurses.h>
#include <stdlib.h>

//PROTOTYPES
static void initialise(void);

//DEFINITIONS
struct Location {
    int          x;
    int          y;
    struct Item *place;
};

//this is based on code from this tutorial:
//https://helderman.github.io/htpataic/htpataic04.html
struct Item {
    const  char     *name;
    const  char     *description;
    struct Location *loc;
} items[] = { //this might be hard to understand. it is an array of Items.
{"start", "the beginning.", NULL},
{"you", "the kitty reading this :flushed:", {0, 0, &items[0]}},
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

}
