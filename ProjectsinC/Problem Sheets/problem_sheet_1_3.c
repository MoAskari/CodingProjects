/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */
#include <stdio.h>

/*  Write a program that accepts the radius of a circle and calculate its
circumference. Print the circumference to the screen. (use float variables, give
results to 2 decimal places )
HINT: 1. Create 2 variables: one to store the radius (r) and one for the
circumference (circum)
 2. Use a printf statement to prompt the user to enter the radius of the
circle
 3. Use scanf with %f to store the radius value
 4. Calculate the circumference (circum = 2*3.142*r)
 5. Print the circumference to the screen to 2 dp (use %.2f) using a printf
statement */

void main()
{
    float int1, int2, sum, prod;
    printf("Please enter your first integer \n");
    scanf("%f",&int1);
    printf("Please enter your second integer \n");
    scanf("%f",&int2);
    sum = int1 + int2;
    prod = int1 * int2;
    printf("The sum of your integers is as follows: %f + %f = %f \n", int1, int2, sum);
    printf("The product of your integers is as follows: %f * %f = %f \n", int1, int2, prod);
}

/* SOLUTION: */

/* Program to input 2 numbers and report their sums and product in the form of 2 equations */
/* Written by Tara Baldacchino, August 2016
                                               */
#include <stdio.h>
void sol()
{
      int num1, num2, sum, product;
      printf("please input two integer numbers\n");
      scanf("%d",&num1);
      scanf("%d", &num2);
      sum = num1+num2;
      product = num1*num2;
      printf("%d + %d = %d\n",num1,num2,sum);   // adding the numbers
      printf("%d * %d = %d\n",num1,num2,product); // multiplying the numbers
      return 0;
}


