/* shopping.c
 *
 *      This program is used to calculate price of item that you shopping.
 *      Ask user for item quantity and price of each item.
 *      Then print total of price and vat to the user.
 *
 *            Created by Nathaphop Sundarabhogin ID 3420
 *            8th August 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXITEM 20

int main()
    {
    int quantity = 0;             /*Item quantity*/
    double price[MAXITEM];        /*Price of each item*/
    double vat = 0;               /*VAT price*/
    double totalvat = 0;          /*Total of VAT price*/
    double total = 0;             /*Price total*/
    int i = 1;                    /*Use for loop*/
    char input[64];               /*Get input from user*/

    /*Ask user for how many items */
    printf("How many items they have in their shopping basket? ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &quantity);

    /*Check item quantity*/
    if(quantity > MAXITEM)
        {
        printf("This program can't handle this many items\n");
        exit(0);
        }

    else if(quantity <= MAXITEM)
        {
        printf("==Enter the price of item==\n");
        for(i = 0 ; i <= (quantity-1) ; i++)      /*Ask user for item price*/
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
                vat = price[i] * 0.07;
                printf("%.2lf\t %.2lf\t  %.2lf\n", price[i], vat, (price[i]+vat));
                totalvat = totalvat + vat;
                }
            }
        printf("-------\t-------\t----------\n");
        printf("%.2lf\t %.2lf\t  %.2lf\n", total, totalvat, (total+totalvat));
        }
    exit(0);
    }
