#include <ncurses.h>
#include <string.h>

#include "main.h"
#include "draw.h"

//move an Object with an x and y location
void move_object(struct Objects *object, int x, int y) {
    //return if there is no symbol to move or no floor
    if (strcmp(NULL, object->symbol) || strcmp(NULL, object->floor)) {
        return;
    }
    
    //draw the floor over current position
    mvprintw(object->ypos, object->xpos, object->floor);
    //put new floor into variable
    object->floor = strcat(mvinch(y, x), "\0");
    //draw object on new location
    mvprintw(y, x, object->symbol);
}
