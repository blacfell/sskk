#pragma once

struct Objects {
    const char *name; //short name
    const char *desc; //description
    const char *symbol; //tui representation
    int xpos; //x position. set to 0 if n/a
    int ypos; //y position. set to 0 if n/a
    struct Objects *loc; //struct of item's location
                         //can be set to non-places to imply possession
};

extern struct Objects objs[];

void initialise(void);
void exit_game(int code);
