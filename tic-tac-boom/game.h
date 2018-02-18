#ifndef MAIN_H
#define MAIN_H
#define RESET  "\x1B[0m"
#define YELLOW  "\x1B[33m"
#define RED  "\x1B[31m"
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
	INVALID_SAVE_FILE = 2,
	INVALID_MOVE = 3
};

int string_to_int(char* string);
void print_grid(Game* game);
bool commandline_check_valid(int arg, char** args);
void error_print(int errorCode);
void create_grid(Game* game);
Game* set_game_values(int arg, char** args);
void remove_newline_trail(char* string);
char* get_move(Game* game);
bool is_number(char* string);
// bool is_number(char string);
int seperate_space(char* string, bool firstHalf);
bool has_space(char* string);
void play_game(Game* game);
// void valid_coordinates_check(char* string);
bool valid_coordinates_check(char* set, Game* game);
void add_coordinates_to_grid(Game* game, int x, int y);
void change_turn(Game* game);

void red_print(char* message);
void yellow_print(char* message);

#endif
