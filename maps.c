/*
 * maps.c
 **********
 * storage for this game's maps. yes, all of this is hard coded. sorry
 */

#include <ncurses.h>
#include <stdbool.h>

#include "sskk.h"
#include "maps.h"

static void m0_events(int x, int y);

/*** MAP 0 ***/

static void m0_events(int x, int y) {
	if (x == 17 && y == 4) {
		write_message("this is an object.");
	}
}

/*** BASE MAP CODE ***/

void check_events(int mapcode, int x, int y) {
	switch (mapcode) {
		case 0:
			m0_events(x, y);
			break;
		default:
			break;
	}
}

//recieves map code number
void draw_map(int mapcode) {
	switch (mapcode) {
		case 0:
			mvprintw(1, 1, "--------------------");
			mvprintw(2, 1, "|..................|");
			mvprintw(3, 1, "|..................|");
			mvprintw(4, 1, "|...............o..|");
			mvprintw(5, 1, "|..................|");
			mvprintw(6, 1, "|..................|");
			mvprintw(7, 1, "--------------------");
			break;
		default:
			write_message("error in draw_map: invalid mapcode");
			break;
	}
}
