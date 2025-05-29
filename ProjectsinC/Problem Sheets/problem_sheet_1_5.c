/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */
#include <stdio.h>
void main()
/*  Write a program that opens a file called “first.txt” for writing. Your program
should then write the string “Hello World\n” to this file and finally close the
file. */
{
    FILE *fOut;
    fOut = fopen("first.txt","w");
    fprintf(fOut,"Hello World!");
    fclose(fOut);
}

/* SOLUTION: */

/* program that opens a file called first.txt for writing, then writes */
/* hello world to the file                                             */
/* written by TB, August 2016                                       */
#include <stdio.h>
void sol()
{
      FILE *myFile;
      myFile=fopen("first.txt","w");// open first.txt for writing - this will be in the same folder as the c program
      fprintf(myFile,"Hello World\n");
      fclose(myFile);
}
