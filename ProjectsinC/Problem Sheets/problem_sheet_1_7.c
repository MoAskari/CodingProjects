/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */
#include <stdio.h>
/*    Write a program that opens the file called “first.txt” for reading. The program
should print to the screen the first character found in the file.
 HINT: Use fscanf along with %c to read the first character from the file.
Then use printf to print this character to the screen.  */



/* SOLUTION */

/* a program to read the first character from the file "first.txt" and displaying it on the screen */
/* written by TB, August 2016                                                           */

#include <stdio.h>
void main()
{
      FILE *myFile;
      char c;
      myFile=fopen("first.txt","r");  // open first.txt for reading - first.txt must be in same folder as c programme

      fscanf(myFile, "%c", &c);
      printf("%c",c);  // display the value of c on the screen


      /*Alternatively you can do:

        c=fgetc(myFile);  // get a single character from the file, store it in the variable c

        putchar(c);  // display the value of c on the screen  */

      fclose(myFile);

}
