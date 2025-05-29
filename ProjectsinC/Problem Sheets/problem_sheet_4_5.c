/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
5. Write a C program that can: Prompt the user to enter a string containing a
maximum of 500 characters and no spaces.
• Input the string and store it in a character array.
• Write the string to a file, close the file.
• Open file and read the string.
• Give the user options to modify the string (use a switch case).
• Modify the string by:
o 1. Changing every lower case letter in the original string to an upper
case letter. Display, on the screen, the modified string.
o 2. Changing every upper case letter in the original string to a lower
case letter. Display, on the screen, the modified string.
o 3. Leaving string unchanged but keeping track of the number of
characters in the string that are not letters. Display, on the screen, the
number of characters in the string that are not letters.
o If the wrong option is entered the program loops back to ask the user to
enter a menu choice again.
 For example, if the string
abcdefgh!123!ABCDEFGH
is input, and the user chooses option 2, the string should be changed to
 abcdefgh!123!abcdefgh
*/

/* SOLUTION: */

/* Problem 4_5                                                                  */
/* A C program to work with a string of up to 500 chars to                      */
/* - write string to file                                                       */
/* - read string from file                                                      */
/* - change upper case to lower (menu choice 1)                                 */
/* - change lower case to upper (menu choice 2)                                 */
/* - leave string unchanged and count number of non-letters (menu choice 3)     */
/* Written by TB  October 2020   */

#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 500

main()
{

  int stringSize=0; /* size of string input by user */
  char string[MAX_STRING_SIZE+1]; /* original string.  Allow space for 500 chars plus null char to terminate string */
  char newString[MAX_STRING_SIZE+1]; /* new string */
  int numNonLetters=0;
  int i, choice, loop=1;

  /* Writing string to a file */
  FILE *filePtr;   // declaring file pointer
  filePtr=fopen("myFile.txt","w");

  printf("Please enter a string of up to 500 characters, with no spaces \n");
  scanf("%s",string);   /* note that if the user enters a string of length > 500, the program will crash */
  fprintf(filePtr,"%s\n",string);   // write to file
  printf("Thanks, the original string is %s\n",string);
  fclose(filePtr);

  /* Reading the string from the file */
  char stringFile[MAX_STRING_SIZE+1];
  FILE *fIn;   // declaring file pointer
  fIn=fopen("myFile.txt","r");
  fgets(stringFile,MAX_STRING_SIZE+1, fIn);
  stringSize = strlen(stringFile);  /* get the length of the string */
  printf("string length is %d\n", stringSize);

  /* Asking the user to enter a menu choice */
  while(loop){
    printf("Please select from the following options:\n");
    printf("Enter 1 to change lower case letter to upper case\n");
    printf("Enter 2 to change upper case letter to lower case\n");
    printf("Enter 3 to count the number of non-letters\n");
    scanf("%d",&choice);

    switch(choice){

      case 1:
         for(i=0; i<stringSize; i++ )
        {
            if ( stringFile[i]>='a' && stringFile[i]<='z' )
            {
                newString[i] = stringFile[i] - 32;  /* change lower case to upper case */
            }
            else
            {
                newString[i] = stringFile[i];

            }
        }
        printf("The new string is\n%s\n",newString);
        loop=0;
        break;

      case 2:
         for(i=0; i<stringSize; i++ )
        {
            if ( stringFile[i]>='A' && stringFile[i]<='Z' )
            {
                newString[i] = stringFile[i] + 32;  /* change upper case to lower case */
            }
            else
            {
                newString[i] = stringFile[i];

            }
        }
        printf("The new string is\n%s\n",newString);
        loop=0;
        break;

      case 3:
         for(i=0; i<stringSize; i++ )
        {
            if (!( (stringFile[i]>='a' && stringFile[i]<='z') || (stringFile[i]>='A' && stringFile[i]<='Z')) )
            {
                numNonLetters = numNonLetters + 1;  /* if it was neither upper case nor lower case, then it isn't a letter, so add it to the total so far */
            }

        }
        strcpy(newString,stringFile);
        printf("The number of non-letters in the string is %d\n", numNonLetters);
        printf("The string has remained unchanged\n%s\n",newString);
        loop=0;
        break;

      default:
        printf("Wrong menu choice. Looping again.");
        loop=1;
    }// end switch case
    fflush(stdin);

  } //end while loop
}
