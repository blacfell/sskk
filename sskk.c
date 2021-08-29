/* sskk.c
 **********
 * contains the main functions for the game's operation. this code should be
 * easily reusable.
 */

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "sskk.h"
#include "maps.h"
#include "look.h"
#include "item.h"

static int get_input(void);
static void refresh_game(void);
static int init_game(void);

struct Actor player = {0, 0, 0, {'@', '\0'}, {' ', '\0'}};

/*** MOVEMENT ***/

//checks given location's block's collision
//returns true if valid.
bool check_collision(int x, int y) {
	if (y > 20 || y < 0 || x > 80 || x < 0) return false;

	char c = mvinch(y, x) & A_CHARTEXT;
	switch (c) {
		case '|':
		case '-':
		case '+':
			return false;
		default:
			return true;
	}
}

void move_actor(struct Actor *act, int x, int y) {
	if (check_collision(x, y) == false) return;
	mvprintw(act->y, act->x, act->floor);
	act->floor[0] = mvinch(y, x) & A_CHARTEXT;
	mvprintw(y, x, act->logo);
	//put new x and y into struct
	act->y = y;
	act->x = x;
}

//warp to location
void warp_to(int to, int dest_x, int dest_y) {
	player.x = dest_x;
	player.y = dest_y;
	player.mapcode = to;

	draw_map(to);
	move_actor(&player, dest_x, dest_y);
}

/*** DISPLAY ***/

//display list of items
//i don't remember why i put this here
void inventory_list(void) {
	write_message("--INVENTORY-- Press any key to return to game.");
	attron(A_STANDOUT);
	for (int i = 0; i < BAGSIZE; i++) {
		if (strcmp(inventory[i].name, "null"))
			mvprintw(i+1, 1, inventory[i].name);
	}
	attroff(A_STANDOUT);
	refresh_game();
	getch();
	draw_map(player.mapcode);
	move_actor(&player, player.x, player.y);
}

//puts a message into the status bar
void write_message(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	attron(A_STANDOUT);
	move(22, 0); //move to status line
	clrtoeol(); //clears the status line
	vw_printw(stdscr, fmt, ap); //write message
	attroff(A_STANDOUT);
	va_end(ap);
}

//clears the message. use this for prompts etc.
void clear_message(void) {
	move(22, 0);
	clrtoeol();
}

void write_status(void) {
	attron(A_STANDOUT);
	move(21, 0);
	clrtoeol();
	printw("x: %d, y: %d\tmap: %d",
			player.x, player.y, player.mapcode);
	attroff(A_STANDOUT);
}

/*** INPUT ***/

//detects user keypresses
//returns 0 unless the user is quitting the program
static int get_input(void) {
	int c = getch();

	switch (c) {
		//should i create a move_player preprocessor directive?
		case 'h':
		case KEY_LEFT:
			move_actor(&player, player.x - 1, player.y);
			break;
		case 'j':
		case KEY_DOWN:
			move_actor(&player, player.x, player.y + 1);
			break;
		case 'k':
		case KEY_UP:
			move_actor(&player, player.x, player.y - 1);
			break;
		case 'l':
		case KEY_RIGHT:
			move_actor(&player, player.x + 1, player.y);
			break;
		case 'y':
			move_actor(&player, player.x - 1, player.y - 1);
			break;
		case 'u':
			move_actor(&player, player.x + 1, player.y - 1);
			break;
		case 'b':
			move_actor(&player, player.x - 1, player.y + 1);
			break;
		case 'n':
			move_actor(&player, player.x + 1, player.y + 1);
			break;
		case ';':
			look_around(player.x, player.y);
			break;
		case 'i':
			inventory_list();
			break;

		case 'q':
			//fuck you
			write_message("really quit? (y/n)");
			while (1) {
				c = getch();
				switch (c) {
					case 'y':
						return 1;
					case 'n':
						clear_message();
						break;
					default:
						continue;
				}
				break;
			}
			break;
		default:
			break;
	}
	return 0;
}


/*** BASE ***/

//refresh the screen
static void refresh_game(void) {
	check_events(player.mapcode, player.x, player.y);
	write_status();
	refresh();
}

//initialise the game.
//TODO add error handling here
static int init_game(void) {
	initscr();
	raw();
	noecho();
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);
	curs_set(0);

	init_inventory();

	write_message("welcome to sskk");
	draw_map(0);
	move_actor(&player, 2, 2);

	return EXIT_SUCCESS;
}

int main() {
	if (init_game() == EXIT_FAILURE)
		return EXIT_FAILURE;
	while (1) {
		refresh_game();
		if (get_input() == 1) break;
	}
	endwin();
	return EXIT_SUCCESS;
}
