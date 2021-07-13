#include <ncurses.h>
#include <string.h>

#include "main.h"
#include "draw.h"

//move an Object with an x and y location
void move_object(OBJ *object, int x, int y) {
    //return if there is no symbol to move or no floor
    if (strncmp(NULLSTR, object->symbol, 1) == 0 || 
            strncmp(NULLSTR, object->floor, 1) == 0) {
        mvprintw(5, 0, "%d", strncmp(NULLSTR, object->symbol, 1));
        mvprintw(6, 0, "%d", strncmp(NULLSTR, object->floor, 1));
        mvprintw(8, 0, "'%s'", object->floor);
        return;
    }
    
    //draw the floor over current position
    mvprintw(object->ypos, object->xpos, object->floor);
    //put new floor into variable
    //char nfl[2];
    //mvinnstr(y, x, nfl, 1);
    //mvprintw(7, 0, "'%s''%s'", nfl, object->floor);
    //object->floor = nfl;
    //draw object on new location
    mvprintw(y, x, object->symbol);

    object->xpos = x;
    object->ypos = y;
}

//draws a map which the given struct belongs to
void get_map(OBJ *object) {
    //return if there is no map to draw
    if (object->loc == NULL)
        return;
    
    //start
    if (object->loc == &objs[1]) {
        mvprintw(0, 0, "------");
        mvprintw(1, 0, "|....|");
        mvprintw(2, 0, "|....|");
        mvprintw(3, 0, "|....|");
        mvprintw(4, 0, "------");
    } else {
        return;
    }
}
