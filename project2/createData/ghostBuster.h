/******************************************************************************
 *   ghostBuster.h
 *
 *      This header file declares functions that related to program Ghost Buster
 *      database. And also define number, file name and event structure.
 *
 *          Created by Nathaphop Sundarabhogin ID 3420
 */

#define LENGTH 100
#define SHORTLEN 30
#define DATAFILE "dataEvent.dat"
#define DUMPFILE "dataEvent.txt"

/* Declare struct of date */
typedef struct
    {
    int day;    /* Day of the date from 1-31 */
    int month;  /* Month of the date from 1-12 */
    int year;   /* Year in western year */
    int hour;   /* Hour in 24 hour format from 0-23 */
    int minute; /* Minute from 0-59 */
    } DATE_T;

/* Declare struct of event data */
typedef struct
    {
    DATE_T dateEvent;           /* Date and time of event happen */
    DATE_T dateInvest;          /* Date and time that investigation */
    char phoneReport[SHORTLEN]; /* Phone number persone reporting event */
    char typeEvent[SHORTLEN];   /* Type of event */
    char nameReport[LENGTH];    /* Name of person reporting event */
    char nameInvest[LENGTH];    /* Name of person investigating */
    float latitude;             /* Latitude of event location in form nn.nnnn */
    float longitude;            /* Longitude of event location in form nn.nnnn */
    int eventCode[2];           /* Event code, keep string in form yyyy-nnnn.
                                 * [0] - yyyy, [1] - nnnn. */
    int result;                 /* Result of event
                                 * 0 - Data Deleted      1 - Success
                                 * 2 - Failure           3 - Unknow */
    } EVENT_T;

/* Define a set of possible error return that can occur in all validate */
typedef enum 
    {
    CORRECT,     /* For correct case */
    ERR_LEN,     /* Have wrong length */
    ERR_CHAR,    /* Have wrong character */
    /* The Other are bad format specific validation that different in each case */
    ERR_FORM1,
    ERR_FORM2,     
    ERR_FORM3
    } CHECK_STATUS;
