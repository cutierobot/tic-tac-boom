#ifndef COMPUTER_H
#define COMPUTER_H
#include "game.h"
enum PlayerTypes {
	PLAYER_O = 79,
	PLAYER_X = 88
};
int is_automatic_player(Game* game);
#endif
