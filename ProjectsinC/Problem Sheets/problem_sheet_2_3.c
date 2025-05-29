/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */
#include <stdio.h>
int main()
/* */
{int n, i, facto=1;
do {printf("Please enter a number ");
    scanf("%d",&n);
    }while (n <0);
for (i=1; i<=n; i++){
    facto = facto*i;}
printf("The factorial is %d",facto);}

/* SOLUTION */

/* program that reads in an integer number and works out its factorial */
/* factorial n! = n × (n-1)!                                           */
/* written by TB, August 2016                                       */
#include <stdio.h>
int main()
{
      int number,i;
      int facto=1;  // this will hold the factorial; initialize facto to 1, which is the factorial of 1

      printf("Factorial calculator:\n");


      do{
        printf("Enter a non-negative number\n");
        scanf("%d",&number);
      }while(number<0);


       for(i=1; i<=number; i++)
       {
               facto = facto*i;  //do a walkthrough of the values to see how this works
       }

      printf("factorial of %d is %d\n",number,facto);
      return 0;
}
