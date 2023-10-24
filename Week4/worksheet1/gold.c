#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename [] = "numbers.dat";
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
        total = total + atof(line_buffer);
        count ++;
    }
    float average = total/count;
    

    fclose(file);

    
    file = fopen (filename, "a"); // or a , w+, a+, r, r+
    if (file == NULL){
        perror("");
        return 1;
    }
   
    fprintf(file, "%f\n", average);
    
        

    fclose(file);

    return 0;
}