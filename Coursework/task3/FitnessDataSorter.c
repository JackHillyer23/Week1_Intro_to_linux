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
    //global variables
    int counter = 0;
    int buffer_size = 100;
    char line[buffer_size];
    char filename[buffer_size];
    char delimiter = ',';
    
    //Retieving input of a file from the user
    printf("Enter Filename: ");
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

    FitnessData stepsArray[counter]; // initialises array

    input = fopen(filename, "r");
    int i = 0;
    while (fgets(line, buffer_size, input)) // This nested section of code tokenises and ensures data is of a valid format
    {
        strcpy(stepsArray[i].date, "");
        strcpy(stepsArray[i].time, "");
        stepsArray[i].steps = 0;
        tokeniseRecord(line, ',', stepsArray[i].date, stepsArray[i].time, &stepsArray[i].steps);
        if (stepsArray[i].date == "" || stepsArray[i].time == "" || stepsArray[i].steps == 0){
            printf("Invalid data in file.\n");
            return 1;
        }
        i++;
    }


    fclose(input);

    //Bubble sort in descending order
    FitnessData temp[1];
    for (int i = 0; i<counter; i++){
        for(int j = 0; j<counter-1; j++){
            if (stepsArray[j].steps<stepsArray[j+1].steps){
                temp[0] = stepsArray[j];
                stepsArray[j]= stepsArray[j+1];
                stepsArray[j+1] = temp[0];
            }
        }
    }
    char *newFile = filename;
    char *fileEnding = ".tsv";
    
    FILE *output = fopen(strcat(newFile, fileEnding), "w");//Opening the new file in write mode with concantenated filename and .tsv
    for (int i = 0; i<counter; i++){
        fprintf(output,"%s\t%s\t%d\n",stepsArray[i].date, stepsArray[i].time, stepsArray[i].steps);
    }
    printf("Data sorted and written to %s\n", newFile);
    return 0;
}