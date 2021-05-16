/**************************************************************
 *
 * racecar
 *
 *	 This program calculate distance of racing car
 *	 from speed and time that user input.
 *
 *	 Created by Nathaphop Sundarabhogin (Kla)  ID 3420
 *	   18 August 2017
 *
 ***************************************************************
 */

/***************************************************************
 * Calculate how far a racing car can travel.
 * Ask the user for speed of the car (meter per second)
 * and the number of seconds it travels,
 * then print a distance (kilometer) that car can travel.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
	{
	char inputvalue[128];	/* get input from the terminal*/
	double speed = 0;			/* speed of racecar (m/s)*/
	int time = 0;			/* time of racecar travel (second)*/
	double distance = 0;	/* distance of racecar can travel (km)*/
	
	/* Get the speed of racecar*/	
	printf("How fast is the car traveling (m/sec)? ");
	fgets(inputvalue, sizeof(inputvalue), stdin);
	sscanf(inputvalue,"%lf",&speed);

	/* Get the time of car travel*/	
	printf("How many seconds does the car travel? ");
	fgets(inputvalue, sizeof(inputvalue), stdin);
	sscanf(inputvalue,"%d",&time);

	/* Calcaulate and print distance*/
	distance = speed * time;
	distance = distance / 1000;
	printf("In %d seconds, the race car will travel %.4lf kilometers.\n", time, distance);
	exit(0);
	}
