#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int array[2][3][4];
    int i, j, k;

    // Seed the random number generator
    srand(time(NULL));

    // Assign random values to each element of the array
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            for(k = 0; k < 4; k++) {
                array[i][j][k] = (rand() % 31)+70;
            }
        }
    }

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            for(k = 0; k < 4; k++) {
                printf("%d, ",array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    

    return 0;
    }