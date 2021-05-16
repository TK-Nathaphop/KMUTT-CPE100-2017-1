/**************************************************************
 *
 * racecar
 *
 *	 This program calculate distance of racing car
 *	 from starting speed, time, and acceleration that user input.
 *
 *	 Created by Nathaphop Sundarabhogin (Kla)  ID 3420
 *	   18 August 2017
 *
 ***************************************************************
 */

/***************************************************************
 * Calculate how far a racing car can travel.
 * Ask the user for starting speed of the race car (meter per second),
 * the number of seconds it travels and rate of acceleration (m/sec2)
 * then print a distance (kilometer) that car can travel.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
	{
	char inputvalue[128];	/* get input from the terminal*/
	double speed = 0;		/* speed of race car (m/s)*/
	double acceleration = 0;	/* acceleration of race car (m/s2)*/
	int time = 0;			/* time of race car travel (second)*/
	double distance = 0;	/* distance of race car can travel (km)*/
	
	/* Get the speed of racecar*/	
	printf("When starting, how speed of the car (m/sec)? ");
	fgets(inputvalue, sizeof(inputvalue), stdin);
	sscanf(inputvalue,"%lf",&speed);

	/* Get the acceleration of racecar*/	
	printf("What acceleration of the car (m/sec2)? ");
	fgets(inputvalue, sizeof(inputvalue), stdin);
	sscanf(inputvalue,"%lf",&acceleration);

	/* Get the time of car travel*/	
	printf("How many seconds does the car travel? ");
	fgets(inputvalue, sizeof(inputvalue), stdin);
	sscanf(inputvalue,"%d",&time);

	/* Calculate and Print distance*/
	distance = (speed * time) + (acceleration * time * time / 2);
	distance = distance / 1000;
	printf("In %d seconds, the race car will travel %.4lf kilometers.\n", time, distance);
	exit(0);
	}
