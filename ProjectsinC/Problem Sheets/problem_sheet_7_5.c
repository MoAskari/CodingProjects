/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
5. Write a C program to input and then display a 5 by 3 matrix. The contents of matrix matA
must be entered in a function, and another function is required to output matA to the
screen. For the input function, pass matA to the function by address. For the output
function, pass matA to the function by value (element by element).
*/

/* SOLUTION: */

/* Problem 7-5                                                                  */
/* A C program which inputs and displays a 5 by 3 matrix                      */
/* uses function void inputMatrix(float matA[][COLS] to input the matrix       */
/* uses function void outputMatrix(float m) to print the matrix                   */

/* Written by TB  March 2019                                                       */

#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 3


void inputMatrix(float matA[][COLS]);
void outputMatrix(float m);


void main()
{
    int i,j;
    float matA[ROWS][COLS];

    inputMatrix(matA);

    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            outputMatrix(matA[i][j]);
        }
        printf("\n");
    }


}

void inputMatrix(float matA[][COLS]){
    int i, j;

    printf("Enter elements for a 5 by 3 matrix, row by row:\n");

    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            scanf("%f",&matA[i][j]);
        }
    }
}

void outputMatrix(float m){

    printf("%0.2f  ",m);


}
