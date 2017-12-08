#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
        /*printf("---=====");
        for (int i = 0; i < 8; ++i) {
            printf("\b");
        }
        printf("*--=====\n");*/
    char grid[3][3] = {
        {' ', 'X', ' '},
        {'O', 'X', 'O'},
        {'X', ' ', 'O'}};
    // print top half with grid
    for (int i = 0; i < 3; ++i) {
        printf(" %c | %c | %c \n", grid[i][0], grid[i][1], grid[i][2]);
        if (i != 2) {
            printf("___|___|___\n");
        } else {
            printf("   |   |   \n");
        }
        
    }
        return 0;
}
