/******************************************************************************
 *  readwrite.c
 *
 *      Read all the data from binary file 'students.dat' and print the information for
 *      each student on the screen. Then write all the data to 'newstudents.dat'
 *
 *          Created by Nathaphop Sundarabhogin ID 3420
 *          10 November 2017
 */
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#define MAX 100

/* Get argument from main function.
 * **pFileOpen - Address of file that want to open.
 * fileName - Get file name that want to open.
 * select - Select for write file or read file. (1 - Read Binary file, 2 - Write Binary file).
 * Open file that want to open. If open not succeed, print error and exit program.
 */
void openFile(char fileName[], int select, FILE **pFileOpen)
    {
    /* If 'select' is 1, it means open for read binary file */
    if(select == 1)
        *pFileOpen = fopen(fileName, "rb"); 
    /* If 'select' is 2, it means open for write binary file */
    else if(select == 2)
        *pFileOpen = fopen(fileName, "wb");
    /* If open file not succeed, print error and exit. */
    if(*pFileOpen == NULL) 
    {
    printf("Can't open '%s'. Program exit.\n", fileName);
    exit(0);
    }
    return; /* Go back to main function */
    }

/* **pFileClose - Address of file that want to close.
 * fileName - Get file name to print to the screen when error.
 * Close file. If close file not succeed print error to let user know that.
 */
void closeFile(FILE **pFileClose, char fileName[])
    {
    int status = 1;   /* Get status from close file */
    status = fclose(*pFileClose);
    if(status != 0) /* If status not equal to 0, it means close file not succeed */
        printf("Have some problem when closing %s file!\n", fileName);
    return; /* Go back to main function */
    }

/* Get one structure of STUDENT_T and display data to user */
void displayStudent(STUDENT_T oneStudent, int count)
    {
    printf("Student No: %d\n", count+1);
    printf("Student name: %s\n", oneStudent.name);
    printf("Age: %d\n", oneStudent.age);
    printf("Gender: %c\n", oneStudent.gender);
    printf("Quiz 1: %d\n", oneStudent.quizGrades[0]);
    printf("Quiz 2: %d\n", oneStudent.quizGrades[1]);
    printf("Quiz 3: %d\n", oneStudent.quizGrades[2]);
    printf("Quiz 4: %d\n", oneStudent.quizGrades[3]);
    printf("Quiz 5: %d\n", oneStudent.quizGrades[4]);
    printf("GPA: %lf\n\n", oneStudent.gpa);
    }
int main()
    {
    FILE *pStudentsInput;                       /* File pointer to 'students.dat', if it open */
    STUDENT_T students[MAX];   /* Declare structure of array to get data */
    int i = 0;                                           /* Used for count loop */
    int status = 0;                                   /* Check status when close file */
    /* Open 'students.dat' for read binary file */
    openFile("newstudents.dat", 1, &pStudentsInput);
    /* Loop for check each data, print data and write it in output file. */
    while(1)
        {
        if (fread(&students[i], sizeof(STUDENT_T), 1, pStudentsInput) != 1)
            break;
        displayStudent(students[i], i);
        i++;
        }
    closeFile(&pStudentsInput, "newstudents.dat");  /* Close 'students.dat' file */
    }