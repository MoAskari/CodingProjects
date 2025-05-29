/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */
#include <stdio.h>
int main()
/*   Write a program that opens the file called “first.txt” (created in Q5) for
appending. It should then write the string “An extra line\n” to the opened file and
finally close the file. (Look at the contents of the .txt file- what happens if you run
the program several times? You might need to reload the .txt file every time). */
{
    FILE *fOut;
    fOut = fopen("first.txt","a");
    fprintf(fOut,"An extra line\n");
    fclose(fOut);
}

/* SOLUTION: */

/* program to opens a file first.txt for appending, then writes the string */
/* "an extra line\n" to the opened file and finally close it.  Use program */
/* above to display the new contents of the file                           */
/* written by lTB, August 2016                                          */
#include <stdio.h>
void main()
{
      FILE *myFile;
      myFile=fopen("first.txt","a");  // open first.txt for appending - first.txt much be in same folder as C program
      fprintf(myFile,"An extra line\n");
      fclose(myFile);
}
