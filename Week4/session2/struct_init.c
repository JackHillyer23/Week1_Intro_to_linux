#include <stdio.h>
struct student {
    char name[20];
    char student_id[11];
    unsigned mark;
};

int main(){
    struct student new_student = {"Name Surname", "2489349979",35};
    printf("Student name: %s\n",new_student.name);
    printf("Student Id: %s\n",new_student.student_id);
    printf("Final mark: %u\n",new_student.mark);
    return 0;
}