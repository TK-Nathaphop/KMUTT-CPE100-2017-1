/*******************************************************************************
 *    validate.c
 *
 *        This program gets the input from users, validate the data and print
 *        'Valid' or 'Not Valid'. In the end of program, print a summary amount
 *        of validations it performed of each typed. 
 *        There are 4 different kinds of validation.
 *        1) Date in form dd MMM yyyy - Western Year) 2) Web URL
 *        3) Thai mobile phone number                 4) Hotel services code.
 *
 *        Created by Nathaphop Sundarabhogin ID 60070503420
 *            28th August 2017
 *
 ******************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLENGTH 100
#define LENGTHDATE 30
#define LENGTHWEB 50
#define LENGTHPHONE 20
#define LENGTHCODE 15
#define MINYEAR 1917
#define MAXYEAR 2117

/* Declare Menu function to switch each option when user input */
int menu();
/* Declare Control functions for control each validate option.
 * Control functions used for loop ask input from user and send value to Validate
 * function for checking.
 */
int controlDate();
int controlWebURL();
int controlphoneNumInput();
int controlHotelServicesCode();

/* Declare Validation functions for checking content and format, Then print valid
 * or invalid message to user. Number in the end of validate function are each of
 * validate option. 1 - Validate Date, 2 - Validate web URL, 3 - Validate Thai mobile
 * phone number, 4 - Validate hotel services code
 */
int validateDay1();
int validateMonth1();
int validateYear1();
void validateDate1();
int validatePrefix2();
int validateURL2();
void validateSuffix2();
int validateNumber3();
void validateThaiPhone3();
int validateLetter4();
void validateDollar4();

/****************************************************************************
 * Main function. Ask user for what kind of validations does user want and then
 * send to menu function to call control functions. 
 */
int main()
    {
    int menuSelect = 0;          /* Switch the validate option */
    int amountValid[4] = {0};    /* Amount of each validation */
    /* [0]-Date, [1]-Web URL, [2]-Thai mobile phone number, [3]-Hotel services code*/
    char input[MAXLENGTH];       /* Text typed input from user */
    while(menuSelect != 5)
        {   
        /* Display a menu and ask the user what user want to do */
        printf("Validation options:\n");
        printf("    1 - Check date in form dd MMM yyyy - Western year\n");
        printf("    2 - Check web URL\n");
        printf("    3 - Check Thai mobile phone number\n");
        printf("    4 - Check hotel services code\n");
        printf("    5 - Exit the program\n");
        printf("What do you want to do? ");
        fgets(input, sizeof(input) ,stdin);
        sscanf(input, "%d", &menuSelect);
        printf("\n");
        /* Send what user want to do to menu function */
        menuSelect = menu(amountValid,menuSelect);
        }
    }

/****************************************************************************
 * Menu function. Get menu option that user want to validate from main function.
 * then call Control function that user want to validate. In the end print summary
 * amount of validation it performed of each typed.
 */
int menu(int amount[], int menu)
    {
    switch (menu)
        {
        case 1: /* Validate date in form dd MMM yyyy - Western year */
            amount[0] = amount[0] + controlDate();
            break;
        case 2: /* Validate Web URL */
            amount[1] = amount[1] + controlWebURL();
            break;
        case 3: /* Validate Thai mobile phone number */
            amount[2] = amount[2] + controlphoneNumInput();
            break;
        case 4: /* Validate Hotel services code. */
            amount[3] = amount[3] + controlHotelServicesCode();
            break;
        case 5: /* Exit Program. Print the summary */
            printf("Program run summary:\n");
            printf("    Validation type 1: %d\n", amount[0]);
            printf("    Validation type 2: %d\n", amount[1]);
            printf("    Validation type 3: %d\n", amount[2]);
            printf("    Validation type 4: %d\n\n", amount[3]);
            printf("Goodbye!\n\n");
            exit(0);
            break;
        default:
            printf("Please enter number 1-5.\n\n");
            break;
        }
        printf("\n");
        return 0;
    }

