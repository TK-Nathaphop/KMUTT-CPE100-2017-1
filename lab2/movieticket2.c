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
	switch (RowNumber)
		{
		case 1 :
		case 2 :
		case 3 :
		case 4 :
		case 5 :
			printf("\nThe price of a movie ticket row number %d is 200 Baht\n", RowNumber);
			break;
		case 6 :
		case 7 :
		case 8 :
		case 9 :
		case 10 :
		case 11 :
		case 12 :
		case 13 :
		case 14 :
		case 15 :
			printf("\nThe price of a movie ticket row number %d is 150 Baht\n", RowNumber);
			break;
		case 16 :
		case 17 :
		case 18 :
		case 19 :
		case 20 :
		case 21 :
		case 22 :
		case 23 :
		case 24 :
		case 25 :
			printf("\nThe price of a movie ticket row number %d is 100 Baht\n", RowNumber);
			break;
		default:
			printf("\n??? (error)\n");
			break;		
		}
	exit(0);
	}
