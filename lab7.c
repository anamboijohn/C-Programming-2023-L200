#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define DELAY 10
void printString(char *string, int number, int star);
void printDesign(int number, char *character);
char grade(float score);

int main()
{
    int numberOfStudents;
    float totalMarks = 0;
    printString("Enter the number of studnets in the class: ", DELAY, 0);
    scanf("%d", &numberOfStudents);
    float marks[numberOfStudents];
    printString("Start entering their marks\n", DELAY, 0);
    printDesign(28, "_");

    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("Student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("Student %d: %.2f\n", i + 1, marks[i]);
        totalMarks += marks[i];
    }
    printf("Mean mark of the students is: %.2f\n", totalMarks / numberOfStudents);

    float temp = 0;
    for (int i = 0; i <= numberOfStudents; ++i)
    {
        for (int j = i + 1; j < numberOfStudents; ++j)
        {
            if (marks[i] > marks[j])
            {
                // switch positions
                temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }
    printString("The contents of the sorted array are:[ ", DELAY, 0);
    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("%.2f, ", marks[i]);
    }
    printf("]\n");
    printDesign(40 + numberOfStudents, "_");

    float studentResults[7][2] = {
        {3, 57.45},
        {2, 69.29},
        {2, 71.32},
        {4, 65.05},
        {3, 75.67},
        {3, 48.65},
        {1, 88.21},
    };


    printString("MULTI DIMENTIONAL ARRAY", DELAY, 0);
    printf("\nCREDIT\t|SCORE\t|GRADE\t|\n");
    printf("\t|\t|\t|\n");
    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            printf("%.2f \t|", studentResults[i][j]);
            if (j % 2 == 1)
            {
                printf("%c \t|", grade(studentResults[i][j]));
                printf("\n\t|\t|\t|");
            }
        }
        printf("\n");
    }
    return 0;
}

char grade(float score)
{
    if (score >= 70)
        return 'A';
    else if (score >= 60)
        return 'B';
    else if (score >= 50)
        return 'C';
    else if (score >= 40)
        return 'D';
    else if (score >= 30)
        return 'E';
    else
        return 'F';
}

void printString(char *string, int number, int star)
{
    if (star != 0)
        printDesign(50, "*");
    for (int i = 0; i < (int)strlen(string); i++)
    {
        printf("%c", string[i]);
        Sleep(number);
    }
    if (star != 0)
        printDesign(50, "*");
}

void printDesign(int number, char *character)
{
    for (int i = 0; i < number; i++)
    {
        printf("%s", character);
        Sleep(DELAY);
    }

    printf("\n");
}