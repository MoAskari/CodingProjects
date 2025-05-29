/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
5. Write a program that allows the user to enter a string into a string variable. Create a pointer to
point to this string. Then print this string:
a) Using the pointer with %c within a for loop
b) Using the string and a pointer with %s
*/

/* SOLUTION: */

/* Problem 5_5: A program that allows the user to enter a string into a string variable.
Create a pointer to point to this string. Then print this string:
a)	Using the pointer with %c within a for loop
b)	Using the pointer with %s */


/* TB, February 2020 */

#include <stdio.h>
#include <string.h>

#define SIZE 50


void main()
{
    char string1[SIZE], *ptrS;
    ptrS = string1;
    int i, lengthString1;

    printf("Enter a string <49\n");
    gets(string1);

    printf("\nString printed using char and pointer:\n");

    lengthString1 = strlen(string1);
    for(i=0;i<lengthString1;i++)
    {
        printf("%c",*(ptrS+i));
    }

    printf("\n\nString printed using %%s and string:\n");
    printf("%s",string1);

    printf("\n\nString printed using %%s and pointer:\n");
    printf("%s",ptrS);

}
