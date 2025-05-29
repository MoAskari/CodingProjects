/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
2. Write a C program to allow the user to enter a string. Store the string in a
character array of size 50. Display the string to the screen. Using a for or while
loop, search the character array for the character *, and, if you find it/them,
display to the screen the array index/indices at which you found it/them.
*/

/* SOLUTION: */

/* Problem 4-2.c                                                              */
/* A C program to allow the user to enter a string, store the string in a     */
/* character array of size 50, display the string to the screen, and          */
/* using a for or while loop, search the character array for the character *, */
/* and, if found, display to the screen the array index at which it was found.*/
/* Written by TB, February 2017                                              */
#include <stdio.h>
#include <string.h>
#define SIZE 50
main()
{
      char string[SIZE];
      int i,length, count=0;
      printf("Please enter a string up to length 49.\n");
      //scanf("%s",string);
      gets(string);
      puts(string);
      length=strlen(string);
      //if(length<SIZE)
      //{
            for(i=0; i<length; i++)
            {
                  if(string[i]=='*'){
                    printf("* found at index %d\n",i);
                    count++;
                  }

            }

            if(count==0)
                printf("No * found!");
      //} else printf("invalid string length, program aborting\n");

}

