/* Program: prog5.c
Author: Mohammad Askari
Date written: 05/10/2021 */
#include <stdio.h>
int main()
/* Write a program that inputs a number from the keyboard, and without
unnecessary calculations, outputs its square, cube and fourth power.*/
{
    int num;
    int square = num*num;
    int cube = num*square;
    int pow4 = num*cube;
    printf("Please enter a number\n");
    scanf("%d",&num);
    printf("The square of your number is %d \n", square);
    printf("The cube of your number is %d \n", cube);
    printf("The fourth power of your number is %d \n", pow4);
}

/* SOLUTION: */

/* Program to input a number and without unnecessary calculations output its square, cube and fourth power */
/* Written by Tara Baldacchino, August 2016                                                                          */

#include <stdio.h>
void sol()
{
      int number, square, cube, fourth;
      printf("please input an integer number\n");
      scanf("%d",&number);
      square=number*number;
      cube=square*number;  // reuse the square variable to reduce the number of calculations
      fourth=cube*number;  // reuse the cube variable to reduce the number of calculations
      printf("square = %d\n",square);
      printf("cube = %d\n",cube);
      printf("fourth = %d\n",fourth);

}
