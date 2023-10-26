#include <stdio.h>
#include <string.h>

typedef struct {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
} student;

int main () {
    // Data generated using ChatGPT.
    int number_of_students = 10, i;
    student students [number_of_students];

    for (i = 0; i < number_of_students; i++){
        strcpy(students[i].name, "Name Surname");
        strcpy(students[i].student_id, "0000000000");
        students[i].mark = 0;
    }

    for (i = 0; i < number_of_students; i++) {
        printf("-------------\n");
        printf("Student name: %s\n", students[i].name);
        printf("Student ID: %s\n", students[i].student_id);
        printf("Final mark: %u\n", students[i].mark);
    }
    printf("-------------\n");
    return 0;
}