/******************************************************************************
 * CONTROL VALIDATE DATE.
 * This function loop ask user to input date, get the input into 3 variable of char 
 * ('day','month','year') then send 3 variable to each validate, get 3 values of 
 * integer back and send to check date is correct or not. If input return, this
 * validate date stops.
 */
int controlDate()
    {
    char input[MAXLENGTH] = {0};           /* Text typed input from user */
    char dateInput[4][LENGTHDATE] = {0};   /* Date input from user. */
    int date[3] = {0};                     /* Date in integer from Validate function */
                                           /* [0] - day, [1] - month, [2] - year */
    int countDate = 0;                     /* Count how many validations */
    printf("Validate date in form dd MMM yyyy - Western year (Hit return to stop)\n");
    while(countDate>=0)
        {
        /* Ask user for input */
        printf("Enter date: ");
        fgets(input, sizeof(input), stdin);
        /* If input return, stops validate and return 'countDate'. */
        if (strlen(input) == 1)
            return countDate;
        /* This condition for user doesn't input in form dd MMM yyyy */
        else if(strlen(input) != 12)
            printf("Not Valid - Please input date inform dd MMM yyyy.\n");
        /* Send 3 variables of char to validate. If correct, convert in integer back */
        else if (strlen(input) == 12)
            {
            sscanf(input, "%s %s %s", dateInput[0], dateInput[1], dateInput[2]);
            date[0] = validateDay1(dateInput[0]);
            if (date[0])
                date[1] = validateMonth1(dateInput[1]);
            if (date[1])
                date[2] = validateYear1(dateInput[2]);
            }
        /* If day, month and year is correct, send to validate date. */
        if ((date[0]) && (date[1]) && (date[2]))
            validateDate1(date);
        countDate++;    /* Count how many validation. */
        /* Set all Buffer to 0. */
        memset(date, 0, sizeof(date));
        memset(dateInput, 0, sizeof(dateInput));
        memset(input, 0, sizeof(input));
        }
    }

/*******************************************************************************
 * VALIDATE DAY. (This function is in a part of validate date)
 * Get day in char from Control Validate Date function. Then check day does it is
 * number 2 digits between 1 - 31 or not. If yes, return day in integer back. But
 * if NOT, print 'Not Valid' and return 0.
 */
int validateDay1(char dayStr[LENGTHDATE])
    {
    int i = 0;          /* Count loop and check each char */
    int dayInteger = 0; /* Keep the day in integer */
    /* Check that 2 digits or not */
    if (strlen(dayStr) != 2)
        {
        printf("Not Valid - Please input 2 digits in day.\n");
        return 0;
        }
    /* Check that it's 2 digits between 1 - 31 or not. If yes, convert that number 
     * to integer and return it back.
     */
    else if (isdigit(dayStr[0]) && isdigit(dayStr[1]))
        {
        sscanf(dayStr, "%d", &dayInteger);
        if ((dayInteger >= 1) && (dayInteger <= 31))
            {
            return dayInteger;
            }
        else if ((dayInteger < 1) || (dayInteger > 31))
            {
            printf("Not Valid - Please input day between 1 - 31.\n");
            return 0;
            } 
        }
    /* If user doesn't input number in day, return 0 */
    else if (!isdigit(dayStr[0]) || !isdigit(dayStr[1]))
        {
        printf("Not Valid - Please input number in day.\n");
        return 0;
        }
    }

/*******************************************************************************
 * VALIDATE MONTH. (This function is in a part of validate date)
 * Get month in char from Control Validate Date function. Then check that month
 * is 3 big capital letters of months or not. If yes, return month in integer variable 
 * (Example: FEB return 2). But if NOT, print 'Not Valid' and return 0.
 */
