/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
1. Declare an integer variable and initialise it to 10. Declare an integer pointer variable. Using the
pointer, perform some mathematical function eg multiply it by 10, or add a number to it. Print
the contents using the variable pointer and the variable itself.
*/

/* SOLUTION: */

/* A simple problem to demonstrate use of pointers*/

#include <stdio.h>

void main(){

    int A=10, *ptrA;

    ptrA = &A;

    *ptrA = *ptrA*10;

    printf("The value of A is %d\n",A);
    printf("The value of A is %d\n",*ptrA);


}
