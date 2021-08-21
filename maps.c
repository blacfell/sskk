/* maps.c
 **********
 * storage for this game's maps. yes, all of this is hard coded. sorry
 */

#include <ncurses.h>
#include <stdbool.h>
#include <string.h>

#include "sskk.h"
#include "maps.h"
#include "item.h"

static void m4_events(int x, int y);
static void m4_draw_map(void);

static void m3_events(int x, int y);
static void m3_draw_map(void);

static void m2_events(int x, int y);
static void m2_draw_map(void);

static void m1_events(int x, int y);
static void m1_draw_map(void);

static void m0_events(int x, int y);
static void m0_draw_map(void);

/*** MAP 4 ***/

static void m4_events(int x, int y) {
}

static void m4_draw_map(void) {
}

/*** MAP 3 ***/

static void m3_events(int x, int y) {
}

static void m3_draw_map(void) {
	mvprintw(1,  1, "-----     ------");
	mvprintw(2,  1, "|...|     |....|");
	mvprintw(3,  1, "--|.|-----|.|---");
	mvprintw(4,  1, "  |.........|   ");
	mvprintw(5,  1, "  -----.-----   ");
	mvprintw(6,  1, "      |.|       ");
	mvprintw(7,  1, "      |.|       ");
	mvprintw(8,  1, "  -----.-----   ");
	mvprintw(9,  1, "  |.........|   ");
	mvprintw(10, 1, "  |.........|   ");
	mvprintw(11, 1, "  |.........|   ");
	mvprintw(12, 1, "  |.........|   ");
	mvprintw(13, 1, "  -----------   ");
}

/*** MAP 2 ***/

static void m2_events(int x, int y) {
	if (x == 5 && y == 12 && search_item("key") == 0) {
		pick_up((struct Item){"k", "key"});
		warp_to(3, 5, 12);
		player.floor[0] = '.';
	}
}

static void m2_draw_map(void) {
	mvprintw(1,  1, "-----     ------");
	mvprintw(2,  1, "|...|     |....|");
	mvprintw(3,  1, "--|.|-----|.|---");
	mvprintw(4,  1, "  |.........|   ");
	mvprintw(5,  1, "  -----.-----   ");
	mvprintw(6,  1, "      |.|       ");
	mvprintw(7,  1, "      |.|       ");
	mvprintw(8,  1, "  -----.-----   ");
	mvprintw(9,  1, "  |.........|   ");
	mvprintw(10, 1, "  |.........|   ");
	mvprintw(11, 1, "  |.........|   ");
	mvprintw(12, 1, "  |.k.......|   ");
	mvprintw(13, 1, "  -----------   ");
}

/*** MAP 1 ***/

static void m1_events(int x, int y) {
	if (x == 12 && y == 4) {
		warp_to(2, 12, 4);
		write_message("maybe you are missing something.");
	}
}

static void m1_draw_map(void) {
	mvprintw(1, 1, "-----     ------");
	mvprintw(2, 1, "|...|     |....|");
	mvprintw(3, 1, "--|.|-----|+|---");
	mvprintw(4, 1, "  |.........|   ");
	mvprintw(5, 1, "  -----------   ");
}

/*** MAP 0 ***/

static void m0_events(int x, int y) {
	static int turns = 0;
	if (turns >= 1 && turns <= 3) {
		write_message("where have you ended up now?");
	} else if (player.floor[0] == 'o') {
		write_message("this is an Object. the Door is now gone.");
		mvprintw(4, 20, ".");
	} else if (y == 4 && x == 21) {
		write_message("you understand, now, what you need to do.");
	} else if (y == 4 && x == 30) {
		warp_to(1, 2, 2);
	}
	turns++;
}

static void m0_draw_map(void) {
	mvprintw(1, 1, "--------------------");
	mvprintw(2, 1, "|..................|");
	mvprintw(3, 1, "|..................|-----------");
	mvprintw(4, 1, "|...............o..+..........|");
	mvprintw(5, 1, "|..................|-----------");
	mvprintw(6, 1, "|..................|");
	mvprintw(7, 1, "--------------------");
}

/*** BASE MAP CODE ***/

void check_events(int mapcode, int x, int y) {
	switch (mapcode) {
		case 0:
			m0_events(x, y);
			break;
		case 1:
			m1_events(x, y);
			break;
		case 2:
			m2_events(x, y);
			break;
		case 3:
			m3_events(x, y);
			break;
		case 4:
			m4_events(x, y);
			break;
		default:
			break;
	}
}

//recieves map code number
void draw_map(int mapcode) {
	erase();
	switch (mapcode) {
		case 0:
			m0_draw_map();
			break;
		case 1:
			m1_draw_map();
			break;
		case 2:
			m2_draw_map();
			break;
		case 3:
			m3_draw_map();
			break;
		case 4:
			m4_draw_map();
			break;
		default:
			write_message("error in draw_map: invalid mapcode");
			break;
	}
}
