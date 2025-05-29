/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
2. Pass array to function: Write a program which inputs a list of 5 values into a float array,
then calls a function to sort the list in ascending order. The function prototype should be
void sort(float anArray[]); where anArray contains the original list when the
sort function is called, and on returning to main() anArray contains the sorted list. I.e. the
function overwrites the contents of the original list with the sorted list. The sort function
has the following flowchart.
*/

/* SOLUTION: */

/* Problem 7-2.c                                           */
/* A program which inputs a list of 5 values into a       */
/* float array, then calls a function to sort the list     */
/* in ascending order.   The function prototype should     */
/* be                                                      */
/*void sort(float anArray[]);                            */
/* written by TB, March 2019                              */
#include <stdio.h>

#define SIZE 5

void sort(float anArray[]);

void main()
{
      float myArray[SIZE];
      int i;
      printf("please enter %d float values: \n",SIZE);
      for(i=0; i<SIZE; i++)
      {
        scanf("%f", &myArray[i]);
      }
      sort(myArray);
      printf("the values sorted in ascending order are:\n");
      for(i=0; i<SIZE; i++)
      {
        printf("%0.2f\n", myArray[i]);
      }

}
/* function void sort(float array[]);                                */
/* to sort the contents of an array                                    */
/* sort in ascending order                                             */
/* original array gets overwritten with sorted array                   */
/* (this is a bubble sort)                                             */
void sort(float anArray[])
{
     float temp;
     int i, j;
     for(i=0; i<SIZE; i++)
     {
              for(j=0; j<SIZE-1; j++)
              {
                    if(anArray[j]>anArray[j+1])
                    {
                         temp=anArray[j+1];
                         anArray[j+1]=anArray[j];
                         anArray[j]=temp;
                    }
              }
     }
}
