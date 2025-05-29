/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */

/*  Write a program that reads the file “first.txt” one character at a time, but displays
the contents of the file one word at a time on the screen. Each word should be
on a new line when it is displayed to the screen. Helpful tip: Use can also use
fgetc() to read in single characters (instead of fscanf). */

/* SOLUTION: */

/* a program to read the file "first.txt" one word at a time, displaying them on the screen */
/* one word on a new line.  When the program reaches EOF, it should close the file and   */
/* terminate.                                                                               */
/* written by TB, August 2016                                                           */


#include <stdio.h>
void main()
{

    FILE *myFile;
    myFile = fopen("first.txt","w");
    fprintf(myFile,"Hello World");
    fclose(myFile);
    char c;
    myFile=fopen("first.txt","r");  // open first.txt for reading - first.txt must be in same folder as c programme

    while(fscanf(myFile, "%c", &c)!=EOF){
        if(c=='\n' || c==' '){
            c='\n';  }// if c is a space, set c to a newline

        printf("%c",c);  // display the value of c on the screen
      }

      /*Alternatively you can do:
      do
      {
        c=fgetc(myFile);  // get a single character from the file, store it in the variable c
        if(c==' ')
            c='\n';  // if c is a space, set c to a newline
        putchar(c);  // display the value of c on the screen
      }while(c!=EOF);  // continue looping until an end of file was read for c*/

      fclose(myFile);

}
