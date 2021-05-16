/******************************************************************************
 * testline.c
 *
 *    Ask user for file name. Read file and check that the first letter of each
 *    line is digit, upper case, or lower and write the line to each output file
 *    (numbers.out, upper.out, lower.out). Otherwise, skip that line. If open 
 *    file doesn't succeed, print error message and exit the program.
 *
 *		Nathaphop Sundarabhogin ID 60070503420
 *		30 October 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LENGTH 257

/* Get line that read from input file and address of 3 output files from main
 * function. Check the first letter of line it is number, upper case or lower
 * case (Otherwise, just skip that line). Then write that line in each file.
 */
void checkAndWrite(char line[], FILE *pNumbers, FILE *pUpper, FILE *pLower)
	{
	/* If first letter is number, write it in 'pNumber' */
	if(isdigit(line[0]))
		fprintf(pNumbers, "%s", line);
	/* If first letter is upper case, write it in 'pUpper' */
	else if(isupper(line[0]))
		fprintf(pUpper, "%s", line);
	/* If first letter is lower case, write it in 'pLower' */
	else if(islower(line[0]))
		fprintf(pLower, "%s", line);
	return;
	}

/* Get address all of output files. Use open command to open all of them. while
 * open check that it succeed or not. If not print error message and exit.
 */
void openFilesOutput(FILE **pNumbers , FILE **pUpper, FILE **pLower)
	{
	*pNumbers = fopen("numbers.out","w");
	if(pNumbers == NULL) /* If 'pNumber' can't open, print error message and exit. */
		{
		printf("Error, program can't open numbers.out.\n");
		exit(0);
		}
	*pUpper = fopen("upper.out","w");
	if(pUpper == NULL) /* If 'pUpper' can't open, print error message and exit. */
		{
		printf("Error, program can't open upper.out.\n");
		exit(0);
		}
	*pLower = fopen("lower.out","w");
	if(pLower == NULL) /* If 'pLower' can't open, print error message and exit. */
		{
		printf("Error, program can't open lower.out.\n");
		exit(0);
		}
	return;
	}

/* Get address of all files. Used close command to close all of them. While Close
 * each file, check that it succeed or not. If not, print error message.
 */
void closeAllFiles(FILE **pFileInput, FILE **pNumbers , FILE **pUpper, FILE **pLower)
	{
	int status = 1;	/* Get return of fclose command */
	/*All of state if below, is check that all file can close or not */
	status = fclose(*pFileInput);
	if(status != 0)
		printf("Error, program can't close file that user input.\n");
	status = fclose(*pNumbers);
	if(status != 0)
		printf("Error, program can't close numbers.out.\n");
	status = fclose(*pUpper);
	if(status != 0)
		printf("Error, program can't close upper.out.\n");
	status = fclose(*pLower);
	if(status != 0)
		printf("Error, program can't close lower.out.\n");
	return;
	}

/* Main function. Ask user for input file name. Open input file and 3 output
 * files in another function. Read file that user input then send to check
 * what is the first letter in line and write it in each output file. In the
 * end close all files in another function.
 */
int main()
	{
	FILE *pFileInput = NULL;	/* Input file that user want to check */
	FILE *pNumbers = NULL;		/* Output file for 'numbers.out' */
	FILE *pUpper = NULL;		/* Output file for 'upper.out' */
	FILE *pLower = NULL;		/* Output file for 'lower.out' */
	char input[100] = {0};		/* Get input from user */
	char file[100] ={0};		/* File name that user input */
	char line[LENGTH] = {0};	/* Keep line after reading file */
	/* Ask user for input file */
	printf("Please input file name : ");
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%s",file);
	/* Open files that user input. If not succeed, print error message and exit. */
	pFileInput = fopen(file,"r");
	if(pFileInput == NULL)
		{
		printf("Error, program can't open file that user input.\n");
		exit(0);
		}
	/* Call function that open output files. While open check that it fail or not. */
	openFilesOutput(&pNumbers, &pUpper, &pLower);
	/* Read each line in file then send to check and write it in each output file. */
	while(fgets(line, sizeof(line), pFileInput) != NULL)
		{
		printf("Program Read - '%s'",line);
		checkAndWrite(line, pNumbers, pUpper, pLower);
		}
	/* Close all files that open. While close check that it succeed or not. */
	closeAllFiles(&pFileInput, &pNumbers, &pUpper, &pLower);
	/* Display ending messsage */
	printf("\n\nFinished checking %s.\n", file);
	printf("The output files are 'numbers.out', 'upper.out' and 'lower.out'.\n");
	printf("GOOD BYE!\n");
	exit(0);
	}