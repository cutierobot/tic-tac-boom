#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "debugHelper.h"
#include "game.h"
#define STRING_LENGTH 80

int main(int argc, char** argv) {
    Game* game;
    //TODO: check if right or wrong;
    if (!commandline_check_valid(argc, argv)) {
        error_print(INVALID_ARGS);
    }
    game = set_game_values(argc, argv);
    // char* string;
    /*char* coords = "32 1";
    string = seperate_space(coords, false);
    printf("coords: '%s'\n", string);*/
    play_game(game);
    return 0;
}

/**
 * Sets up the values for the Game struct for a first time game. Not to be used
 * for a continued game.
 * @param  arg  argc equivilent
 * @param  args argv equivilent
 * @return[Game*]  the filled in Game struct
 */
Game* set_game_values(int arg, char** args) {
    Game* game = malloc(sizeof(*game));
    // struct Hub* hub = malloc(sizeof(*hub));
    game->gridSize = string_to_int(args[3]);
    game->turn = (game->gridSize % 2  == 0) ? 'X' : 'O';
    /*if gridsize is even X goes first else O goes first*/
    game->explodeX = false;
    game->explodeO = false;
    game->xAuto = (strcmp(args[1], "m") == 0) ? false : true;
    game->oAuto = (strcmp(args[2], "m") == 0) ? false : true;
    game->xMoveCount = 0;
    game->oMoveCount = 0;
   create_grid(game);
   return game;
}

//TODO: [write] function definition (99)
void play_game(Game* game) {
    	char* move = (char*)malloc(STRING_LENGTH * sizeof(char));
        int xCoordinates, yCoordinates;
        bool end = false;
        while(end != true) {
           if (game->turn == 'X') {
                printf("X turn\n");
                move = get_move(game);
                xCoordinates = seperate_space(move, true);
                yCoordinates = seperate_space(move, false);
                printf("%d-%d\n", xCoordinates, yCoordinates);
            } else {
                printf("O turn\n");
                // char* move = (char*)malloc(STRING_LENGTH * sizeof(char));
                move = get_move(game);
                xCoordinates = seperate_space(move, true);
                yCoordinates = seperate_space(move, false);
                printf("%d-%d\n", xCoordinates, yCoordinates);
            }
            add_coordinates_to_grid(game, xCoordinates, yCoordinates); 
            change_turn(game);
        }
    
    free(move);
}

/**
 * Sepeperates the coordinates for the game. If firstHalf is true then the 
 * first coordinates is returned, else the second coordiantes is returned. If
 * the given string does not contain any numbers, disregarding the seperating
 * space, -1 will be returned.
 * @param  string    The string with the two coordinates
 * @param  firstHalf[Bool] the coordiante we want
 * @return[String] the coordiante wanted or -1.
 */
int seperate_space(char* string, bool firstHalf) {
	int length = (int)strlen(string);
	char* stringCopy = (char*)malloc(length * sizeof(char));
	int stringLength = 0;
	bool copy = false;
	if (firstHalf) {
		copy = true;
		for (int i = 0; i < length; ++i) {
			if (copy) {
				stringCopy[stringLength++] = string[i];
				if (string[i] == ' ') {
					copy = false;
				}
			} 
		}
		stringLength--; //to get rid of the space that gets appended
		stringCopy[stringLength] = '\0';
	} else {
		for (int i = 0; i < length; ++i) {
			if (copy) {
				stringCopy[stringLength++] = string[i];
			}
			if (string[i] == ' ') {
				copy = true;
			}	
		}	
	}
	stringCopy[stringLength] = '\0';

    if (!is_number(stringCopy)) {
        printf(RED "not number\n" RESET);
        free(stringCopy);
        return -1;
    }
    int number = string_to_int(stringCopy);
    free(stringCopy);
	return number;
}

//TODO: [write] function definition (99)
void add_coordinates_to_grid(Game* game, int x, int y) {
    game->grid[y][x] = game->turn;
    print_grid(game);
}

/**
 * Determins is a string has a space in it. If it has then true is returned, 
 * else false is returned.
 * @param  string the string to check for a space.
 * @return[Bool] returns true if there is a space, false otherwise.
 */
bool has_space(char* string) {
	int length = (int)strlen(string);
	for (int i = 0; i < length; ++i) {
		if (string[i] == ' ') {
			return true;
		}
	}
	return false;
}

//NOTE: malloc returned value
/**
 * Gets the move entered in by a manual player. Checks to see if the move 
 * entered in is a number. If move doesn't contain numbers, excluding 
 * seperating space, 'invalid' is returned else the move is returned.
 * @param  game The Game struct for this particular game.
 * @return      'invalid' or the move  string
 */
char* get_move(Game* game) {
	printf("move: ");
    char* move = (char*)malloc(80 * sizeof(char));
    if (fgets(move, 80, stdin) != NULL) {
    	remove_newline_trail(move);
        
        if (!valid_coordinates_check(move, game)) {
            error_print(INVALID_MOVE);
        }
    	return move;
    } else {
    	error_print(INVALID_MOVE);
    }
}

//TODO: [write] function definition (99)
bool is_number(char* string) {
    char* needle = "1234567890";
    // char* ret;
    // ret = strstr(string, needle);
    // //TODO: change t value to something meaningful
    int t = 0;
    t = strspn(string, needle);
    // ret = strstr(string, needle);
    int length = (int)strlen(string);
    // if (ret == NULL) {
    if (t != length) {
        return false;
    } else {
        return true;
    }
}
/*bool is_number(char string) {
	char* needle = "1234567890";
	char* ret;
    ret = strchr(needle, string);
	if (ret == NULL) {
		return false;
	} else {
		return true;
	}
}*/

