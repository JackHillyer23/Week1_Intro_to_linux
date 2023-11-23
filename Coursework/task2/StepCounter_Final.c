#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


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
    printf("Menu Options:\n")
    printf("A: Specify the filename to be imported\n");                       
    printf("B: Display the total number of records in the file\n");                    
    printf("C: Find the date and time of the timeslot with the fewest steps\n");                     
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");                   
    printf("E: Find the mean step count of all the records in the file\n");       
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");        
    printf("Q: Quit\n");
    printf("Enter Choice: ")

    choice = getchar();

    while (getchar() != '\n');


    // switch statement to control the menu.
    switch (choice)
    {
    case 'A':
    case 'a':
        for (int i = 0; i < counter; i++)
        {
            printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
        }
        break;

    case 'B':
    case 'b':
        mean = find_mean(daily_readings, counter);
        printf("Your average blood iron was %.2f\n", mean);
        break;

    case 'C':
    case 'c':
        min = find_lowest(daily_readings, counter);
        printf("Your lowest level of blood iron was %.2f\n", min);
        break;

    case 'D':
    case 'd':
        max = find_highest(daily_readings, counter);
        printf("Your highest level of blood iron was %.2f\n", max);
        break;

    case 'E':
    case 'e':
        printf("Please enter the month you wish to look at (in the form JAN, FEB etc): ");
        scanf("%s", month);
        monthly_iron(daily_readings, counter, month);
        break;

    case 'F':
    case 'f':
        max = find_highest(daily_readings, counter);
        min = find_lowest(daily_readings, counter);
        range = max - min;
        printf("The range of you blood iron levels is: %.2f\n", range);
        SD = standardDeviation(daily_readings, counter);
        printf("The standard deviation of you blood iron levels is: %f\n", SD);
        for (int i=0; i<counter; i++){
            tempArray[i]= daily_readings[i]. bloodIron;
        }
        
        median = medianCalc(tempArray, counter);
        printf("The median of you blood iron levels is: %f\n", median);
        return 0;
        break;

    case 'Q':
    case 'q':
        return 0;
        break;

    // if they type anything else:
    default:
        printf("Invalid choice\n");
        break;
    }
}








