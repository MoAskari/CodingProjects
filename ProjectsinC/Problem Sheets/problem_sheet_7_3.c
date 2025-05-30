/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
3. Passing strings to functions: Write a C program that can: Prompt the user to enter a
string containing a maximum of 500 characters and no spaces.
• Input the string from keyboard and store it in a character array (string).
• Modify the string by:
o Changing every lower case letter in the original string to an upper case letter
(subtract 32 from the character).
o Changing every upper case letter in the original string to a lower case letter
(add 32 to the character).
o Leaving characters that are not letters unchanged.
• Keep track of the number of characters in the string that are not letters.
• Display, on the screen, the modified string.
• Display, on the screen, the number of characters in the string that are not letters.
Use a function to modify the string (char array) and to keep track of the number of
characters that are not letters. An example function could be
void modifyString(char *s, int *nNL, int strSize) (where nNL is
number of non-letters) but feel free to use something slightly different.
*/

/* SOLUTION: */

/* Problem 7-3.c                                                                  */
/* A C program to work with a string of up to 500 chars to                      */
/* - change upper case to lower and lower case to upper                         */
/* - leave non-letters unchanged                                                */
/* - keep track of how many non-letters are in the string                       */
/* All this needs to be done in a function which passes the string to a pointer */
/* Written by TB  March 2019                                                      */

#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 500


void modifyString(char *s, int *nNL, int strSize);

main()
{
  int stringSize=0; /* size of string input by user */
  char string[MAX_STRING_SIZE+1]; /* original string - will be modified.  Allow space for 500 chars plus null char to terminate string */
  int numNonLetters=0;
  int i;

  printf("Please enter a string of up to 500 characters, with no spaces \n");
  scanf("%s",string);   /* note that if the user enters a string of length > 500, the program will not work properly- change MAX_STRING_SIZE to 5 and check it out */
  printf("Thanks, the original string is %s\n",string);

  stringSize = strlen(string);  /* get the length of the string */
  printf("string length is %d\n", stringSize);

  modifyString(string, &numNonLetters, stringSize);

  printf("The new string is\n%s\n",string);
  printf("The number of non-letters in the string is %d\n", numNonLetters);


}

// function void modifyString(char *s, int *nNL, int strSize)
void modifyString(char *s, int *nNL, int strSize)
{
  int i;

  *nNL=0;

  for(i=0; i<strSize; i++ )
  {
    if( s[i]>='A' && s[i]<='Z' )
    {
      s[i] = s[i] + 32;  /* change upper case to lower case using ACSII table*/
    }
    else if ( s[i]>='a' && s[i]<='z' )
    {
      s[i] = s[i] - 32;  /* change lower case to upper case using ACSII table*/
    }
    else
    {
      s[i] = s[i];
	  *nNL = *nNL + 1;  /* if it was neither upper case nor lower case, then it isn't a letter, so add it to the total so far */
    }
  }
  s[strSize] = '\0';  /* add terminating null to new string (scanf will have added this to the original)*/


}


