/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */
#include <stdio.h>
int main()
/*   Two students have taken four examination papers. Write a program that reads
the four marks from the keyboard and prints their results in a table */
{
    int mark1, mark2, mark3, mark4, mark5, mark6, mark7, mark8;
    printf("Please enter Student 1's first mark \n");
    scanf("%d",&mark1);
    printf("Please enter Student 1's second mark \n");
    scanf("%d",&mark2);
    printf("Please enter Student 1's third mark \n");
    scanf("%d",&mark3);
    printf("Please enter Student 1's fourth mark \n");
    scanf("%d",&mark4);
    printf("Please enter Student 2's first mark \n");
    scanf("%d",&mark5);
    printf("Please enter Student 2's second mark \n");
    scanf("%d",&mark6);
    printf("Please enter Student 2's third mark \n");
    scanf("%d",&mark7);
    printf("Please enter Student 2's fourth mark \n");
    scanf("%d",&mark8);
    printf("\tMark1\tMark2\tMark3\tMark4\n");
    printf("Student1 %d\t%d\t%d\t%d\n", mark1, mark2, mark3, mark4);
    printf("Student2 %d\t%d\t%d\t%d\n", mark5, mark6, mark7, mark8);

}

/* SOLUTION: */

/* program that prints a table to the screen */
/* The table shows 4 marks for 2 students */
/* written by Tara Baldacchino, August 2016    */

#include <stdio.h>
void sol()
{
      int mark1, mark2, mark3, mark4,mark11, mark22, mark33, mark44;

      printf("please enter marks for first student, one at a time\n");

      printf("enter mark:\n");
      scanf("%d",&mark1);
      printf("enter mark:\n");
      scanf("%d",&mark2);
      printf("enter mark:\n");
      scanf("%d",&mark3);
      printf("enter mark:\n");
      scanf("%d",&mark4);

      printf("please enter marks for second student, one at a time\n");

      printf("enter mark:\n");
      scanf("%d",&mark11);
      printf("enter mark:\n");
      scanf("%d",&mark22);
      printf("enter mark:\n");
      scanf("%d",&mark33);
      printf("enter mark:\n");
      scanf("%d",&mark44);


      printf("\t Mark1   Mark2  Mark3  Mark4 \n");
      printf("Student1 %d \t %d \t %d \t %d\n", mark1, mark2, mark3, mark4);
      printf("Student2 %d \t %d \t %d \t %d", mark11, mark22, mark33, mark44);

}
