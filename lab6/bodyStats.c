/*
 * bodyStats.c
 *
 *      This program ask user for weight and height and then show in the
 *      table weight - height.
 *
 *          Created by Nathaphop Sundarabhogin ID 3420
 *          22 September 2017
*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define BINCOUNT 10
#define WEIGHTBIN 10
#define HEIGHTBIN 20

/* Ask for the weight from user. Keep asking until
 * get the weight less than 99.Then return that value.
 */
int getWeight(int countPeople)
    {
    int weight = 0;        /*Used for keep weight from user*/
    char input[128];      /*Get input from user*/
    printf("Enter weight for person %d in kilos (max is 99): ", countPeople);
    fgets(input , sizeof(input) , stdin);
    sscanf(input , "%d\n" , &weight);
    /*Prevent user input wrong value*/
    while(weight > 99)
        {
        printf("Enter weight for person %d in kilos (max is 99): ", countPeople);
        fgets(input , sizeof(input) , stdin);
        sscanf(input , "%d\n" , &weight);
        }
    return weight;
    }

/* Ask for the height from user. Keep asking until
 * get the less than height 199 and more than 0.
 * Then return that value.
 */
int getHeight(int countPeople)
    {
    int height = 0;        /*Used to keep height from user*/
    char input[128];      /*Get input from user*/
    printf("Enter height for person %d in cm (max is 199): ", countPeople);
    fgets(input , sizeof(input) , stdin);
    sscanf(input , "%d" , &height);
     /*Prevent user input wrong value*/
    while((height > 199) || (height < 0))
        {
        printf("Enter height for person %d in cm (max is 199): ", countPeople);
        fgets(input , sizeof(input) , stdin);
        sscanf(input , "%d" , &height);
        }
    printf("\n");
    return height;
    }

/* Get the value from main and then print the table
 * show to the user.
*/
void printTable(int countsBin[BINCOUNT][BINCOUNT])
    {
    int i = 0, j = 0 ;                      /*Used for count loop*/
    /*Print head of table*/
    printf("\t\t\t\t\t\tHeight\n");
    printf("\t\t0-\t20-\t40-\t60-\t80-\t100-\t120-\t140-\t160-\t180-\n");
    printf("\t\t19 cm\t39 cm\t59 cm\t79 cm\t89 cm\t119 cm\t139 cm\t159 cm\t179 cm\t199 cm\n");
    for(i = 0 ;  i<=9 ; i++)
        {
        /*Print left side of table*/
        printf(" %d- %d kg", (i*10), (((i+1)*10)-1));
        /*Print value in each row and column*/
        for(j = 0 ; j<=9 ; j++)
            {
            /*If value is 0, turn it to ---*/
            if(countsBin[i][j] == 0)
                {
                printf("\t---");
                }
            else
                {
                printf("\t%d",countsBin[i][j]);
                }
            }
        printf("\n");
        }
    exit(0);
    }

/*Main function includes loop to get value from user
 * and then send value to print table
*/
int main()
    {
    int countsBin[BINCOUNT][BINCOUNT] = {0};    /*Count for bin of weight and height*/
    int weight = 0;                             /*Used for get weight from user*/
    int height = 0;                             /*Used for get height from user*/
    int countPeople = 0;                        /*Count how many people from user*/

    printf("Welcome to the bodyStats!\n");
    printf("    This program prints a 10 x 10 table\n");
    printf("    showing the relationship between weight and height\n\n");
    /*Loop for get weight and height from another function then calculate and keep it in to countsBin*/
    for(countPeople = 0 ; weight>=0 ; countPeople++)
        {
        weight = getWeight(countPeople+1);
        if(weight>=0) /*If weight less than 0, then program will not ask height and not keep value to countsBin*/
            {
            height = getHeight(countPeople+1);
            countsBin[(weight / WEIGHTBIN)][(height / HEIGHTBIN)]++;
            }
        }

    printf("\nRecieved data for %d people\n\n", (countPeople-1));
    printTable(countsBin); /*Send value to the function printTable*/
    }
