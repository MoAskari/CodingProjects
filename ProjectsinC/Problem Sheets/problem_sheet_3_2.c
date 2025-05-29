/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/* Create a file in Notepad that contains a list of student marks, or use the one
found on Blackboard. Write a program that reads this file and finds 1) the
maximum mark in the list and 2) the average mark. The program must use a
function to find the maximum mark and the maximum mark must be printed in
main. The program must use another function to find the average mark and the
average mark must be printed (to 1d.p.) from within the function. Please do NOT
use arrays! Your program must check to see if the file exists.*/

/* SOLUTION: */

/* A program which reads in a file containing a list of marks,
and prints the maximum mark in the list, and calculates the average.
The max mark is found via a function and returned to main.
The average mark is found in a function and printed within the function.
Author: Tara Baldacchino, August 2019  */


#include <stdio.h>

int max(int a, int b);
void average(int sum, int N);

main()
{
  int mark, maxMark = 0, sum=0, num=0;
  FILE *fin;

  fin = fopen("myFile.txt", "r");   // reading in file

  if(fin==NULL){
    printf("myFile.txt is not in folder, aborting program\n");}
  else{


    while(fscanf(fin, "%d",&mark)!=EOF)  // look for end of line
   	 {
        maxMark = max(maxMark, mark);  // calling function to find maximum mark
        sum = sum + mark;
        num++;

        }
    printf("The max mark is %d\n", maxMark);
    average(sum,num);        // calling function to find average mark
  }
}

// function definition to find and return maximum mark
int max(int a, int b){
    if (a>b)
        return a;
    else
        return b;
}

// function definition to find and return maximum mark
void average(int sum, int N){
    float average;
    average = (float)sum/N;   //investigate what happens if you don't use (float)
    printf("Average mark is %.1f",average);
}
