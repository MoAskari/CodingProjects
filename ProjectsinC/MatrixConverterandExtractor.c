/* Program: ACS130 Individual C Programming Assignment 2
Author: Mohammad Askari
Date submitted: 29/03/2022

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
The code given below is designed to input a 10x10 matrix from an external file, and store it.
It then asks the user to select a certain size of matrix to be extracted from this, which is also stored separately.
The user is then asked to select a 2x2 matrix from the first matrix, after which the code calculates it's determinant.
Finally, the inverse of this matrix is calculated.
This process repeats, asking the user each time whether they would like to run the program again.
Defensive programming is included in the event that the user inputs negative values, or values above the maximum for any matrix.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>                                                                                                                                         // Defines the library being used, stdio.h
struct matrix{                                                                                                                          // defines a structure called matrix, with certain parameters
    float mValues[10][10];                                                                                                            // to hold the values in the matrix, up to 10 rows x 10 columns
    int nrows;                                                                                                                                          // to hold the number of rows used in mValues
    int ncols;                                                                                                                                       // to hold the number of columns used in mValues
    };

/* FUNCTION PROTOTYPES */
void matrixInput(struct matrix *mat, FILE *in);                                   // to input the size of the matrix, and read in the values from the file into the 2D array that makes up the matrix
void matrixDisplay(struct matrix mat);                                                                                              // to display the values in the 2D array that makes up the matrix
float matrixDeterminant(struct matrix m1, struct matrix *m2, int *check);                                   // to find the determinant of matrix m2, a 2x2 subset matrix of m1, and return it to main
void matrixInverse(struct matrix m2, float determinant, struct matrix *m3);                            // to find the inverse of the 2x2 matrix, using the variable check to perform its calculations

