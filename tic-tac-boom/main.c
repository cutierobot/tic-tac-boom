#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    Game* game;
    //TODO: check if right or wrong;
    return 0;
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
//TODO: @add to main.h file (98)
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
    if (/*don't have to sets of numbers*/) {
        return false;
    }
    if (/* check if valid coordinates */) {
        return false;
    }
    return true;

}
//TODO: [write] function definition (99)
//TODO: @add to main.h file (98)
//TODO: create func valid_coordinates_check
bool valid_coordinates_check(char* string) {
    
}
//TODO: @add to main.h file (98)
//TODO: [write] function definition (99)
void print_grid(Game* game) {
    for (int i = 0; i < game.; ++i) {
        printf(" %c | %c | %c \n", grid[i][0], grid[i][1], grid[i][2]);
        if (i != 2) {
            printf("___|___|___\n");
        } else {
            printf("   |   |   \n");
        }
    }
}

bool commandline_check_valid(int arg, char* args) {
    if (arg != 4) {
        // ./tic-tac-boom m m 3
        return false;
    }
    if (args[1] != 'm' || args[1] != 'a') {
        return false;
    } 
    if (args[2] != 'm' || args[2] != 'a') {
        return false;
    }
    

}