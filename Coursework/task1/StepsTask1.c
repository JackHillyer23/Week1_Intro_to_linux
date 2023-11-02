#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    char filename [] = "FitnessData_2023.csv";  //This section initialises file to read from
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    
    int buffer_size = 100;     // This section counts the amount of rows in the file
    int rows = 0;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        rows ++;
    }
    fclose(file);

    FITNESS_DATA stepsArray [rows];  // This defines the struct and reopens the file 
    file = fopen (filename, "r"); 
    if (file == NULL){
        perror("");
        return 1;
    }

    char date[11];   // I kept finding errors saying the variables in the tokenise function were undeclared so decided to declare them here first
    char time[6];
    char steps[10];
    char line_buffer2[buffer_size];
    for (int i = 0; i < rows; i++) {  // This section loops through the files and splits each line before assinging it to the stepsArray
        fgets(line_buffer2, buffer_size, file);
        tokeniseRecord(line_buffer2, ",", date, time, steps); 
        strcpy(stepsArray[i].date, date);
        strcpy(stepsArray[i].time, time);
        stepsArray[i].steps = atoi(steps);

    }
    fclose(file);

    printf("Number of records in file: %d\n",rows); //Prints out the number of rows in the file
    for (int i = 0; i<3; i++){ //prints out the values in the array in the correct format up to the first 3 values
        printf("%s/%s/%d\n",stepsArray[i].date, stepsArray[i].time, stepsArray[i].steps);
    }

    return 0;
}
