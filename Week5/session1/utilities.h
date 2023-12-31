#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// declaring this value so I can use it in different places
#define buffer_size 100

/**
 * @brief Struct to hold each daily reading, contains the date as a string
 *        and the bloodIron as a floating point number.
 *
 */
typedef struct
{
    char date[20];
    float bloodIron;
} reading;

/**
 * @brief Adapted version of the tokeniseRecord function which you should now be familiar with - this one is adapted for this data file
 *        as it has fewer outputs and gives you the bloodIron as a float
 *
 * @param input the line of the file to be split
 * @param delimiter what character it should split on
 * @param date the place where the date will be stored
 * @param bloodIron the place where the bloodIron will be stored.
 */
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, float *bloodIron)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        // turns the blood iron into a float - similar to atoi().
        // we have to tell C that bloodIron is a pointer so it stores it.
        *bloodIron = atof(token);
    }

    // Free the duplicated string
    free(inputCopy);
}

// SUGGESTED FUNCTIONS

/**
 * @brief Opens the file in the correct mode
 *
 * @param filename the name of the file to open
 * @param mode the mode (r/w/a/r+/w+/a+)
 * @return FILE* The file object to store the opened file in.
 */
FILE *open_file(char *filename, char *mode)
{
    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: File could not be opened\n");
        return NULL;
    }
    return input;
}

/**
 * @brief Reads the data from the input file into an array of structs
 *
 * @param inputFile the open file object
 * @param dataArray the array of readings
 * @return int Returns the number of readings from the file
 */

int read_file(FILE *inputFile, reading *dataArray, int counter)
{
    // to do
}

/**
 * @brief Checks that there was data for each part of each reading in the file
 *
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return int Return 0 if there are no errors, 1 if you find an error.
 */
int data_checker(reading *dataArray, int numReadings)
{
    // to do
}


/**
 * @brief Calculates and returns the mean of the readings in the array
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return float The mean of the readings.
 */
float find_mean(reading* dataArray, int numReadings)
{
    float total = 0;
    for (int i=0; i<numReadings; i++){
        total += dataArray[i].bloodIron;
    } 
    return (total/numReadings);
}

/**
 * @brief Finds and returns the highest blood iron reading
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return float The highest blood iron reading
 */
float find_highest(reading* dataArray, int numReadings)
{
    float max = 0;
    for (int i=0; i<numReadings; i++){
        if (max < dataArray[i].bloodIron){
            max = dataArray[i].bloodIron;
        }
        
    } 
    return (max);
}

/**
 * @brief Finds and returns the lowest blood iron reading
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return float The lowest blood iron reading
 */
float find_lowest(reading* dataArray, int numReadings)
{
    float min = dataArray[0].bloodIron;
    for (int i=1; i<numReadings; i++){
        if (min > dataArray[i].bloodIron){
            min = dataArray[i].bloodIron;
        }
        
    } 
    return (min);
}


/**
 * @brief Ask the user for the month to find, and then print out all readings containing that month.
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 */
void monthly_iron(reading* dataArray, int numReadings, char month [4])
{
    for (int i=1; i<numReadings; i++){
        if (strstr(dataArray[i].date, month) != NULL){
            printf("%s - Blood iron: %.1f\n", dataArray[i].date, dataArray[i].bloodIron);
        }
        
    } 
}
int records = 0;
float sqrTotal = 0;
float normalTotal = 0;
float finalTotal = 0;
float standardDeviation (reading* dataArray, int numReadings){
    for (int i=0; i<numReadings; i++){
        sqrTotal += pow(dataArray[i].bloodIron, 2);
        normalTotal += dataArray[i].bloodIron;
        records += 1;
    }
    sqrTotal = sqrTotal/records;
    normalTotal = normalTotal/records;
    normalTotal = pow(normalTotal, 2);
    finalTotal = sqrt(sqrTotal-normalTotal);
    return finalTotal;
}

// bubble sort for median
// int tempArray[400];
// int temp;
// int arrayValues(reading* dataArray, int numReadings){
//     for (int i=0; i<numReadings; i++){
//         tempArray[i]= dataArray[i]. bloodIron;
//     }    
//     return tempArray;
// }

// // Swap function 
// void swap(int tempArray, int i, int j) 
// { 
//     temp = tempArray[i]; 
//     tempArray[i] = tempArray[j]; 
//     tempArray[j] = temp; 
// } 
  
// // A function to implement bubble sort 
// int bubbleSort(int tempArray, int n) 
// { 
//     int i, j; 
//     for (i = 0; i < n - 1; i++) 
  
//         // Last i elements are already 
//         // in place 
//         for (j = 0; j < n - i - 1; j++) 
//             if (tempArray[j] > tempArray[j + 1]) 
//                 swap(tempArray, j, j + 1); 
//     return tempArray;
// } 

// float median(int tempArray, int numReadings){
//     tempArray = arrayValues(tempArray);
//     tempArray = bubbleSort(tempArray);
//     if (numReadings%2 = 0){
//         return tempArray[numReadings/2];
//     }
//     return tempArray [(numReadings+1)/2];
// }

int cmpfunc (const void * a, const void * b) {
   return ( *(float*)a - *(float*)b );
}
float medianCalc(float *tempArray, int numReadings){
    qsort(tempArray, numReadings, sizeof(float), cmpfunc);
    for (int i=0; i<numReadings; i++){
    }
    if (numReadings%2 == 0){
        return tempArray[numReadings/2];
    }
    return tempArray [(numReadings+1)/2];
}