int validateMonth1(char monthStr[LENGTHDATE])
    {
    int i = 0;                 /* Count loop and check each char and month */
    int monthInteger = 0;      /* Keep the month in integer */
    char monthCompare[13][4] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG",
                                "SEP","OCT","NOV","DEC"}; /* Used for check month */
    /* Check that there are 3 letters in month */
    if (strlen(monthStr) != 3)
        {
        printf("Not Valid - Please input 3 letters in month.\n");
        return 0;
        }
    /* Check that month is capital letters */
    for(i = 0; i <= 2; i++)
        {
        if (islower(monthStr[i]))
            {
            printf("Not Valid - Please input capital letters in month.\n");
            return 0;
            }
        }
    /* Check that user input month correct spell or not. If month is correct,
     * return month in integer back (example : FEB return 2 , DEC return 12).
     * But if not, return 0.
     */
    for(i = 0; i <= 12; i++)
        {
        if ((strstr(monthCompare[i], monthStr) != NULL) && (i < 12))
            {
            monthInteger = i+1;
            return monthInteger;
            }
        else if (i == 12) 
            {
            printf("Not Valid - %s is not a month.\n", monthStr);
            return 0;
            }
        }
    }

/*******************************************************************************
 * VALIDATE YEAR. (This function is in a part of validate date)
 * Get year in char from Control Validate Date function. Then check year does it
 * is number 4 digits between 1917 - 2117 or not. If yes, return year in integer.
 * But if NOT, print 'Not Valid' return 0.
 */
int validateYear1(char yearStr[LENGTHDATE])
    {
    int yearInteger = 0;        /* Keep the year in integer */
    /* Check that 4 digits or not. */
    if (strlen(yearStr) != 4)
        {
        printf("Not Valid - Please input 4 digits in year.\n");
        return 0;
        }
    /* Check that number between 1917 - 2117 or not. If yes, convert to integer. */
    else if (isdigit(yearStr[0]) && isdigit(yearStr[1]) && isdigit(yearStr[2])
             && isdigit(yearStr[3]) )
        {
        sscanf(yearStr, "%d", &yearInteger);
        if ((yearInteger >= MINYEAR) && (yearInteger <= MAXYEAR))
            {
            return yearInteger;
            }
        if ((yearInteger < MINYEAR) || (yearInteger > MAXYEAR))
            {
            printf("Not Valid - Please input year between 1917 - 2117.\n");
            return 0;
            }
        }
    else
        {
        printf("Not Valid - Please input number in year.\n");
        return 0;
        }
    }

/*******************************************************************************
 * VALIDATE DATE. (This function is in a part of validate date)
 * Get day, month and year from Control Validate Date function. Check day and month
 * does it relation or not. If correct, print 'Valid'. But if not print 'Not Valid'.
 */
//void validateDate1(int dateCheck[3]) /* [0] - day, [1] - month, [2] - year */
//    {
    /* Check month that have 30 days.*/
/*    if ((dateCheck[1] == 4) || (dateCheck[1] == 6) || (dateCheck[1] == 9)
        || (dateCheck[1] == 11))
        {
        if ((dateCheck[0] >=1) && (dateCheck[0] <= 30))
            printf("Valid\n");
        else 
            printf("Not Valid - Day is not correct. This month have only 30 days.\n");
        }*/
    /* Check February month. First check leap year, and then check days */
//    else if (dateCheck[1] == 2)
//        {
        /* Leap year */
        /*if (((dateCheck[2] % 4) == 0) &&
            ((dateCheck[0] >= 1)&& (dateCheck[0] <= 29)))
            printf("Valid\n");
        else if (((dateCheck[2] % 4) == 0) &&
                 ((dateCheck[0] < 1) || (dateCheck[0] > 29)))
            printf("Not Valid - Day is not corret. This month have only 29 days.\n");*/
        /* Common year */
        /*else if (((dateCheck[2] % 4) != 0) &&
                 ((dateCheck[0] >= 1) && (dateCheck[0] <= 28)))
            printf("Valid\n");
        else if (((dateCheck[2] % 4) != 0) &&
                 ((dateCheck[0] < 1) || (dateCheck[0] > 28)))
            printf("Not Valid - Day is not corret. This month have only 28 days.\n");
        }*/
    /* Check month that have 31 days. */
    /*else
        {
        if ((dateCheck[0] >= 1) && (dateCheck[0] <= 31))
            printf("Valid\n");
        else
            printf("Not Valid - Day is not correct. This month have only 31 days.\n");
        }
    return;
    }*/

