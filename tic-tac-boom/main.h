#ifndef MAIN_H
#define MAIN_H

typedef struct Game {
	char turn; //who's turn it is
	char** grid;
	bool explodeX;
	bool explodeO;
	bool xAuto;
	bool oAuto;
	int gridSize;
	int xMoveCount;
	int oMoveCount;
} Game;

enum ErrorCode {
	INVALID_ARGS = 1,
	INVALID_SAVE_FILE = 2
};

int string_to_int(char* string);
void print_grid(Game* game);
bool commandline_check_valid(int arg, char** args);
void error_print(int errorCode);
#endif
