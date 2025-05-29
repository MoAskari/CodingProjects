/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
1. Revision of functions (pass by value): Read in four marks for each of 10 students
from the file “marks.txt” and write out the average mark for each student to the screen.
You should calculate the average mark in a function. The function prototype should be:
float average(float m1, float m2, float m3, float m4);
 where m1, m2, m3 and m4 are the four marks to be averaged.
1a) Functions - Pass by address: Modify Problem 1 above so as to use pointers via
void average(float m1, float m2, float m3, float m4, float
*mean);
*/

/* SOLUTION: */

/* Problem6-1.c
Read in four marks for each of 10 students from the file “marks.txt”
and write out the average mark for each student to the screen.  You should
calculate the average mark in a function, using pass by value.
written by TB, March 2017                                              */
#include <stdio.h>
float average(float m1, float m2, float m3,float m4);
main()
{
      FILE *myFile;
      float av;
      float mark1, mark2, mark3, mark4;
      int i;
      myFile=fopen("marks.txt","r");
      printf("Marks\t\t\t\t\t\t\t|Average Mark\n");
      for(i=0; i<10; i++)
      {
             fscanf(myFile,"%f %f %f %f",&mark1,&mark2,&mark3,&mark4);
             av=average(mark1,mark2,mark3,mark4);
             printf("%6.2f %6.2f %6.2f %6.2f\t\t\t\t|%6.2f\n",mark1,mark2,mark3,mark4,av);
      }
      fclose(myFile);
}
/* function float average(int m1, int m2, int m3, int m4);  */
float average(float m1, float m2, float m3, float m4)
{
      return (m1+m2+m3+m4)/4;
}