/*******************************************************************************
 * CONTROL VALIDATE WEB URL.
 * This function loop ask user to input web URL. Then send web URL to 3 Validate
 * Functions (Prefix, URL name, Suffix). If input only return, this validate stops.
 */
int controlWebURL()
    {
    char input[MAXLENGTH] = {0};     /* Text typed input from user */
    char urlInput[LENGTHWEB] = {0};  /* URL input from user */
    int countURL = 0;                /* Count how many validations */
    int checkURL = 0;                /* Check after send to validate correct or not */
    printf("Validate web URL (Hit return to stop)\n");
    while(countURL>=0)
        {
        /* Ask user for input */
        printf("Enter web URL: ");
        fgets(input, sizeof(input), stdin);
        /* If input return, stop validate and return 'countURL'. */
        if (strlen(input) == 1)
            return countURL;
        sscanf(input, "%s", urlInput);
        /* This condition for input space in web URL */
        if (strlen(input) != (strlen(urlInput) + 1))
            printf("Not Valid - Web URL can't have any space.\n");
        /* Send web URL to validate Prefix, URL name and Suffix. */
        else
            {
            checkURL = validatePrefix2(urlInput);
            if (checkURL)
                checkURL = validateURL2(urlInput);
            if (checkURL)
                validateSuffix2(urlInput);
            }
        countURL++;  /* Count how many validation. */
        /* Set all buffer to 0 */
        memset(input, 0, sizeof(input));
        memset(urlInput, 0, sizeof(urlInput));
        }
    }

/*******************************************************************************
 * VALIDATE PREFIX OF WEB URL. (This function is in a part of validate web URL)
 * Get web URL from Control Validate web URL function. Then check prefix does it is
 * 'https://', 'https://' (either lower case or upper case) or not. If yes, return 1.
 * But if NOT, return 0 and print 'Not Valid'.
 */
int validatePrefix2(char prefixCheck[LENGTHWEB])
    {
    int i = 0;  /* Count loop to change URL to lower case */
    /* Change web URL to lower case for easy to check both upper case or lower case. */
    for(i = 0; i < strlen(prefixCheck); i++)
        prefixCheck[i] = tolower(prefixCheck[i]);
    /* Check that 'http://' or 'https://' is in front of web URL or not. */ 
    if (strstr(prefixCheck, "http://") != NULL)
        {
        if (strlen(prefixCheck) == strlen(strstr(prefixCheck, "http://")))

            return 1;
        }
    else if(strstr(prefixCheck, "https://") != NULL)
        {
        if (strlen(prefixCheck) == strlen(strstr(prefixCheck, "https://")))
            return 1;
        }
    printf("Not Valid - 'http://' or 'https://' must in front of web URL.\n");
    return 0;
    }

/*******************************************************************************
 * VALIDATE URL NAME OF WEB URL. (This function is in a part of validate web URL)
 * Get web URL from Control Validate web URL function. Then check period and legal 
 * letters (alphabets, numbers, periods, dashes) follow rules or not. If yes,
 * return 1. But if NOT, return 0 and print 'Not Valid'.
 */
int validateURL2(char urlCheck[LENGTHWEB])
    {
    int i = 0;          /* Count loop and check each character in web URL. */
    char *urlNoPrefix;  /* Get URL that doesn't have prefix. */
    /* Get URL doesn't contain 'http:' or 'https:'. */
    urlNoPrefix = strstr(urlCheck, "//");
    /* Check that there are only prefix or not. */
    if(strlen(urlNoPrefix) == 2)
        {
        printf("Not Valid - Please input URL name after 'https://' or 'http://'.\n");
        return 0;
        }
    /* Check that period is after prefix immediately or not. */
    if(urlNoPrefix[2] == '.')
        {
        printf("Not Valid - After 'https://' or 'http://' must not be period (.).\n");
        return 0;
        }
    /* Check that period in the end of web URL or not */
    if (urlNoPrefix[strlen(urlNoPrefix) - 1] == '.')
        {
        printf("Not Valid - Period can't in the end of web URL.\n");
        return 0;
        }
    for (i = 2; i < strlen(urlNoPrefix); i++)
        {
        /* Check that 2 periods next to each other or not. */
        if(strstr(urlNoPrefix,"..") != NULL)
            {
            printf("Not Valid - Two periods (.) must not next to each other.\n");
            return 0;
            }
        /* Check that therer are only letters,dash and period or not. */
        else if((!isalnum(urlNoPrefix[i])) && (urlNoPrefix[i] != '.')
                && (urlNoPrefix[i] != '-'))
            {
            printf("Not Valid - Please input only letters, numbers, ");
            printf("dashes (-) or periods(.).\n");
            return 0;
            }
        }
        return 1;
    }

