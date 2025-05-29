/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
2. Modify the program you wrote for the question above to use a:
- function for entering the number of rows and columns, as well as the contents of matA.
matA needs to be passed by address (because any changes we make to matA in the
function we want to get reflected in main). The function prototype is
void inputMatrix(struct matrix *matA); // if you want to read in the rows
member of the struct, you could do something like:
 scanf(“%d”, &(*mat).rows); // you need to dereference
- function for displaying the matrix. The function prototype is
void displayMatrix(struct matrix matA);
- function for adding matA to itself (you can choose the function declaration yourself)
*/

/* SOLUTION: */

//Problem8-2.c
// A C program to define a struct matrix, with members
// float mat[10][10];  // to hold matrix of size up to 10x10
// int rows;               // to hold the number of rows in mat
// int cols;                // to hold the number of cols in mat
// In main( ), declare matA of type matrix,
// In a function, prompt the user for the number of rows and columns and input data into matA
// In another function, output matA to the screen.
// A third function adds matA to itself
// Main will need to call each function.
// Written by TB March 2019


#include <stdio.h>

struct matrix
{
       float Matrix[10][10]; // to hold matrix of size up to 10x10
       int rows;          // to hold the number of rows in mat
       int cols;          // to hold the number of cols in mat
};

void inputMatrix(struct matrix *mat);
void displayMatrix(struct matrix mat);
void addMatrix(struct matrix *mat);

void main()
{
     struct matrix matA;
     inputMatrix(&matA);    // calling input function
     displayMatrix(matA);   // calling display function
     addMatrix(&matA);      // calling add function
     displayMatrix(matA);   // calling display function

}
// function to input matrix
void inputMatrix(struct matrix *mat)
{
     int i,j;
     printf("please enter the number of rows in matA:  ");   //enter rows
     scanf("%d",&(*mat).rows);

     printf("please enter the number of columns in matA:  ");   // enter columns
     scanf("%d",&mat->cols);
     printf("please enter the contents of matA, one row at a time\n");
     for(i=0; i<(*mat).rows; i++)       // enter elements one row at a time
     {
              printf("Row %d:  ",i+1);
              for(j=0; j<(*mat).cols; j++)
              {
                    scanf("%f",&((*mat).Matrix[i][j]));

              }
     }
}
// function to display matrix
void displayMatrix(struct matrix mat)
{
     int i,j;
     printf("The matrix is:\n");
     for(i=0; i<mat.rows; i++)
     {
              printf("Row %d:  ",i+1);
              for(j=0; j<mat.cols; j++)
              {
                    printf("\t%8.2f",mat.Matrix[i][j]);
              }
              printf("\n");
     }
}

void addMatrix(struct matrix *mat){
     printf("Adding the matrix to itself.\n");
     int i,j;
        for(i=0; i<(*mat).rows; i++)
        {

            for(j=0; j<(*mat).cols; j++)
            {
                (*mat).Matrix[i][j] = (*mat).Matrix[i][j] + (*mat).Matrix[i][j];
            }

        }

}
