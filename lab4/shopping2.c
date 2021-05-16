/* shopping2.c
 *
 *      This program is used to calculate price of item that you shopping.
 *      Get item quantity and VAT percentage from Terminal line.
 *      Then ask user for price and then print total to the user.
 *
 *            Created by Nathaphop Sundarabhogin ID 3420
 *            8th August 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
    {
    int quantity = 0;        /*Item quantity*/
    double price[argc];      /*Price of each item*/
    double vatpercent = 0;   /*VAT percent*/
    double vat = 0;          /* VAT price*/
    double totalvat = 0;     /*Total of VAT price*/
    double total = 0;        /*Price total*/
    int i = 1;               /*Use for loop*/
    char input[64];          /*Get input from user*/

     /*Check values input from Terminal line*/
    if((argc < 3) || (argc > 3))
        {
        printf("The user didn't provide both the item count and the VAT percentage.\n");
        exit(0);
        }

    /*Transform arguments into variable*/
    sscanf(argv[1], "%d", &quantity);
    sscanf(argv[2], "%lf", &vatpercent);
    if((quantity > 20) || (quantity < 1))    /*Check VAT percentage*/
        {
        printf("Error! Please input quantity of items between 1 - 20\n");
        exit(0);
        }
    else if((vatpercent < 0) || (vatpercent > 10))    /*Check item quantity*/
        {
        printf("Error! Please input VAT percentage between 0 to 10\n");
        exit(0);
        }
    else if((argc = 3) || (quantity<=20) || ((vatpercent > 0) && (vatpercent < 10)))
        {
        /*Ask user for price of each item*/
        printf("==Enter the price of item==\n");
        for(i = 0 ; i <= (quantity-1) ; i++)
            {
             printf("Price of item No.%d : ", i+1);
             fgets(input, sizeof(input), stdin);
             sscanf(input, "%lf Baht", &price[i]);
            }

        /*Print table of total price*/
        printf("\n Price\t  Vat\tItem total\n");
        printf("-------\t-------\t----------\n");
        for(i = 0, vat = 0 ; i <= (quantity-1) ; i++)
            {
            /*Check price of item for VAT.*/
            if(price[i] < 100)
                {
                total = total + price[i];
                printf("%.2lf\t 0.00\t  %.2lf\n", price[i], price[i]);
                }
            else if(price[i] >= 100)
                {
                total = total + price[i];
                vat = (price[i] * vatpercent)/100;
                printf("%.2lf\t %.2lf\t  %.2lf\n", price[i], vat, (price[i]+vat));
                totalvat = totalvat + vat;
                }
            }
        printf("-------\t-------\t----------\n");
        printf("%.2lf\t %.2lf\t  %.2lf\n", total, totalvat, (total+totalvat));
        }
    exit(0);
    }