/*******************************************************************************
 * VALIDATE SUFFIX OF WEB URL. (This function is in a part of validate web URL)
 * Get web URL from Control Validate web URL function. Then check suffix does it is
 * 'com', 'net', 'co.th', 'ac.th' and 'go.th' (either lower case or upper case)
 * or not. If yes, print 'Valid'. If not, print 'Not Valid'.
 */
void validateSuffix2(char suffixCheck[LENGTHWEB])
    {
    char *tokenSuffix[50] = {0};    /* Get string that after period. */
    int i = 0;                      /* Count loop and count string after period. */
    /* Change web URL to lower case for easy to check both upper case or lower case. */
    for(i = 0; i < (strlen(suffixCheck)); i++)
        suffixCheck[i] = tolower(suffixCheck[i]);
    /* Get strings after period. */
    tokenSuffix[0] = strtok(suffixCheck,".");
    for(i = 1; i < 50, tokenSuffix[0] != NULL; i++)
        {
        tokenSuffix[i] = strtok(NULL,".");
        if(tokenSuffix[i] == NULL)
            break;
        }
    i = i - 1; /* Get the position last array to check suffix. */
    /* If last string is 'th', then suffix can be only 'co.th','ac.th' or 'go.th'. */
    if(strcmp(tokenSuffix[i] , "th") == 0) 
        {
        i = i - 1; /* Get the position before last array to check suffix. */
        if((strcmp(tokenSuffix[i],"co") == 0) || (strcmp(tokenSuffix[i],"go") == 0)
           || (strcmp(tokenSuffix[i],"ac") == 0))
            printf("Valid\n");
        else
            {
            printf("Not Valid - '.com', '.net', '.co.th', '.ac.th' or '.go.th' ");
            printf("must in the end of web URL.\n");
            }
        }
    /* Check that suffix of URL is '.com' or '.net'. */
    else if((strcmp(tokenSuffix[i], "com") == 0) 
            || (strcmp(tokenSuffix[i], "net") == 0))
        printf("Valid\n");
    else
        {
        printf("Not Valid - '.com', '.net', '.co.th', '.ac.th' or '.go.th' ");
        printf("must in the end of web URL.\n");
        }
    return;
    }

/*******************************************************************************
 * CONTROL VALIDATE THAI MOBILE PHONE NUMBER.
 * This function loop ask user to input mobile phone number. Then send mobile phone
 * number to 2 Validate Functions(Check number and dash, Check Thai mobile phone number
 * form). If input only return, this validate stops.
 */
int controlphoneNumInput()
    {
    char input[MAXLENGTH] = {0};     /* Text typed input from user */
    char phoneNumInput[LENGTHPHONE]; /* Mobile phone number input from user */
    int countPhone = 0;              /* Count how many validations */
    int checkPhone = 0;              /* Check after send to validate correct or not */
    printf("Validate Thai mobile phone number (Hit return to stop)\n");
    while(countPhone>=0)
        {
        /* Ask input from user */
        printf("Enter mobile phone number: ");
        fgets(input, sizeof(input), stdin);
        /* If input return, stop validate and return 'countPhone'. */
        if (strlen(input) == 1)
            return countPhone;
        sscanf(input, "%s", phoneNumInput);
        /* This condition for user input space in mobile phone number */
        if (strlen(input) != (strlen(phoneNumInput) + 1))
            printf("Not Valid - Mobile phone number can't have any space.\n");
        /* Send phone number to validate number and validate Thai mobile phone form. */
        else
            {
            checkPhone = validateNumber3(phoneNumInput);
            if(checkPhone)
                validateThaiPhone3();
            }
        countPhone++;   /* Count how many validation. */
        /* Set all buffer to 0 */
        memset(input, 0, sizeof(input));
        memset(phoneNumInput, 0, sizeof(phoneNumInput));
        }
    }

