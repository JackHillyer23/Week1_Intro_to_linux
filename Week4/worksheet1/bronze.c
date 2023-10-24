#include <stdio.h>

int main()
{

    char filename [] = "squares.dat";
    FILE *file = fopen (filename, "w"); // or a , w+, a+, r, r+
    if (file == NULL){
        perror("");
        return 1;
    }
    int number;
    printf("What is the final squared number to write to the file: ");
    scanf("%d", &number);
    for (int i = 1; i < number+1; i++){
        int square = i*i;
        fprintf(file, "%d\n", square);
    }
        

    fclose(file);

    return 0;
}