/**
 * When using fgets, this function will take that string and remove the trailing
 * newline after the string.
 */
void remove_newline_trail(char* string) {
    int length;
    length = strcspn(string, "\n");
    string[length] = '\0';
}

/**
 * Creates the grid for the game struct. makes a inital print of the gmae grid.
 * @param game the game struct
 */
void create_grid(Game* game) {
    game->grid = malloc(sizeof(char*) * (game->gridSize * 2));
    for (int i = 0; i < game->gridSize; ++i) {
	game->grid[i] = (char*)malloc(game->gridSize * 2);
    }
    for (int rowCount = 0; rowCount < game->gridSize; ++rowCount) {
    	for (int columnCount = 0; columnCount < game->gridSize; ++columnCount) {
    	    game->grid[rowCount][columnCount] = ' ';
    	}
    }
    print_grid(game);
}


/**
 * Checks to see if the string entered by the player is to explode a players
 * previously entered marker.
 * @param  string the string that the human player entered
 * @return[Bool]    true if string is to explode, false otherwise
 */
//TODO: @add to game.h file (98)
bool explode_check(char* string) {
    if (strstr(string, "boom") != NULL) {
        return true;
    }
    return false;
}

/**
 * Takes a string and changes it to a intenger. This is done by the ASCII table
 *  and chars.
 * @return[Int] The string as a intenger.
 */
int string_to_int(char* string) {
    int number = 0;
    // for coor_to_int as stupidly it adds a space at ends some times
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == ' ') {
            string[i] = '\0';
        }
    }
    // ends here
    for (int i = 0; i < strlen(string); ++i) {
        number = number * 10 + (string[i] - '0');
    }
    return number;
}

//TODO: @add to game.h file (98)
//TODO: [write] function definition (99)
bool valid_explode(char* string) {
    if (strstr(string, "boom") == NULL) {
        return false;
    }
    //TODO: check don't have to sets of numbers
    //TODO: check if valid coordinates
    return true;

}

/**
 * Changes the turn of the player. If current player is 'X' this function
 * changes it to 'O'.
 * @param game the Game struct for this current session
 */
void change_turn(Game* game) {
    if (game->turn == 'O') {
        game->turn = 'X';
    } else {
        game->turn = 'O';
    }
}

/**
 * Determins if the given coordinates are valid. A valid coordinate set is 
 * defined as having a X and Y coordinate that is only numbers and within the 
 * board bounds. False is returned for any coordinate set that doesn't meet
 * this criteria.   
 * @param  set the coordinate set
 * @return [Bool] true if valid, false otherwise
 */
bool valid_coordinates_check(char* set, Game* game) {
    int moveLength = (int)strlen(set);
    bool twoDigits = false;
    int xCheck = 0;
    int yCheck = 0;
    for (int i = 0; i < moveLength; ++i) {
        if (set[i] == ' ') {
            twoDigits = true;
        }
    }

    if (!twoDigits) {
        return false;
    }

    if (!has_space(set)) {
        return false;
    }
    xCheck = seperate_space(set, true);
    yCheck = seperate_space(set, false);
    //make sure the coordinates are numbers
    if (xCheck == -1 || yCheck == -1) {
        return false;
    }

    if (xCheck >= game->gridSize || yCheck >= game->gridSize) {
        return false;
    }

    //TODO: check that the given coordiantes are withing the board bounds
    return true;
}

/**
 * Prints out the grid to stdout
 * @param game The game struct containing the game grid
 */
void print_grid(Game* game) {
    for (int i = 0; i < game->gridSize; ++i) {
        for (int j = 0; j < game->gridSize-1; ++j) {
            printf(" %c |", game->grid[i][j]);
        }
        printf("\n");
        if (i != game->gridSize-1) {
            for (int k = 0; k < game->gridSize-1; ++k) {
                printf("___|");
            }
            printf("___\n");
        }
    }
    for (int l = 0; l < game->gridSize-1; ++l) {
        printf("   |");
    }
    printf("\n");
}

//TODO: [write] function definition (99)
bool commandline_check_valid(int arg, char** args) {
    if (arg != 4) {
        // ./tic-tac-boom m m 3
        return false;
    }
    if ((int)strlen(args[1]) != 1) {
        return false;
    }
    // printf("%c\n", args[1][0]);
    if ((strcmp(args[1], "m") != 0) && (strcmp(args[1], "a") != 0)) {
        return false;
    }
    /*if (args[1] != "m" || args[1] != "a") {
        printf("gghgh\n");
        return false;
    } */
    if ((strcmp(args[2], "m") != 0) && (strcmp(args[2], "a") != 0)) {
        return false;
    }
    int size = string_to_int(args[3]);
    if (size < 3) {
        return false;
    }
    return true;

}

/**
 * Prints out the error descriptions to stderr.
 * @param errorCode number that is associated with a specific error type.
 */
void error_print(int errorCode) {
    switch (errorCode) {
        case INVALID_ARGS:
            fprintf(stderr, "./tic-tac-boom ply1Type ply2Type gridSize\n");
            exit(INVALID_ARGS);
            break;
        case INVALID_MOVE:
        	fprintf(stderr, "invalid move\n");
        	exit(INVALID_MOVE);
        	break;
    }
}





void red_print(char* message) {
    printf(RED "%s\n" RESET, message);
}

void yellow_print(char* message) {
    printf(YELLOW "%s\n" RESET, message);
}

