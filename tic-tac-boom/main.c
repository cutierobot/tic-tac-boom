#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"

int main(int argc, char** argv) {
    Game* game;
    //TODO: check if right or wrong;
    if (!commandline_check_valid(argc, argv)) {
        error_print(INVALID_ARGS);
    }
    return 0;
}



//TODO: change equations so that it can increase number after each turn
Game* set_game_values(int arg, char** args) {
    Game* game = malloc(sizeof(*game));
    // struct Hub* hub = malloc(sizeof(*hub));
    game->gridSize = string_to_int(args[3]);
    game->turn = (game->gridSize % 2  == 0) ? 'x' : 'o';
    /*if gridsize is even x goes first else o goes first*/
    game->explodeX = false;
    game->explodeO = false;
    game->xAuto = (strcmp(args[1], "m") == 0) ? false : true;
    game->oAuto = (strcmp(args[2], "m") == 0) ? false : true;
    game->xMoveCount = 0;
    game->oMoveCount = 0;
    //TODO: add grid setup malloc thingo
    /*
    char** grid;
    */
}


/**
 * Checks to see if the string entered by the player is to explode a players
 * previously entered marker.
 * @param  string the string that the human player entered
 * @return[Bool]    true if string is to explode, false otherwise
 */
//TODO: @add to main.h file (98)
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

//TODO: @add to main.h file (98)
//TODO: [write] function definition (99)
bool valid_explode(char* string) {
    if (strstr(string, "boom") == NULL) {
        return false;
    }
    //TODO: check don't have to sets of numbers
    //TODO: check if valid coordinates
    return true;

}
//TODO: [write] function definition (99)
//TODO: @add to main.h file (98)
//TODO: create func valid_coordinates_check
bool valid_coordinates_check(char* string) {
    return true;
}

//TODO: [write] function definition (99)
void print_grid(Game* game) {
    for (int i = 0; i < game->gridSize; ++i) {
        printf(" %c | %c | %c \n", game->grid[i][0], game->grid[i][1], 
                game->grid[i][2]);
        if (i != 2) {
            printf("___|___|___\n");
        } else {
            printf("   |   |   \n");
        }
    }
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
        
    }
}