void main(){                                                                                                                                                               // begins the main program
    int quit = 0;                                                                //defines an integer 'quit' to store the value given when the user is asked if they would like to repeat the program
    do{                                                                                    // initiates a 'do while' loop to repeat the program over a given condition until the user chooses to quit
        struct matrix oriMatrix;                                                                   // defines a structure variable to hold information about the original matrix, input from the file
        struct matrix subMatrix = {{{0,0},{0,0}},2,2};                                                                       // defines a structure variable to hold the submatrix chosen by the user
        struct matrix invMatrix = {{{0,0},{0,0}},2,2};                                                           // defines a structure variable to hold the inverse matrix calculated by the program
        FILE *myFile;                                                                                                                                        // declares a pointer to the file stream
        myFile = fopen("matrix.txt", "r");                                                                                                                 // opens the file 'matrix.txt' for reading
        if(myFile == NULL){                                                                                                        // creates a condition if the file is not opened or read correctly
            printf("File could not be opened. Please make sure your file is named correctly and restart the program.");                                 //Tells the user the file could not be opened
            return 0;                                                                                                                                                             // ends the program
        }

        /* ASK FOR NUMBER OF ROWS AND STORE IT */                                                                       // Header: code to ask the user for the number of rows their matrix should be
        printf("Enter # rows of the matrix (<10):\n");                                                                                               // asks the user for the number of rows required
        do{                                                                             // initiates a do while loop to continue asking the user until a suitable input (between 1 and 10) is entered
            scanf("%d", &oriMatrix.nrows);                                                                                                                   // requests keyboard input from the user
            if(oriMatrix.nrows > 10 || oriMatrix.nrows <1){                                  // condition to tell the user to input again, if the number of rows given is more than 10 or less than 1
                printf("The maximum number of rows must be less or equal to 10, and more than 0. Please select a new # of rows:\n");                                 // tells the user to input again
            }
        }while(oriMatrix.nrows > 10 || oriMatrix.nrows <1);                                                                  // loops the program while number of rows is more than 10 or less than 1

        /* ASK FOR NUMBER OF COLUMNS AND STORE IT */                                                                 // Header: code to ask the user for the number of columns their matrix should be
        printf("Enter # columns of the matrix (<10):\n");                                                                                         // asks the user for the number of columns required
        do{                                                                             // initiates a do while loop to continue asking the user until a suitable input (between 1 and 10) is entered
            scanf("%d", &oriMatrix.ncols);                                                                                                                   // requests keyboard input from the user
            if(oriMatrix.ncols > 10 || oriMatrix.ncols <1){                               // condition to tell the user to input again, if the number of columns given is more than 10 or less than 1
                printf("The maximum number of columns must be less or equal to 10, and more than 0. Please select a new # of columns:\n");                           // tells the user to input again
            }
        }while(oriMatrix.ncols > 10 || oriMatrix.ncols <1);                                                               // loops the program while number of columns is more than 10 or less than 1
        matrixInput(&oriMatrix, myFile);                                         // calls the function matrixInput to input the matrix from the file and store it in the oriMatrix structure variable
        fclose(myFile);                                                                                                                                                            // closes the file

        /* SHOW THE SUB MATRIX THAT HAS BEEN SELECTED */                                                                                                      // Header: shows the selected submatrix
        matrixDisplay(oriMatrix);                                                                                                           // calls the function matrixDisplay to display the matrix

        /* FINDS THE DETERMINANT OF THE CHOSEN MATRIX */                                                    // Header: finds the determinant of the matrix chosen by the user, if one can be obtained
        int check, *checkPtr = &check;                                                       // defines new integer variable check, with a pointer assigned to it for use in and outside of functions
        float determinant = matrixDeterminant(oriMatrix, &subMatrix, checkPtr);                           // defines a float variable for the determinant, which calls the function matrixDeterminant

        /* FINDS THE INVERSE OF THE MATRIX */                                                                                           //Header: finds the inverse of the matrix if one can be found
        if (check == 0){                                                                   // defines a condition using the check variable, for when the matrix isn't large enough to have an inverse
            printf("\nThe inverse of the matrix could not be found because the matrix is not an appropriate size.");                    // tells the user that the chosen matrix isn't the right size
            }
        if (check == 2){                                           // defines a condition using the check variable, for when the matrix has a determinant of zero, meaning an inverse cannot be found
            printf("\nThe inverse of the matrix could not be found because the determinant is equal to 0.");             // tells the user that the determinant is zero so an inverse cannot be found
            }
        if (check == 1){                                                 // defines a condition using the check variable, for when the matrix has a non zero determinant, and an inverse can be found
            matrixInverse(subMatrix, determinant, &invMatrix);                                                             // calls the function matrixInverse to calculate the inverse of the matrix
            }
        fflush(stdin);                                                                                      // clears the input stream, so values from previous iterations of the code are not reused

        /* ASKS THE USER IF THEY WOULD LIKE TO INPUT ANOTHER MATRIX */                                                            // Header: asks the user if they would like to continue the program
        printf("\nWould you like to input another matrix? (type 1 for yes or any other character for no)\n");                             // asks the user if they would like to input another matrix
        scanf("%d",&quit);                                                                                                                                   // requests keyboard input from the user
        if (quit!= 1){                                                                                                                    // defines a condition to end the program if 1 is not input
            return 0;                                                                                                                                                             // ends the program
            }
    }while (quit == 1);                                                                                                 // repeats the entire main function until the value of quit is not equal to 1
}

void matrixInput(struct matrix *mat, FILE *in){                                                                                                                // Function definition for matrixInput
    for(int row = 0; row < mat->nrows; row++){                        // loops the code for a number of times equal to the number of rows in the referenced matrix, given when the function is called
        for(int col = 0; col < mat->ncols; col++){                 // loops the code for a number of times equal to the number of columns in the referenced matrix, given when the function is called
            fscanf(in, "%f", &(mat->mValues[row][col]));                                                                            // scans in the float values from the external file one at a time
            }
        }
}

void matrixDisplay(struct matrix mat){                                                                                                                       // Function definition for matrixDisplay
    for(int row = 0; row < mat.nrows; row++){                         // loops the code for a number of times equal to the number of rows in the referenced matrix, given when the function is called
        printf("\n|");                                                                                                                // prints a new line and a marker to display the matrix clearly
        for(int col = 0; col < mat.ncols; col++){                  // loops the code for a number of times equal to the number of columns in the referenced matrix, given when the function is called
            printf("%10.2f", mat.mValues[row][col]);                                     // prints float values of the matrix to 2 d.p, from the referenced matrix, given when the function is called
            }
        printf("|");                                                                                                                                        // prints a marker at the end of each row
        }
    printf("\n\n");                                                                                                                                                           // prints two new lines
}

