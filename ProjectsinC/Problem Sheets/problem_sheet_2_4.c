/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */

/* SOLUTION */

/* program to read a file and read the characters one at a time from the file */
/* then display them to the screen.  When the program reaches EOF, close the  */
/* file and terminate.                                                        */
/* written by TB, October 2016                                             */

#include <stdio.h>
main()
{
      FILE *myFile;
      char c=' ';
      myFile=fopen("first.txt","r");  // open first.txt for reading - first.txt must be in the same folder as the C program
      while(fscanf(myFile, "%c", &c)!=EOF)  // is c end of file?
      {
            printf("%c",c);
      }

      /* Alternatively you can do:

      while(c!=EOF){
        c=fgetc(myFile); // read one character at a time from the file
        putchar(c);  // putchar(c) displays the value of the character c on the screen
      }  */
      fclose(myFile);
      return 0;

}
