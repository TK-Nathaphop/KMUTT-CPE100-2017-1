/******************************************************************************
 * dataTest.c
 *
 *      Get input filename and output filename from terminal. Read data in file into an
 *      array of structures. After reading all information, write into a new file.
 *          Created by Nathaphop Sundarabhogin ID 3420
 *          3rd November 2017
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ghostBuster.h"
#define MAX 30

int readFile (FILE *pRead, EVENT_T data[])
    {
    int i = 0;              /* Count loop */
    char input[300];     /* Get input from file */
    /* Loop for read each line in file and keep it in each structure array.
     * Program will read only first 10 line.
     */
    for(i = 0; (fgets(input, sizeof(input), pRead) != NULL) && (i < MAX); i++)
        {
        printf("Program Read : %s", input);
        /* Keep data in structure */
        sscanf(input, "%d-%d-%d %d:%d %d-%d-%d %d:%d %s %s %s %s %f %f %d %d %d",
            &data[i].dateEvent.day, &data[i].dateEvent.month,
            &data[i].dateEvent.year, &data[i].dateEvent.hour,
            &data[i].dateEvent.minute, &data[i].dateInvest.day,
            &data[i].dateInvest.month, &data[i].dateInvest.year, 
            &data[i].dateInvest.hour, &data[i].dateInvest.minute,
            data[i].phoneReport,data[i].typeEvent,data[i].nameReport,
            data[i].nameInvest,&data[i].latitude,&data[i].longitude,
            &data[i].eventCode[0], &data[i].eventCode[1],&data[i].result);
        }
    return i; /* Return count of stars */
    }

/* Close file that user want to closed and check that close file
 * succed or not. If close file not succeed, print error message.
 * Arguments: pFileClose - Address of file that want to close.
 */
void closeF(FILE **pFileClose)
    {
    int status = 1;   /* Get status from close file */
    status = fclose(*pFileClose);
    if (status != 0) /* If status not equal to 0, it means close file not succeed */
        printf("#ERROR: Have some problem when closing data file!\n");
    *pFileClose == NULL;
    return; /* Go back to main function */
    }

/* Open file that want to open and check open succeed or not. If open
 * not succeed, print error message.
 * Arguments : fileName - Get file name that want to open.
 *             access - type of access that want to use
 */
FILE *openF(char fileName[], char *accessType)
    {
    FILE *pFileOpen = NULL;
    pFileOpen = fopen(fileName, accessType); 
    /* If open file not succeed, print error message. */
    if (pFileOpen == NULL) 
        printf("#ERROR: Unable to open data file.\n");
    return pFileOpen; /* Go back to main function */
    }

/* This is MAIN function. Get input and output filenames from terminal line.
 * Open input file, then read each line and keep it into structure. Close input file
 * Open output file, then write from structure into output file. Close output file
 */
int main (int argc, char* argv[])
    {
    EVENT_T data[MAX];               /* Declare array structure */
    FILE *pFile = NULL;              /* File that open */
    char inputFileName[64] = {0};    /* Input file name from terminal line */
    char outputFileName[64] = {0};   /* Output file name from terminal line */
    int count = 0;                   /* Count how many star in file text */
    int i = 0;                       /* Count loop */
     /* If user doesn't input argument correctly, print error and exit */
    if (argc != 3)
        {
        printf("Please input 'input filename' and 'output filename'");
        printf(" after './dataTest' in terminal line!\n");
        printf("Example : ./dataTest inputFileName.in OutputFileName.out\n");
        exit(0);
        }
    /* Copy input and output filenames from argc into variable in function */
    strcpy(inputFileName, argv[1]);
    strcpy(outputFileName, argv[2]);
    pFile = openF(inputFileName, "r");
    /* Read file and keep in structure then get the count of star back */
    count = readFile(pFile, data);
    closeF(&pFile);      /* Close input file */
    /* Open output file (send 2 to know that it is write file) */
    pFile = openF(outputFileName, "wb+");
    fwrite(&count, sizeof(int), 1, pFile);
    fwrite(data, sizeof(EVENT_T), count, pFile);
    closeF(&pFile); /* Close output file */
    /* Display ending program */
    printf("\nPROGRAM FINISHED!\n");
    printf("Good Bye!\n");
    exit(0);
    }
