
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H


#include <stdio.h>

#define buffer_size 100



// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes

FILE *open_file(char *filename, char *mode)
{
    FILE *input = fopen(filename, "r");
    if (!input)
    {
        return NULL;
    }
    return input;
}

void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

#endif // FITNESS_DATA_STRUCT_H

int find_lowest(FITNESS_DATA* dataArray, int numReadings)
{
    int min = dataArray[0].steps;
    int record = 0;
    for (int i=1; i<numReadings; i++){
        if (min > dataArray[i].steps){
            min = dataArray[i].steps;
            record = i;
        }
        
    } 
    return (record);
}


int find_highest(FITNESS_DATA* dataArray, int numReadings)
{
    int max = dataArray[0].steps;
    int record = 0;
    for (int i=1; i<numReadings; i++){
        if (max < dataArray[i].steps){
            max = dataArray[i].steps;
            record = i;
        }
        
    } 
    return (record);
}


int find_mean(FITNESS_DATA* dataArray, int numReadings)
{
    int total = 0;
    for (int i=0; i<numReadings; i++){
        total += dataArray[i].steps;
    } 
    return (total/numReadings);
}

void timeOver(FITNESS_DATA* dataArray, int numReadings)
{
    int start = 0;
    int tempStart = 0;
    int tempEnd = 0;
    int end = 0;
    int total = 0;
    int tempTotal = 0;
    for (int i=0; i<numReadings; i++){
        if (dataArray[i].steps>500){
            tempStart = i;
            for (int j = i; j<numReadings; j++){
                if (dataArray[j].steps>500){
                    tempTotal += 1;
                } else{
                    tempEnd = j-1;
                    if (total<tempTotal){
                        total = tempTotal;
                        start = tempStart;
                        end = tempEnd;
                        break;
                    }else{
                        break;
                    }
                    
                }
            }
        }
    }
    printf("Longest period start: %s %s\n",dataArray[start].date, dataArray[start].time);
    printf("Longest period end: %s %s\n",dataArray[end].date,dataArray[end].time) ;
}