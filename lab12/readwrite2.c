/******************************************************************************
 *  readwrite2.c
 *
 *      Get file name from terminal line. First read amount of student then read
 *      data from file and print what program read to terminal line. After reading
 *      write the amount and data into new file.
 *
 *          Created by Nathaphop Sundarabhogin ID 3420
 *          21 November 2017
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

/* Get argument from main function.
 * fileName - Get file name that want to open.
 * typeAccess - Get type of access file to open.
 * Open file that want to open. If open not succeed, print error and exit program.
 */
FILE *openFile(char fileName[], char *typeAccess)
    {
    FILE *pFileOpen = NULL;     /* Get address after open file */
    pFileOpen = fopen(fileName, typeAccess); 
    if(pFileOpen == NULL) /* If file doesn't open print error and exit */
        {
        printf("Can't open '%s'. Program exit.\n", fileName);
        exit(0);
        }
    return pFileOpen; /* Return address of file */
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

/* MAIN FUNCTION. Open input file, read amount of data and all of data in file
 * then keep in allocate structure. After get all data, loop print each data 
 * and write it to new binary file.
 */
int main(int argc,char *argv[])
    {
    FILE *pInput = NULL;           /* File pointer to input file, if it open */
    FILE *pOutput = NULL;          /* File pointer to output file, if it open */
    STUDENT_T *students = NULL;    /* Declare pointer of structure to allocate */
    char inFileName[64] = {0};     /* Keep file name from terminal line */
    char outFileName[64] = {0};    /* Keep file name from terminal line */
    int i = 0;                     /* Used for count loop */
    int count = 0;                 /* Get count from read file */
    if(argc != 2)  /* If user doesn't input file name, print error and exit */
        {
        printf("Please input file name after run program");
        exit(0);
        }
    /* Copy input filename from terminal line to string in program */
    strcpy(inFileName, argv[1]);
    /* Open input file and allocate memory for read file. */
    pInput = openFile(inFileName, "rb");
    fread(&count, sizeof(int), 1, pInput);
    students = calloc(count,sizeof(STUDENT_T));
    if (students == NULL) /* This condition for allocate error */
        {
        printf("Error: Program can't allocate memory.\n");
        exit(0);
        }
    fread(students, sizeof(STUDENT_T), count, pInput);
    closeFile(&pInput, inFileName);
    for(i = 0; i<count ;i++) /* Loop print data */
        displayStudent(students[i], i);
    /* Write new binary output file */
    sprintf(outFileName,"new%s",inFileName);
    pOutput = openFile(outFileName, "wb");
    fwrite(&count, sizeof(int), 1, pOutput);
    fwrite(students, sizeof(STUDENT_T), i, pOutput);
    closeFile(&pInput, outFileName);
    free(students);
    printf("Output file: %s\n",outFileName);
    printf("Good bye!\n");
    exit(0);
    }
