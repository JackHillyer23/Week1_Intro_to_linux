#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename [] = "squares.dat";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];
    float total = 0;
    int count = 0;
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        total = total + atoi(line_buffer);
        count ++;
    }
    float average = total/count;
    printf("The average in the file is %f\n",average);
    

    fclose(file);
    return 0;
}