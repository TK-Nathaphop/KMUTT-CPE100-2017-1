/******************************************************************************
 *  daranang.c
 *
 *      Get input filename and output filename from terminal. Read data in file into an
 *      array of structures. After reading all information, write into a new file.
 *          Created by Nathaphop Sundarabhogin ID 3420
 *          3rd November 2017
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

typedef struct 
    {
    char firstname[32];     /* First name of star */
    char lastname[32];      /* Last name of star */
    char gender;                /* Gender of star */
    int movieCount;           /* Number of movies */
    int rating;                   /* Popularity rating */
    } MOVIESTAR_T;

/* Get argument from main function 
 * *pRead - File that want to read data
 *  movieStar[] - Address of structure of 'moviestar'
 * Read data from file and keep data in structure.
 */
int readFile (FILE *pRead, MOVIESTAR_T movieStar[])
    {
    int i = 0;              /* Count loop */
    char input[64];     /* Get input from file */
    /* Loop for read each line in file and keep it in each structure array.
     * Program will read only first 10 line.
     */
    for(i = 0; (fgets(input, sizeof(input), pRead) != NULL) && (i < MAX); i++)
        {
        printf("Program Read : %s", input);
        /* Keep data in structure */
        sscanf(input, "%s %s %c %d %d", movieStar[i].firstname, movieStar[i].lastname,
                    &movieStar[i].gender, &movieStar[i].movieCount, &movieStar[i].rating);
        }
    return i; /* Return count of stars */
    }

/* Get argument from main function
 * *pOutput - File that want to write data.
 * moviestar[] - Address of structure of 'moviestar'
 * count - Count of stars
 * Write data from structure into output file.
 */
void writeFile (FILE *pOutput, MOVIESTAR_T movieStar[], int count)
    {
    int i = 0;    /* Count loop */
    /* Count loop to write each structure array into file. */
    for(i = 0; i<count ; i++)
        {
        /* Write into output file in easy to read form */
        fprintf(pOutput, "Movie star #%d\n", i+1);
        fprintf(pOutput, "Name: %s %s\n", movieStar[i].firstname,
                  movieStar[i].lastname);
        fprintf(pOutput, "Gender: %c\n", movieStar[i].gender);
        fprintf(pOutput, "Number of movies: %d\n", movieStar[i].movieCount);
        fprintf(pOutput, "Popularity rating : %d\n", movieStar[i].rating);
        fprintf(pOutput, "\n");
        }
    return; /* Go back to main function */
    }

/* Get argument from main function.
 * **pFileOpen - Address of file that want to open.
 * fileName - Get file name that want to open.
 * select - Select for write file or read file. (1-Read, 2-Write).
 * Open file that want to open. If open not succeed, print error and exit program.
 */
void openFile(FILE **pFileOpen, char fileName[], int select)
    {
    /* If 'select' is 1, it means open for read file */
    if(select == 1)
        {
        *pFileOpen = fopen(fileName, "r"); 
        if(pFileOpen==NULL) /* If open file not succeed, print error and. */
            {
            printf("Can't open 'input file'. Program exit.");
            exit(0);
            }
        }
    /* If 'select' is 2, it means open for write file */
    else if(select == 2)
        {
        *pFileOpen = fopen(fileName, "w");
        if(pFileOpen==NULL) /* If open file not succeed, print error message. */
            {
            printf("Can't open 'output file'. Program exit.");
            exit(0);
            }
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

/* This is MAIN function. Get input and output filenames from terminal line.
 * Open input file, then read each line and keep it into structure. Close input file
 * Open output file, then write from structure into output file. Close output file
 */
int main (int argc, char* argv[])
    {
    MOVIESTAR_T movieStar[MAX];  /* Declare array structure */
    FILE *pInput = NULL;                 /* Input file or file that want to read */
    FILE *pOutput = NULL;               /* Output file or file that want to write */
    char inputFileName[64] = {0};    /* Input file name from terminal line */
    char outputFileName[64] = {0};  /* Output file name from terminal line */
    int count = 0;                              /* Count how many star in file text */
    int i = 0;                                     /* Count loop */
     /* If user doesn't input argument correctly, print error and exit */
    if (argc != 3)
        {
        printf("Please input 'input filename' and 'output filename'");
        printf(" after './daranang' in terminal line!\n");
        printf("Example : ./daranang inputFileName.in OutputFileName.out\n");
        exit(0);
        }
    /* Copy input and output filenames from argc into variable in function */
    strcpy(inputFileName, argv[1]);
    strcpy(outputFileName, argv[2]);
    /* Open input file (send 1 to know that it is read file) */
    openFile(&pInput, inputFileName, 1);
    /* Read file and keep in structure then get the count of star back */
    count = readFile(pInput, movieStar);
    closeFile(&pInput, inputFileName);      /* Close input file */
    /* Open output file (send 2 to know that it is write file) */
    openFile(&pOutput, outputFileName, 2);
    /* Write data from structure to output file */
    writeFile(pOutput, movieStar, count);  
    closeFile(&pOutput, outputFileName); /* Close output file */
    /* Display ending program */
    printf("\nPROGRAM FINISHED!\n");
    printf("Good Bye!\n");
    exit(0);
    }
