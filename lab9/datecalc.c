/* datecalc.c
 *   
 *  Ask the user for two dates. When we get two well-formed dates
 *  calculate and display the difference between them in days.
 *
 *   Created by Sally E. Goldin on 29 August 2008
 *   Updated 13 October 2017 to use new functions without structs
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dateFunctions.h"

/* Translate the code returned from checkDate into an
 * informative error message 
 */
void displayDateError(int status);

int main(int argc, char* argv[])
{
  int day1;
  int month1;
  int year1;
  int day2;
  int month2;
  int year2;
  long difference = 0;
  char input[32];
  char date[32];
  int bGoodDate = 0;

  /* example of using dateToday */
  dateToday(&day1,&month1,&year1);
  printf("Welcome! Today's date is %02d/%02d/%d\n\n",
	 day1,month1,year1);

  /* Get the first date */
  while (!bGoodDate)
    {
    memset(date,0,sizeof(date)); 
    printf("Enter first date in form dd/mm/yyyy: ");
    fgets(input,32,stdin);
    sscanf(input,"%s",date);
    if (strlen(date) > 0)
      {
      DATE_STATUS status = checkDate(date,&day1,&month1,&year1);
      if (status == DATE_OK)
	{
	bGoodDate = 1;
	} 
      else
	{
	displayDateError(status);
	}
      }
    } 

    bGoodDate = 0;
    /* Get the second date */
    while (!bGoodDate)
      {
      memset(date,0,sizeof(date)); 
      printf("Enter second date in form dd/mm/yyyy: ");
      fgets(input,32,stdin);
      sscanf(input,"%s",date);
      if (strlen(date) > 0)
	{
	DATE_STATUS status = checkDate(date,&day2,&month2,&year2);
	if (status == DATE_OK)
	  {
	  bGoodDate = 1;
	  } 
	else
	  {
	  displayDateError(status);
	  }
	}
      } 
    difference = dateDifference(day1,month1,year1,day2,month2,year2);
    printf("Dates %02d/%02d/%d and %02d/%02d/%d are %ld days apart\n",
	   day1, month1, year1,
	   day2, month2, year2, difference);

}


/* Translate the code returned from checkDate into an
 * informative error message 
 */
void displayDateError(int status)
{
  switch(status)
    {
    case ERR_BADYEAR:
      printf("   >> Invalid date - year must be between 1900 and 2100 inclusive\n");
      break;
    case ERR_BADMONTH: 
      printf("   >> Invalid date - month must be between 1 and 12 inclusive\n");
      break;
    case ERR_BADDAY:
      printf("   >> Invalid date - exceeds the number of days in month\n");
      break;
    case ERR_BADFORMAT: 
      printf("   >>Invalid date - format must be DD/MM/YYYY with leading zeroes if day or month is less than 10.\n");
      break;
    default:
	  printf("   >> Invalid date - unknown error\n");
    }
} 
