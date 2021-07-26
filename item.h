//item.h
#pragma once

#define BAGSIZE 5

struct Item {
	char logo[2]; //second is null byte
	//these are maybe excessively large? i'm not sure.
	char name[10]; 
};

extern struct Item inventory[BAGSIZE];

int search_item(const char *query);
void pick_up(struct Item item);
void init_inventory(void);
