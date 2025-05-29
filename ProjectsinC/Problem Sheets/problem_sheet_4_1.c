/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
1. Write a C program to allow the user to enter 5 numbers into an integer array.
After all the numbers have been entered, display the list to the screen in reverse
order.
a. Change your code to allow 20 numbers to be entered. How would you
write your code to efficiently make changes (hint: use #define)?
*/

/* SOLUTION: */

/* Problem 4-1.c                                                            */
/* A C program to allow the user to enter 20 numbers into an integer array. */
/* After all the numbers have been entered, display the list to the screen  */
/* in reverse order.                                                        */
/* Written by TB, February 2017                                            */
#include <stdio.h>
#define SIZE 5
main()
{
      int array[SIZE];
      int i;
      printf("Please enter %d integer numbers, one per row.\n",SIZE);
      for(i=0; i<SIZE; i++)
      {
            scanf("%d",&array[i]);
      }

      printf("You entered, in reverse order:\n");
      for(i=SIZE-1; i>=0; i--)
      {
            printf("%d\n", array[i]);
      }

}