float matrixDeterminant(struct matrix m1, struct matrix *m2, int *check){                                                                                // Function definition for matrixDeterminant
    printf("Finding the determinant now!\n");                                                                                                    // tells the user the determinant is now being found
    float det;                                                                                                                                        // defines a float variable for the determinant
    int rowMax = m1.nrows - 2, colMax = m1.ncols - 2, rowUser, colUser, onecheck = 0;                                             // defines a number of variables useful for finding the determinant

    if (m1.nrows == 1 && m1.ncols == 1){                                                                                        // establishes a condition in the event that the chosen matrix is 1x1
        onecheck = 1;                                                                                                                                            // sets the variable 'onecheck' to 1
        *m2 = m1;                                                                                                                     // sets the value of the submatrix to that of the chosen matrix
    }

switch(onecheck){                                                                                                      // establishes a switch case for the event that the user requests a 1x1 matrix
    case 1:                                                                                                                                                                                 // case 1
        det = m1.mValues[0][0];                                                                                                   // sets the value of the determinant to the value of the 1x1 matrix
        printf("The determinant for this 1x1 matrix is just it's value: %0.2f\n",det);                                                       // tells the user the determinant is equal to the matrix
        break;                                                                                                                                                       // breaks out of the switch case
    default:                                                                                                                                                                          // default case
        if(m1.nrows < 2 || m1.ncols < 2){                                                                     // condition established if the number of rows and columns in the matrix is less than 2
        *check = 0;                                                                                                                                                   // sets the check variable to 0
        printf("The determinant could not be found because the chosen matrix is not an appropriate size.");                                   // tells the user that the matrix is not the right size
        return;                                                                                                                                                                  // ends the function
        }

        /* ASKS THE USER TO SELECT A ROW NUMBER TO START THE 2x2 SUB MATRIX FROM WHICH THE DETERMINANT CAN BE FOUND */                            // Header: asks the user for a submatrix row number
        if(m1.nrows != 2){                                                                                               // condition established if the number of rows in the chosen matrix is not 2
            printf("\nEnter row number where to start 2x2 matrix, matrix needs to be between 0 and %d:\n", rowMax);                         // asks the user for a row number to start the 2x2 matrix
            do{                                                                                                                                                                 // establishes a loop
                scanf("%d", &rowUser);                                                                                                                     // requests a keyboard input from the user
                if(rowUser > rowMax || rowUser <0){                     // condition established if the input from the user is greater than the number of rows of the original matrix, or less than 0
                printf("The number of rows must be less or equal to %d, and more than -1. Please select a new # of rows:\n",rowMax);                         // tells the user to select a new number
                }
            }while(rowUser > rowMax || rowUser <0);                   // repeats the loop until the number entered by the user is less than the maximum rows in the chosen matrix, and greater than 0
        }
        else{                                                                                                    // if the number of rows in the chosen matrix is 2, the variable rowUser is set to 0
            rowUser = 0;                                                                                                                                            // sets the variable rowUser to 0
            }

        /* ASKS THE USER TO SELECT A COLUMN NUMBER TO START THE 2x2 SUB MATRIX FROM WHICH THE DETERMINANT CAN BE FOUND */                      // Header: asks the user for a submatrix column number
        if(m1.nrows != 2){                                                                                            // condition established if the number of columns in the chosen matrix is not 2
        printf("\nEnter column number where to start 2x2 matrix, matrix needs to be between 0 and %d:\n", colMax);                       // asks the user for a column number to start the 2x2 matrix
        do{                                                                                                                                                                     // establishes a loop
            scanf("%d", &colUser);                                                                                                                         // requests a keyboard input from the user
            if(colUser > colMax || colUser <0){                      // condition established if the input from the user is greater than the number of columns of the original matrix, or less than 0
            printf("The number of columns must be less or equal to %d, and more than -1. Please select a new # of columns:\n",colMax);                       // tells the user to select a new number
            }
        }while(colUser > colMax || colUser <0);                    // repeats the loop until the number entered by the user is less than the maximum columns in the chosen matrix, and greater than 0
        }
        else{                                                                                                 // if the number of columns in the chosen matrix is 2, the variable colUser is set to 0
            colUser = 0;                                                                                                                                            // sets the variable colUser to 0
        }

        // SETS THE VALUES OF THE SUBMATRIX TO THAT OF THE ORIGINAL MATRIX                                                    //Header: inputs the values of the chosen matrix into the 2x2 submatrix
        for(int row = 0; row < 2; row++){                                                                                                             // loops the code twice, for the number of rows
            for(int col = 0; col < 2; col++){                                                                                                      // loops the code twice, for the number of columns
            (*m2).mValues[row][col] = m1.mValues[rowUser+row][colUser+col];               // sets the value of m2 to the value of m1 for one position in the matrix, depending on the variables shown
            }
        }
        int detA = (*m2).mValues[0][0], detB = (*m2).mValues[0][1], detC = (*m2).mValues[1][0], detD = (*m2).mValues[1][1]; // defines integer variables for the 4 component values of the 2x2 matrix
        det = (((detA) * (detD)) - ((detB) * (detC)));                                                                                      //calculates the determinant using the 4 component values
}

if (det != 0){                                                                                                                                // condition established if the determinant is non zero
    *check = 1;                                                                                                                                          // sets the value of the variable check to 1
    }
if (det == 0){                                                                                                                                    // condition established if the determinant is zero
    *check = 2;                                                                                                                                          // sets the value of the variable check to 2
    }
/* END RESULT: */                                                                                                                                       //Header: gives the result of the determinant
        if ((*check == 1 || *check == 2)&&onecheck !=1){                                                           //condition established if the check variable is 1 or 2, and the matrix is not 1x1
        printf("\nThe determinant is %.2f for\n",det);                                                                                       // tells the user the determinant for their given matrix
        matrixDisplay(*m2);                                                                                //calls the function matrixDisplay to display the matrix used to calculate the determinant
        return det;                                                                                                                      // returns the value of the determinant to the main function
        }
}

