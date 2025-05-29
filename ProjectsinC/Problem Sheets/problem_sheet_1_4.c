/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */
#include <stdio.h>
void main()
/* A student has taken four examination papers. Write a program that reads the four
marks from the keyboard, calculate the average mark and print it to the screen.
Give the answer to 1 decimal place */
{
    float mark1, mark2, mark3, mark4;
    printf("Please enter the first mark \n");
    scanf("%f",&mark1);
    printf("Please enter the second mark \n");
    scanf("%f",&mark2);
    printf("Please enter the third mark \n");
    scanf("%f",&mark3);
    printf("Please enter the fourth mark \n");
    scanf("%f",&mark4);
    float sum = mark1 + mark2 + mark3 + mark4;
    float avg = sum / 4;
    printf("The average of your exam marks is as follows: %f \n", avg);
}

/* SOLUTION: */

/* program that averages four marks */
/* written by Tara Baldacchino, August 2016    */
#include <stdio.h>
#define NUMMARKS 4  // define constant number of marks
void sol()
{
      float mark1, mark2, mark3, mark4,average,sum;
      int i;
      sum=0.0;
      printf("please enter marks, one at a time\n");

      printf("enter mark:\n");
      scanf("%f",&mark1);
      printf("enter mark:\n");
      scanf("%f",&mark2);
      printf("enter mark:\n");
      scanf("%f",&mark3);
      printf("enter mark:\n");
      scanf("%f",&mark4);
      sum=mark1+mark2+mark3+mark4;  // accumulate sum

      average=sum/NUMMARKS;  // divide accumulated sum by number of marks to get average
      printf("average was:  %.2f\n",average); // print average to 2 d.p.
      return 0;
}


