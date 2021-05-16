/* multiples.c
 *
 *      This program is used to check which number are evenly divisible
 *      Ask the user for divisor and dividend. Either dividend number is evenly
 *      divisible by divisor or not, Program will tell you and ask for dividend again.
 *      Program will stop when user enters '-1'
 *
 *          Created by Nathaphop Sundarabhogin ID 3420
 *          1 September 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
    {
    int i = 0;                               /*Count how many number are evenly divisible*/
    int divisor = 0;                      /*Keep divisor number*/
    int dividend = 0;                   /*Keep dividend number*/
    char inputvalue[128];            /*Get input from the user*/

    /*Ask the user for divisor number.*/
    while ((divisor <= 0) || (divisor >= 10))
        {
        printf("Check for multiples of what number (greater 0 than and less than 10)? ");
        fgets(inputvalue, sizeof(inputvalue), stdin);
        sscanf(inputvalue,"%d",&divisor);
        if((divisor <= 0) || (divisor >= 10))
            {
            printf("Illegal value!\n");
            }
        }

    /*Loop ask the user for dividend number*/
    while (dividend != -1)
        {
        printf("Value to check (-1 to stop) : ");
        fgets(inputvalue, sizeof(inputvalue), stdin);
        sscanf(inputvalue,"%d",&dividend);

	/*Print the answer to the user and made a condition for ended program.*/
        if (((dividend % divisor) == 0) && (dividend != -1))
            {
            printf("%d is evenly divisible by %d\n\n",dividend ,divisor);
            i++;
            }
        else if (((dividend % divisor) != 0) && (dividend != -1))
            {
            printf("%d is NOT evenly divisible by %d\n\n",dividend ,divisor);
            }
        else if (dividend == -1)
            {
            printf("You entered %d values that were multiples of %d.\n",i ,divisor);
            printf("Goodbye!\n");
            exit(0);
            }
        }
    }
