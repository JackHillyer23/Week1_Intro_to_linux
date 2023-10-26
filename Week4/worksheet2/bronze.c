#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} point;

int main () {
    // Data generated using ChatGPT.
    int number_of_points = 10, i;
    point array1 [number_of_points];

    for (i = 0; i < number_of_points; i++){
        array1[i].x = rand();
        array1[i].y = rand();
    }

    for (i = 0; i < number_of_points; i++) {
        printf("-------------\n");
        printf("x value: %.2f\n", array1[i].x);
        printf("y value: %.2f\n", array1[i].y);
    }
    printf("-------------\n");
    return 0;
}