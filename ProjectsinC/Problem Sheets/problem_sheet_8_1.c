/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
1. Write a C program to define a struct matrix, with members:
float Matrix[10][10]; // to hold a matrix of size up to 10x10
int rows; // to hold the number of rows in mat
int cols; // to hold the number of cols in mat
 In main( ), declare matA of type struct matrix, prompt the user for the number of rows and
columns (<=10), input data into matA from the keyboard, output matA to the screen, then add
matA to itself and print it to the screen. Keeping looping until the user quits the program.
*/

/* SOLUTION: */

//Problem8-1.c
// A C program to define a struct matrix, with members
// float mat[10][10];  // to hold matrix of size up to 10x10
// int rows;               // to hold the number of rows in mat
// int cols;                // to hold the number of cols in mat
// In main( ), declare matA of type matrix, prompt the user
// for the number of rows and columns, input data into matA, output matA to the screen
// add the matrix to itself and display to the screen
// Written by TB March 2020

#include <stdio.h>

struct matrix
{
       float Matrix[10][10]; // to hold matrix of size up to 10x10
       int rows;          // to hold the number of rows in mat
       int cols;          // to hold the number of cols in mat
};

void main()
{
     int i,j, choice, quit;
     struct matrix matA;

   do{

    do{
        printf("please enter the number of rows in matA (<10):  ");
        scanf("%d",&matA.rows);
    }while(matA.rows<0||matA.rows>10);


    do{
        printf("please enter the number of columns in matA(<10):  ");
        scanf("%d",&matA.cols);
    }while(matA.cols<0||matA.cols>10);

    printf("please enter the contents of matA, one row at a time\n");
    for(i=0; i<matA.rows; i++)
        {
            printf("Row %d:  ",i+1);
            for(j=0; j<matA.cols; j++)
            {
                scanf("%f",&matA.Matrix[i][j]);
            }
        }

     printf("The matrix is:\n");
     for(i=0; i<matA.rows; i++)
        {
            printf("Row %d:  ",i+1);
            for(j=0; j<matA.cols; j++)
            {
                printf("\t%8.2f",matA.Matrix[i][j]);
            }
            printf("\n");
        }

        printf("Adding the matrix to itself.\n");
        for(i=0; i<matA.rows; i++)
        {

            for(j=0; j<matA.cols; j++)
            {
                matA.Matrix[i][j] = matA.Matrix[i][j] + matA.Matrix[i][j];
            }

        }

      printf("The matrix is:\n");
      for(i=0; i<matA.rows; i++)
        {
            printf("Row %d:  ",i+1);
            for(j=0; j<matA.cols; j++)
            {
                printf("\t%8.2f",matA.Matrix[i][j]);
            }
            printf("\n");
        }



        fflush(stdin);
        printf("Would you like to quit? Yes=1, No = 0.\n");
        scanf("%d",&quit);


     }while(quit==0);

}
