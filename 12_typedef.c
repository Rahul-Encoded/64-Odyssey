#include<stdio.h>

/*
struct student
{
    char name[25];
    int rank;
    float cgpa;
}
*/

typedef struct 
{
    char name[25];
    int rank;
    float cgpa;
} student;

int main()
{   
    //typedef is a reserved keyword that gives aan existing datatype a "nickname"

/*
    struct student student1 = {"Rahul", 1, 9.6};
    struct student student2 = {"Shreya", 17, 8.6};
    struct student student3 = {"Preeti", 9.2, 8};
*/

    student student1 =  {"Rahul", 1, 9.6};
    student student2 = {"Shreya", 17, 8.6};
    student student3 = {"Preeti", 9.2, 8};

    printf("Name of the student : %s\n", student1.name);
    printf("Rank of the student : %d\n", student1.rank);
    printf("CGPA of the student : %f\n", student1.cgpa);

    printf("Name of the student : %s\n", student2.name);
    printf("Rank of the student : %d\n", student2.rank);
    printf("CGPA of the student : %f\n", student2.cgpa);

    printf("Name of the student : %s\n", student3.name);
    printf("Rank of the student : %d\n", student3.rank);
    printf("CGPA of the student : %f\n", student3.cgpa);

    return 0;
}