/*******************************************************************************
 * VALIDATE NUMBER AND DASH. (This function is in a part of validate Thai mobile phone)
 * Get phone number from Control Validate Thai mobile phone number function. Then
 * check dashes correct or not and check there are letters or not. If corret,
 * return 1. If NOT, return 0.
 */
int validateNumber3(char phoneLetter[LENGTHPHONE])
    {
    int i = 0;          /* Count loop and check each character is number or not. */
    int countDash = 0;  /* Count how many dashes in string. */
    for(i = 0; i < strlen(phoneLetter); i++)
        {
        /* Count how many dashes and check it is correct or not. */
        if(phoneLetter[i] == '-')
            {
                countDash++;
                if(i < 2)
                {
                printf("Not Valid - Dash can't input earlier than position 3.\n");
                return 0;
                }
                else if(countDash > 2)
                {
                printf("Not Valid - Dash can't input more than 2.\n");
                return 0;
                }
                else if(phoneLetter[i] == phoneLetter[i + 1])
                {
                printf("Not Valid - Dash can't next to dash\n");
                return 0;
                }
                else if(i == (strlen(phoneLetter) - 1))
                {
                printf("Not Valid - Dash can't in the end of mobile phone number.\n");
                return 0;
                }
            }
        /* Check that it is letters or numbers */
        else if(!isdigit(phoneLetter[i]))
            {
            printf("Not Valid - Please input only number in mobile phone number.\n");
            return 0;
            }
        }
    return 1;
    }

/*******************************************************************************
 * VALIDATE THAI MOBILE PHONE NUMBER 
 * (This function is in a part of validate Thai mobile phone)
 * Get phone number from Control Validate Thai mobile phone number function. Then
 * check phone number contain 10 number digits and follow the rules or not. If yes,
 * print 'Valid'. But if NOT, print 'Not Valid'.
 */
void validateThaiPhone3(char phoneThai[LENGTHPHONE])
    {
    int i = 0;          /* Count loop and check each character in phone number. */
    int countNum = 0;   /* Count how many numbers. */
    /* Check that the first number is 0 or not. */
    if(phoneThai[0] != '0')
        printf("Not Valid - Please input '0' in front of mobile phone number.\n");
    /* Check that first 2 digits correct or not */
    else if((phoneThai[1] != '1') && (phoneThai[1] != '5') && (phoneThai[1] != '6') 
             && (phoneThai[1] != '8') && (phoneThai[1] != '9'))
        {
        printf("Not Valid - First 2 digits of Thai mobile phone number ");
        printf("must be '01','05','06','08' and '09'.\n");
        }
    else
        {
        for(i = 0; i < strlen(phoneThai); i++)
            {
            if(isdigit(phoneThai[i]))  /* Count how many number input. */
                countNum++;
            /* Check that there are 10 digits or not. */
            if((countNum > 10 || ((countNum < 10))
               && (phoneThai[i+1] == '\0')))
                {
                printf("Not Valid - Thai mobile phone number must input 10 digits.\n");
                break;
                }
            }
            if(countNum == 10)
                printf("Valid\n");
        }
    return;
    }

/*******************************************************************************
 * CONTROL VALIDATE HOTEL SERVICES CODE.
 * This function loop ask user to input hotel services code. Then send code to 2 
 * Validate Functions(Letter and Dollar). If input only return, this validate stops.
 */
