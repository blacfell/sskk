/* item.c
 **********
 * handle inventory
 */

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "sskk.h"
#include "maps.h"
#include "item.h"

struct Item inventory[BAGSIZE];

int search_item(const char *query) {
	for (int i = 0; i < BAGSIZE; i++) {
		if (strcmp(inventory[i].name, query)) {
			return 0;
		}
	}
	return 1;
}

void pick_up(struct Item item) {
	for (int i = 0; i < BAGSIZE; i++) {
		if (strcmp(inventory[i].name, "null") == 0) {
			inventory[i] = item;
			write_message("you have picked up %s", item.name);
			return;
		}
	}
	write_message("pickup failed");
}

void init_inventory(void) {
	for (int i = 0; i < BAGSIZE; i++) {
		strcpy(inventory[i].logo, " ");
		strcpy(inventory[i].name, "null");
		strcpy(inventory[i].desc, "null");
	}
}
