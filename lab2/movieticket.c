/* movieticket.c
 *
 *	Calculates the price of movie a ticket.
 *	Ask the user for row number and then print the ticket price
 *
 *	Created by Nathaphop Sundarabhogin ID 3024
 *	25th August 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
	{
	char inputvalue[64];		/*get input from the terminal*/	
	int RowNumber=0;			/*Row number of customer's seat*/
	
	/*Ask customer for row number*/
	printf("There are 25 rows of seats in the theater.\n");
	printf("Which row of seat do you want to buy?\n");
	printf("Row Number : ");
	fgets(inputvalue, sizeof(inputvalue), stdin);
	sscanf(inputvalue,"%d",&RowNumber);
	
	/*Print price of ticket to customer*/
	if ((RowNumber>=1) && (RowNumber<=5))
		{
		printf("\nThe price of a movie ticket row number %d is 200 Baht\n", RowNumber);
		}
	else if ((RowNumber>=6) && (RowNumber<=15))
		{
		printf("\nThe price of a movie ticket row number %d is 150 Baht\n", RowNumber);
		}
	else if ((RowNumber>=16) && (RowNumber<=25))
		{
		printf("\nThe price of a movie ticket row number %d is 100 Baht\n", RowNumber);
		}
	else
		{
		printf("\n??? (error)\n");
		}
	exit(0);
	}
