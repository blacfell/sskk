#pragma once

#define NULLSTR "\0"

#define PLAYER objs[0]
#define START objs[1]

typedef struct Objects {
    const char *name; //short name
    const char *desc; //description
    char symbol[2]; //tui representation
    char floor[2]; //whatever is under the object
    int xpos; //x position. set to 0 if n/a
    int ypos; //y position. set to 0 if n/a
    struct Objects *loc; //struct of item's location
                         //can be set to non-places to imply possession
} OBJ;

extern OBJ objs[];

void initialise(void);
void exit_game(int code);
