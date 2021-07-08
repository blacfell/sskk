//INCLUDES
#include <ncurses.h>
#include <stdlib.h>

//DEFINITIONS
//this is a struct containing every thing in the game.
struct Objects {
    const char *name; //short name
    const char *desc; //description
    const char *symbol; //tui representation
    int xpos; //x position. set to 0 if n/a
    int ypos; //y position. set to 0 if n/a
    struct Objects *loc; //struct of item's location
                         //can be set to non-places to imply possession.
} objs[] = {
{"you", "the kitty reading this :flushed:", "@", 0, 0, &objs[1]},
{"start", "the Beginning", NULL, 0, 0, NULL},
};

//PROTOTYPES
void draw_object(struct Objects *obj);
static void initialise(void);

//DRAWING
//draw character from Objects array
void draw_object(struct Objects *obj) {
    mvprintw(obj->ypos, obj->xpos, obj->symbol);
}

//THE BEGINNING
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
    while (1) {

    }
}
