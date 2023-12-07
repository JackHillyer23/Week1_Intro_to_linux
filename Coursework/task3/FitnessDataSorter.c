#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {
    int counter = 0;
    int buffer_size = 100;
    char line[buffer_size];
    char filename[buffer_size];
    char delimiter = ',';
    

    printf("Please enter the name of the data file: ");
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);
    FILE *input = fopen(filename, "r");
    if (input == NULL){ //Checking for a valid file
        printf("Error: invalid file\n");
        return 1;
    }
    while (fgets(line, buffer_size, input) != NULL) { // Gets the total number of records of the file
        counter ++;
    }
    fclose(input);

    FitnessData stepsArray[counter];

    input = fopen(filename, "r");
    while (fgets(line, buffer_size, input))
    {
        for (int i=0; i<counter; i++)
            // split up the line and store it in the right place in the steps array
            tokeniseRecord(line, delimiter, stepsArray[i].date, stepsArray[i].time, &stepsArray[i].steps);
    }


    fclose(input);

    FitnessData temp[1];
    for (int i = 0; i<counter; i++){
        for(int j = 0; j<counter-1; j++){
            if (stepsArray[j].steps>stepsArray[j+1].steps){
                temp[0] = stepsArray[j];
                stepsArray[j]= stepsArray[j+1];
                stepsArray[j+1] = temp[0];
            }
        }
    }
    char *newFile = filename;
    char *fileEnding = ".tsv";
    
    FILE *output = fopen(strcat(newFile, fileEnding), "w");
    for (int i = 0; i<counter; i++){
        fprintf(output,"%s\t%s\t%d\n",stepsArray[i].date, stepsArray[i].time, stepsArray[i].steps);
    }

}