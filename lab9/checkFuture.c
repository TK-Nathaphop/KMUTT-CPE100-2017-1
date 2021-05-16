/******************************************************************************
 *  checkFuture.c
 *
 *      This program loop ask user for input date. Validate date is correct or
 *      not. If correct, check that date is in the future or in the past and
 *      print the results.
 *   
 *      Created by Nathaphop Sundarabhogin ID 3420
 *          23 October 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dateFunctions.h"
#define LENGTH 64

/* Get string of date that user input and address of date in integer from main.
 * Then validate it's valid or not. If not, print not valid message. If valid,
 * check the date is in the future, past or today and print the result.
 */ 
void checkResult(char dateInput[LENGTH], int dateInt[3])
    {
    int result = 0;      /* Result after checking. */
    int today[3] = {0};  /* The date today. [0] - day, [1] - month, [2] - year */
    printf("%s is ",dateInput);
    /* Check that date input is valid or not. */
    result = checkDate(dateInput, &dateInt[0], &dateInt[1],
                       &dateInt[2]);
    /* If it is not valid, Print error message to user. */
    if (result == ERR_BADYEAR)
        printf("not a valid year.\nYear must be between 1900 to 2100.\n");
    else if (result == ERR_BADMONTH)
        printf("not a valid month.\nMonth must be between 1-12.\n");
    else if (result == ERR_BADDAY)
        printf("not a valid day.\nDay is outside of possible range for month.\n");
    else if (result == ERR_BADFORMAT)
        printf("not a valid format.\nDate is not in form of dd/mm/yyyy.\n");
    /* Otherwise date input is valid. */
    else
        {
        /* Get the date today. */
        dateToday(&today[0], &today[1], &today[2]);
        /* Compare between the date today and date that user input to know that
         * is in the future, past or today.
         */
        result = dateCompare(today[0], today[1], today[2], dateInt[0],
                             dateInt[1], dateInt[2]);
        /* Print the result. */
        if (result < 0)
            printf("in the future.\n");
        else if (result > 0)
            printf("in the past.\n");
        else if (result == 0)
            printf("today.\n");
        }
    return;
    }

/* THIS IS MAIN FUNCTION. Loop ask user for input date, send input to check and
 * print the result. If use input 'BYE' stop checking and print the summary.
 */
int main()
    {
    char input[LENGTH] = {0};      /* Get input from user */
    char dateInput[LENGTH] = {0};  /* Date input from user in string */
    int dateInt[3] = {0};          /* Date input from user in integer */
                                   /* [0] - day, [1] - month, [2] - year */
    int i = 0;                     /* Count loop */
    /* Display head program. */
    printf("===== Check date is in the future or in the past =====\n");
    printf("Please input date in form dd/mm/yyyy\n");
    /* Loop ask input and check. */
    for(i = 0; 1 ; i++)
        {
        printf("Date %d (Input 'BYE' to stop): ", i+1);
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s", dateInput);
        /* If user input 'BYE' stop checking. */
        if(strcmp("BYE",dateInput) == 0)
            {
            printf("\n");
            break;
            }
        /* Send date that user input and address of date integer to check
         * and print result in checkResult function.
         */
        checkResult(dateInput, dateInt);
        printf("\n");
        }
    /* When out of loop, print summary. */
    printf("You checked %d dates\n",i);
    printf("Good Bye!\n");
    exit(0);
    }