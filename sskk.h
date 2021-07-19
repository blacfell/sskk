//sskk.h
#pragma once

#include <stdbool.h>

struct Actor {
	int x;
	int y;
	int mapcode;
	char logo[2]; //second is null byte
	char floor[2]; //second is null byte
};

extern struct Actor player;

bool check_collision(int x, int y);
void move_actor(struct Actor *act, int x, int y);
void write_message(const char *fmt, ...);
void clear_message(void);
void write_status(void);
