/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */

/*   Modify program 5 above to count how many words are in the file. Print the
number of words in the file to the screen, on a new line after the last word has
been printed to the screen.*/

/* SOLUTION: */

/* a program to read the file "first.txt" one word at a time, displaying them on the screen */
/* separated by a space(' ').  The program should keep track of the number of words in the  */
/* file and write this to the screen after the last word. When the program reaches EOF, it  */
/* should close the file and terminate                                                      */
/* written by TB, August 2016
                                                        */
#include <stdio.h>

main()
{
      FILE *myFile;
      char c;
      int numWords=0;  // this will hold the number of words in the file
      myFile=fopen("first.txt","r");  // open the file for reading
      while(fscanf(myFile,"%c",&c)!=EOF)  //can also use (fgetc(myFile)!=EOF)
      {
            if(c=='\n' || c==' ') //if c is a new line OR c is a space, then assume a word has just finished
            {
                c='\n';  // change c to a new line, so that each word will be on a new line
                numWords=numWords+1;  // increment the number of words
            }
            /* display whatever c is to the screen (can also use putchar(c);
            - this could be a printing character, or it could be a new line or a non-printing character */
            printf("%c",c);  //
      }  // keep looking until c was input as EOF
      printf("number of words in the file: %d\n",numWords);  // print out the accumulated number of words
      fclose(myFile);
      return 0;
}
