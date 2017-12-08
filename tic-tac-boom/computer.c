#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "computer.h"
#define GENERAL_ERROR -1

/*void tnt_explode(?????) {
}*/

/**
 * Checks if the current player taking turn is a automatic player.
 * @param  game The game struct
 * @return      either the current player if a automatic player, else general 
 * error.
 */
int is_automatic_player(Game* game) {
	if (game->turn == 'x') {
		if (xAuto) {
			return PLAYER_X;
		}
	} else {
		if (oAuto) {
			return PLAYER_O;
		}
	}
	return GENERAL_ERROR;
}

void automatic_coordinates_calc(Game* game) {
	int moveCount = (game->turn == 'x') ? game->xMoveCount : game->oMoveCount;
	int x = (game->gridSize % 10) + 32 + moveCount;
	int y = (x % 10) + 23 + moveCount;
	//TODO: check that calcualted coordiantes don't already exist on board
}