void matrixInverse(struct matrix m2, float determinant, struct matrix *m3){                                                                                  // Function definition for matrixInverse
printf("\nFinding the inverse now!\n");                                                                                                         // Tells the user that the inverse is now being found
if (m2.nrows == 1 && m2.ncols == 1){                                                                             // condition established if the number  of rows and columns in the given matrix is 1
    printf("This is a 1x1 matrix, so it's inverse is 0.");                                                                                    // tells the user that the inverse of a 1x1 matrix is 0
    return;                                                                                                                                                           // returns to the main function
    }
printf("The inverse of the matrix is:\n\n");                                                                                                              // tells the user the inverse of the matrix

// REVERSES THE VALUES OF THE INVERSE MATRIX                                          // uses the values of the given matrix to obtain the second component, the matrix used to calculate the inverse
(*m3).mValues[0][0] = m2.mValues[1][1];                                                                          //sets the first value of the inverse matrix to the fourth value of the given matrix
(*m3).mValues[0][1] = -m2.mValues[0][1];                                                                  //sets the second value of the inverse matrix to minus the second value of the given matrix
(*m3).mValues[1][0] = -m2.mValues[1][0];                                                                    //sets the third value of the inverse matrix to minus the third value of the given matrix
(*m3).mValues[1][1] = m2.mValues[0][0];                                                                          //sets the fourth value of the inverse matrix to the first value of the given matrix
float recip = (1/determinant);                                                                                     // defines a float 'recip' to store the value of the reciprocal of the determinant
(*m3).mValues[0][0] = m3->mValues[0][0]*recip;                               // multiplies each value in the inverse matrix by the recip variable, and sets it as the new value of the inverse matrix
(*m3).mValues[0][1] = m3->mValues[0][1]*recip;
(*m3).mValues[1][0] = m3->mValues[1][0]*recip;
(*m3).mValues[1][1] = m3->mValues[1][1]*recip;
matrixDisplay(*m3);                                                                                                                                 // displays the final value of the inverse matrix
}
