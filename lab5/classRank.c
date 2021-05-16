/* classRank.c
 *
 *      This program used to check student grades which is the highest or lowest
 *      Ask user to enter a list of student name and student grades, then find and print
 *      the highest and lowest grades.
 *
 *          Created by Nathaphop Sundarabhogin ID 3420
 *          15 August 2017
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAME 20
#define MAXLEN 32
#define MAXGRADE 20

int main()
    {
    char input[128];                            /*Get input from user*/
    char name[MAXNAME][MAXLEN]; /*Keep name from user*/
    int grade[MAXGRADE];                  /*Keep grade from user*/
    int maxstudent = 0;                      /*Keep the max student*/
    int ehigh = 0;                               /*Keep element of the highest grade student*/
    int elow = 0;                                /*Keep element of the lowest grade student*/
    int i = 0;                                      /*Used for loop*/
    
    /*Ask user for how many student*/
    printf("How many students in the class (max is 20)?  ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &maxstudent);

    if (maxstudent > 20) /*Check if student more than 20*/
        {
        printf("Sorry, this program can handle no more than 20 students.\n");
        exit(0);
        }
    else if (maxstudent < 0) /*Check if student less than 0*/
        {
        printf("Sorry, this program can't check negative students.\n");
        exit(0);
        }
    else
        {
        for(i = 0; i < maxstudent ; i++)
            {
            /*Ask user for name of student*/
            printf("Name for student %d? ", (i + 1));
            fgets(input , sizeof(input), stdin);
            sscanf(input , "%s", name[i]);

            /*Loop for Check name from user (If less than 2 characters, program will ask for name again)*/
            while(strlen(name[i]) < 2)
                {
                printf("Please enter at least 2 letters.\n");
                printf("Name for student %d? ", (i + 1));
                fgets(input , sizeof(input), stdin);
                sscanf(input , "%s", name[i]);
                }

            /*Ask user for grade of student*/
            printf("Grade for student %d? ", (i + 1));
            fgets(input, sizeof(input), stdin);
            sscanf(input, "%d", &grade[i]);

            /*Loop for Check grade from user (If not between 0-100, program will ask for grade again)*/
            while((grade[i] < 0) || (grade[i] > 100))
                {
                printf("Please enter grade between 0 to 100.\n");
                printf("Grade for student %d? ", (i + 1));
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%d", &grade[i]);
                }

            /*Compare 2 grades which is the highest grade and lowest grade*/
            if(grade[i] >= grade[ehigh])
                {
                ehigh = i;
                }
            if(grade[i] <= grade[elow])
                {
                elow = i;
                }
            } /*Exit from loop ask*/

        /*Print the highest grade and the loweset grade*/
        printf("\n%s had the highest grade in the class (%d)",name[ehigh],grade[ehigh]);
        printf("\n%s had the lowest grade in the class (%d)\n",name[elow],grade[elow]);
        exit(0);
        }
    }
