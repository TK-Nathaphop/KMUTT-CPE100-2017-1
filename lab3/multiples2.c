/* multiples2.c
 *
 *      This program is used to check which number are evenly divisible.
 *      Ask the user for divisor, quantity of numbers and dividend.
 *      Either dividend is evenly divisible by divisor or not evenly divisible,
 *      Program will tell you and ask for numbers again. Program will stop
 *      when user enters number completely.
 *
 *          Created by Nathaphop Sundarabhogin ID 3420
 *          1 September 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
    {
    int i = 0;                              /*Count how many number are evenly divisible*/
    int quantitynum = 0;           /*Quantity of number that user want to know*/
    int divisor = 0;                    /*Keep divisor number*/
    int dividend = 0;                 /*Keep dividend number*/
    char inputvalue[128];          /*Get input from the user*/

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

    /*Prevent the user input quantity of number less than or equal 0*/
    while (quantitynum <= 0)
        {
        printf("How many values? ");
        fgets(inputvalue, sizeof(inputvalue), stdin);
        sscanf(inputvalue,"%d",&quantitynum);
        if(quantitynum<= 0)
            {
            printf("Illegal value!\n");
            }
        }

    /*Ask the user for dividend number and print the answer to the user.*/
    for ( ; quantitynum>0 ; quantitynum--)
        {
        printf("Value to check : ");
        fgets(inputvalue, sizeof(inputvalue), stdin);
        sscanf(inputvalue,"%d",&dividend);
        if (((dividend % divisor) == 0) && (dividend != -1))
            {
            printf("%d is evenly divisible by %d\n\n",dividend ,divisor);
            i++;
            }
        else if (((dividend % divisor) != 0) && (dividend != -1))
            {
            printf("%d is NOT evenly divisible by %d\n\n",dividend ,divisor);
            }
        }

    /*Conclusion for results*/
    printf("You entered %d values that were multiples of %d.\n",i ,divisor);
    printf("Goodbye!\n");
    exit(0);
    }
