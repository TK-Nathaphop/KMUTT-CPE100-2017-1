/* Calculate a student's grade.
 * Ask the user for quizzes, midterm and final exam scores,
 * then print the results. Quizzes count 25%, midterm 25%,
 * final exam 50%. Final grade is a number, not a letter.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
	{
	char stringInput[128];	/* get input from the terminal */
	int totalScores = 0;	/* sum of quiz scores */
	int quizScore = 0;		/* one quiz score */
	int midScore = 0;		/* midterm exam score */
	int finalScore = 0;		/* final exam score */
	int averageScore = 0;	/* average of quizzes */
	int grade = 0;			/* numeric course grade */
	int quiz;				/* counter for quizzes */

	/* Calculate average of quizzes */
	for (quiz = 1; quiz <= 5; quiz++)
		{
		printf("Enter score for quiz number %d: ", quiz);
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput,"%d",&quizScore);
		totalScores = totalScores + quizScore;
		}
	averageScore = totalScores/5;

	/* Get the midterm exam score */
	printf("Enter midterm exam score: ");
	fgets(stringInput,sizeof(stringInput), stdin);
	sscanf(stringInput,"%d",&midScore);

	/* Get the final exam score */
	printf("Enter final exam score: ");
	fgets(stringInput,sizeof(stringInput), stdin);
	sscanf(stringInput,"%d",&finalScore);

		/* Calculate grade */
	grade = averageScore * 0.25 + midScore * 0.25 + finalScore *0.5;
	printf("Your grade is %d\n", grade);
	if (grade < 60)
		printf("Sorry, you've failed the course.\n");
	else
		printf("Congratulations! You passed the course.\n");
	exit(0);
	}