int controlHotelServicesCode()
    {
    char input[MAXLENGTH] = {0};       /* Text typed input from user */
    char codeInput[LENGTHCODE] = {0};  /* Hotel services code input from user */
    int countCode = 0;                 /* Count how many validations */
    int checkCode = 0;                 /* Get result after send to validate */
    printf("Validate hotel services code (Hit return to stop)\n");
    while(countCode>=0)
        {
        /* Ask input from user */
        printf("Enter hotel services code: ");
        fgets(input, sizeof(input), stdin);
        /* If input return, stop validate and return 'countCode'. */
        if (strlen(input) == 1)
            return countCode;
        sscanf(input, "%s", codeInput);
        /* This condition for input space in hotel services code */
        if (strlen(input) != (strlen(codeInput) + 1))
            printf("Not Valid - hotel services code can't have any space.\n");
        /* Send hotel services code to validate letters and dollars. */
        else
            {
            checkCode = validateLetter4(codeInput);
            if(checkCode)
                validateDollar4(codeInput);
            }
        countCode++;    /* Count how many validation. */
        /* Set all buffer to 0 */
        memset(input, 0, sizeof(input));
        memset(codeInput, 0, sizeof(codeInput));
        }
    }

/*******************************************************************************
 * VALIDATE LETTER (This function is in a part of validate hotel services code)
 * Get hotel services code from Control Validate hotel services code function. Then
 * check letter in hotel services code correct or not. If yes, return 1. But if NOT,
 * print 'Not Valid' and return 0.
 */
int validateLetter4(char letterCheck[LENGTHCODE])
    {
    int i = 0;                  /* Count loop and check each letter. */
    int countLetter[5] = {0};   /* Count each hotel services letters. */
                                /* [0]-P, [1]-R, [2]-W, [3]-S, [4]-T */
    for(i = 0; (letterCheck[i] != '$') && (i < strlen(letterCheck)); i++)
        {
        /* Check that upper case or not */
        if(islower(letterCheck[i]))
            {
            printf("Not Valid - Hotel services code must be capital letters.\n");
            return 0;
            }
        /* Count how many letters in code and check letters is correct or not. */
        else if(letterCheck[i] == 'P')
            countLetter[0]++;
        else if(letterCheck[i] == 'R')
            countLetter[1]++;
        else if(letterCheck[i] == 'W')
            countLetter[2]++;
        else if(letterCheck[i] == 'S')
            countLetter[3]++;
        else if(letterCheck[i] == 'T')
            countLetter[4]++;
        else
            {
            printf("Not Valid - 'The letters must be only 'P', 'R', 'W', ");
            printf("'S','T' or '$'.\n");
            return 0;
            }
        }
    /* This condition for there are the same letter in hotel services code. */
    if((countLetter[0] > 1) || (countLetter[1] > 1) || (countLetter[2] > 1)
       || (countLetter[3] > 1) || (countLetter[4] > 1))
        {
        printf("Not Valid - You can't put the same letters in hotel services code.\n");
        return 0;
        }
    return 1;
    }

/*******************************************************************************
 * VALIDATE DOLLAR (This function is in a part of validate hotel services code)
 * Get hotel services code from Control Validate hotel services code function. Then
 * check there are 1-4 dollar in hotel services code or not. If yes, print 'Valid'. 
 * But if NOT, print'Not Valid'.
 */
void validateDollar4(char dollarCheck[LENGTHCODE])
    {
    /* Check how many dollars contain in code, then check it's in the end or not */
    if((strstr(dollarCheck,"$$$$") != NULL)
       && strlen(strstr(dollarCheck,"$$$$")) == 4)
        printf("Valid\n");
    else if((strstr(dollarCheck,"$$$") != NULL)
            && strlen(strstr(dollarCheck,"$$$")) == 3)
        printf("Valid\n");
    else if((strstr(dollarCheck,"$$") != NULL)
            && strlen(strstr(dollarCheck,"$$")) == 2)
        printf("Valid\n");
    else if((strstr(dollarCheck,"$") != NULL)
            && strlen(strstr(dollarCheck,"$")) == 1)
        printf("Valid\n");
    else
        {
        printf("Not Valid - Please input 1-4 dollars in the end of ");
        printf("hotel services code.\n");
        }
    return;
    }