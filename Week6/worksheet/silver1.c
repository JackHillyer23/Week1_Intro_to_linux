#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int array[4][5];
    int i, j;

    // Seed the random number generator
    srand(time(NULL));

    // Assign random values to each element of the array
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 5; j++) {
            array[i][j] = rand() % 26;
        }
    }

    float total = 0;
    for(i = 0; i < 4; i++) {
        float average = 0;
        for(j = 0; j < 5; j++) {
            average += array[i][j];
            total += array[i][j];
        }
        printf("Student %d averaged %.2f on the 5 tasks\n", i+1, average/5);
    }
    printf("All the Students averaged %.2f on all 5 tasks\n", total/4/5);

    return 0;
}