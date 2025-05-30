/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
6. Write a C code to input a week's (7 days) worth of 24 temperature readings (one per
hour) from a file, then to calculate and print the daily averages.
*/

/* SOLUTION: */

/* Problem 7-6.c                                                     */
/* Program to input a week's worth of 24 temperature readings per day */
/* from a file, find and print the daily average                      */
/* Written by TB, March 2019                                         */

#include <stdio.h>

#define SAMPLESIZE 24
#define WEEKSIZE 7

void calculateAverage(float data[][WEEKSIZE], float average[]);

void main()
{
	float inp[SAMPLESIZE][WEEKSIZE], average[WEEKSIZE], n;
	int i,j=0;


	FILE *fin;

	fin = fopen( "Temperatures.txt","r" );  /* open file for input */
	printf("Printing temperatures recorded every hour over a week:\n");
	if( fin != NULL )  /* if fin is NULL, the file did not open successfully */
	{
        printf("Day1\t Day2\t Day3\t Day4\t Day5\t Day6\t Day7\n");

        // compact code by reading in one element at a time
		for( i=0; i<SAMPLESIZE; i++ ) // read 1 element at a time from the file
		{
		    for(j=0;j<WEEKSIZE;j++){

                fscanf(fin, "%f", &n);
                printf("%0.2f\t", n);   //printing the temperature values
                inp[i][j]=n;
		    }

        printf("\n");

		}

		printf("\n");
		fclose( fin );                    /* close the input file */

		calculateAverage(inp, average);

        for(j=0;j<WEEKSIZE;j++){
            printf( "Day %d average temperature was %.2f \n", j+1,average[j]);}




    } else printf( "The file could not be opened - program aborting\n" );

}

/*****************************************************************************/
/* function to calculate average, given array of data and size as parameters */
/*****************************************************************************/
void calculateAverage(float data[][WEEKSIZE], float average[])
{
      int i,j;
      float sum;

      for(j=0;j<WEEKSIZE;j++){    //since I want the daily averages, my nested loops are this way round- taking the average of each column
        sum=0.0;
        for( i=0; i<SAMPLESIZE; i++ )
        {
            sum = sum+data[i][j];
        }
        average[j] = sum/SAMPLESIZE;
      }
}

