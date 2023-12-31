#include "utilities.h"

int main()
{
    // array of daily readings
    reading daily_readings[100];

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice;
    int counter = 0;
    float mean = 0;
    float min = 0;
    float max = 0;
    char month[4];
    float range = 0;
    float SD = 0;
    float median = 0;
    float tempArray[400];

    while (1)
    {
        FILE *input = open_file(filename, "r");
        counter = 0;
        while (fgets(line, buffer_size, input))
        {
            // split up the line and store it in the right place
            // using the & operator to pass in a pointer to the bloodIron so it stores it
            tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
            counter++;
        }
        fclose(input);

        printf("A: View all your blood iron levels\n");                       // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your lowest blood iron level\n");                     // SILVER
        printf("D: View your highest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');


        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
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

        case 'G':
        case 'g':
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
}