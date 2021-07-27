/* look.c
 **********
 * help the player identity things
 */

#include <ncurses.h>

#include "sskk.h"
#include "look.h"

static void look_move(int x, int y);
static void look_refresh(void);

const char *look_check(char c) {
	switch (c) {
		case '@':
			return "you";
		case '.':
			return "floor";
		case '|':
		case '-':
			return "wall";
		case 'o':
			return "object";
		case '+':
			return "door";
		case 'k':
			return "keys";
		default:
			return "something";
	}
	write_message("how did you get here??");
	return "nothing";
}

static void look_move(int x, int y) {
	move(y, x);
	write_message(look_check(inch() & A_CHARTEXT));
	move(y, x);
}

static void look_refresh(void) {
	refresh();
}

//main loop for look functionality.
//takes starting x and y position as input.
void look_around(int inx, int iny) {
	int x = inx;
	int y = iny;
	move(y, x);
	curs_set(1); //make cursor visible
	int c;
	while (1) {
		look_refresh();
		c = getch();
		switch (c) {
			case 'h':
			case KEY_LEFT:
				look_move(x - 1, y);
				x--;
				break;
			case 'j':
			case KEY_DOWN:
				look_move(x, y + 1);
				y++;
				break;
			case 'k':
			case KEY_UP:
				look_move(x, y - 1);
				y--;
				break;
			case 'l':
			case KEY_RIGHT:
				look_move(x + 1, y);
				x++;
				break;

			case 'q':
			case 27:
				curs_set(0);
				return;
			default:
				break;
		}
	}
}
