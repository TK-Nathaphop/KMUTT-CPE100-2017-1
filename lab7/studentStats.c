/******************************************************************************
 *	studentStats.c
 *
 *		This program used to calculate stats of quiz grade. Program ask how
 *		many quizzes from user, name, and quizzes grade. Then print the average
 *		grade and standard deviation.
 *
 *		Created by Nathaphop Sundaradbhogin ID 3420
 *			08 October 2017
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXLENGTH 128
#define MAXSCORE 80

/* Calculate the mean (average) and standard deviation.
 * Return the calculated average grades in the address pointed to by 'pAverage'.
 * Return the standard deviation as the function value.
 */
double calculateStats(int grades[], int count, double *pAverage)
	{
	int i = 0;			/* Count loop for calculate */
	double sum = 0;		/* Summation of grades */
	double SD = 0;		/* Standard deviation of student score */
	/* Find average grades */
	for(i = 0; i<count; i++)
		sum = sum + grades[i];
	*pAverage = sum / count;
	/* Find standard deviation */
	for(i = 0; i<count; i++)
		SD = SD + pow((grades[i] - *pAverage),2);
	SD = sqrt(SD/(count - 1));
	return SD;
	}

/* Get 'count' quiz grade for the student with the name 'name' from main.
 * Ask user to input grades and stored in grades array.
 * Then send grades, count, address of 'average' to calculate stats.
 * And print the result to user.
 */
void getQuizGrades(int grades[], char name[], int count)
	{
	char input[MAXLENGTH];	/* Get input from user */
	double SD = 0;			/* Standard deviation of student score */
	double average;			/* Keep average grade */
	int i = 0;				/* Count loop for ask quiz */
	/* Loop ask grades */
	for(i = 0; i < count; i++)
		{
		printf("Quiz grade %d for %s: ",(i+1) ,name);
		fgets(input, sizeof(input), stdin);
		sscanf(input, "%d", &grades[i]);
		}
	/* Print the result */
	SD = calculateStats(grades, count, &average);
	printf("\n%s's average grade is %.2lf\n",name ,average);
	printf("The standard deviation is %.4lf\n\n",SD);
	}

/* MAIN FUNCTION
 * Ask how many quizzes in course and name from user then send to ask
 * quiz grades. If user input DONE program, program stops.
 */
int main()
	{
	char input[MAXLENGTH];		/* Get input from user */
	char nameInput[MAXLENGTH];	/* Name of student */
	int countStudent = 0;		/* Count how many student */
	int quizCount = 0;			/* Get how many quiz in course */
	int grades[MAXSCORE];	 	/* Score of each student */
	/* Ask how many quizzes from user */
	printf("How many quizzes in the course (max is 10)? ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%d", &quizCount);
	/* Check that user input more than 10 or not */
	if(quizCount <= 10)
		while(strcmp(nameInput,"DONE"))
		{
		countStudent++;  /* Count how many student input */
		printf("Enter name of student %d: ", countStudent);	/* Ask name of student */
		fgets(input, sizeof(input), stdin);
		sscanf(input, "%s", nameInput);
		if(strcmp(nameInput, "DONE") == 0)	/* If user input done, the program end */
			{
			printf("Goodbye!\n");
			exit(0);
			}
		getQuizGrades(grades, nameInput, quizCount);
		}
	/* If user input more than 10 or less than 0, program print ERROR and stops */
	else if((quizCount > 10) || (quizCount <= 0)) 
		printf("This program can't calculate more than 10 quizzes or less than 0");
	}