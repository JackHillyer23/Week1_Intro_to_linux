#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char choice;
char line[buffer_size];
char filename[buffer_size];
int counter = 0;



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

    //Variables defined for switch cases
    int counter = 0;
    int i = 0;
    int min = 0;
    int max = 0;
    int mean = 0;
    //char stepsChar[10];
    FITNESS_DATA stepsArray[200];
    int completeActions = 0; //loop for ensuring correct flow of data until the program is finished
    while (1){
        

        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");                       
        printf("B: Display the total number of records in the file\n");                    
        printf("C: Find the date and time of the timeslot with the fewest steps\n");                     
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");                   
        printf("E: Find the mean step count of all the records in the file\n");       
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");        
        printf("Q: Quit\n");
        printf("Enter Choice: ");

        choice = getchar();

        while (getchar() != '\n');


        // switch statement to control the menu.
        switch (choice)
        {
        case 'A':
        case 'a':

            // get filename from user
            printf("Please enter the name of the data file: ");
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", filename);
            FILE *input = open_file(filename, "r");
            if (input == NULL){ //Checking for a valid file
                printf("Error: Could not find or open the file.\n");
                return 1;
            }
            while (fgets(line, buffer_size, input) != NULL) { // Gets the total number of records of the file
                counter ++;
            }
            fclose(input);

            input = open_file(filename, "r");
            int i = 0;
            while (fgets(line, buffer_size, input))
            {
                // split up the line and store it in the right place in the steps array
                char stepsChar[10];
                tokeniseRecord(line, ",", stepsArray[i].date, stepsArray[i].time, stepsChar);
                stepsArray[i].steps= atoi(stepsChar);
                i++;
            }

        
            fclose(input);
            printf("File successfully loaded.\n");
            completeActions += 1;
            break;

        case 'B':
        case 'b':
            if (completeActions < 1){ //ensures file has been inputted
                printf("No file has been inputted yet\n");
                break;
            } else{
                printf("Total records: %d\n",counter); // Returns number of records
                break;
            }
            

        case 'C':
        case 'c':
            if (completeActions < 1){//ensures file has been inputted
                printf("No file has been inputted yet\n");
                break;
            } else{
                min = find_lowest(stepsArray, counter);
                printf("Fewest steps: %s %s\n", stepsArray[min].date, stepsArray[min].time); //returns date and time of fewest steps 
                break;
            }

        case 'D':
        case 'd':
            if (completeActions < 1){//ensures file has been inputted
                printf("No file has been inputted yet\n");
                break;
            } else{
                max = find_highest(stepsArray, counter);
                printf("Largest steps: %s %s\n", stepsArray[max].date, stepsArray[max].time);//returns date and time of most steps 
                break;
            }

        case 'E':
        case 'e':
            if (completeActions < 1){//ensures file has been inputted
                printf("No file has been inputted yet\n");
                break;
            } else{
                mean = find_mean(stepsArray, counter);
                printf("Mean step count: %d\n", mean);//returns mean steps in the file 
                break;
            }

        case 'F':
        case 'f':
            if (completeActions < 1){//ensures file has been inputted
                printf("No file has been inputted yet\n");
                break;
            } else{
                timeOver(stepsArray, counter);
                break;
            }
            

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice. Try again.\n");
            break; 
        } 
    }
}












