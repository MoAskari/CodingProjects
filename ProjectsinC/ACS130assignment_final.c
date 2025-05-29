/* Program: ACS130 Individual C Programming Assignment 1
Author: Mohammad Askari
Date submitted: 08/11/2021

-------------------------------------------------------------------------------------------------
The code given below is designed to read a series of characters (numbers, letters and symbols)
inputted by the user on a single line, and write each of those characters to a separate file
('File1.txt') after checking that the file exists.

The file is then closed, and opened again for reading, after which only the numbers which
are read from the file are returned to the screen, with each digit on a separate line.

The code then prints the number of numbers entered by the user, and the sum of these numbers.

Using a separate function defined underneath the main function, the mean of the numbers
entered by the user is calculated using the number of numbers entered and their sum. This
function contains no printf statements. If no numbers are entered by the user, the
function returns a value of 0, and the code tells the user that a mean could not be found
for this reason.

Following this, the code prints the value of the mean calculated to 2 decimal places.
The code then asks the user if they would like to repeat the program (y/n) and waits for
an input. If y is entered, it repeats. If n is entered, it thanks the user and ends the
program, and if neither of those characters is entered, it tells the user to try again,
asking for either a y or n to continue or stop the program.
----------------------------------------------------------------------------------------------*/

#include <stdio.h>                                                                                          // Defines the library being used, stdio.h

float mean(float sum, float N);                                                                             // Defines the function prototype for the mean function

void main()                                                                                                 // Opens the main function
{
char character; char repeatchar;                                                                            // Defines the variables character and repeatchar as characters.
int avalue; int count = 0; int sum = 0; int rvalue = 0; int repeat = 1;                                     // Defines the integer variables avalue, count, sum, rvalue and repeat, with their ascribed values

// TASK 1: Reads characters from the user's input and writes them to the file 'File1.txt' one at a time, after checking that the file exists.

do{                                                                                                         // Opens a do while loop, which loops the entire program after ending, if the user requests to do so (y/n)

    FILE *myFile = fopen("File1.txt","r");                                                                  // Opens the file 'File1.txt' for reading (to check if it exists)
    if (myFile == NULL)                                                                                     // Condition to stop the program if the file 'File1.txt' isn't found
        {
        printf("The file could not be found.\n");                                                           // Tells the user that the file wasn't found
        fclose(myFile);                                                                                     // Closes the file
        return 0;                                                                                           // Ends the program
        }
    else                                                                                                    // If the file is found, enters the main program
        {
        fclose(myFile);                                                                                     // Closes the file 'File1.txt'
        fopen("File1.txt","w");                                                                             // Opens the file 'File1.txt' for writing
        fprintf(myFile,"");                                                                                 // Prints empty space to the file, overwriting all previous text
        printf("\nPlease enter a combination of letters, numbers and symbols:\n");                          // Asks the user for an input of letters, numbers and symbols
        while ((character = getchar())!= '\n')                                                              // Loops through each of the characters inputted by the user, printing them to the file until the end of the input is reached
            {                                                                                               // Once the last character ('new line') is reached, the program moves on.
            fputc(character, myFile);                                                                       // Prints the scanned character to the file.
            }
        }
    fclose(myFile);                                                                                         // Closes the file 'File1.txt'

// TASKS 2 AND 3: Reads the characters from the file, printing only the numbers to the screen, and then prints the count of how many numbers there are, as well as their sum

    myFile=fopen("File1.txt","r");                                                                          // Opens the file for reading
    printf("Numbers found in the line:\n");                                                                 // Tells the user what numbers are found in the line
    while(avalue!=EOF)                                                                                      // Loops through the file one character at a time, until the end (EOF) with the declared variable avalue (meaning ASCII value)
      {
        avalue=fgetc(myFile);                                                                               // Ascribes the ASCII value of each scanned character to the variable 'avalue' (since avalue is an integer variable, not a character)
        if (avalue>= 48 && avalue<= 57)                                                                     // Condition to only accept values of 'avalue' between 48 and 57 (in the ASCII table, this covers the numbers 0 to 9)
            {
            putchar(avalue);                                                                                // Displays the value of the character on the screen (hence only displaying the numbers)
            printf("\n");                                                                                   // Starts a new line
            count++;                                                                                        // Adds one to the count variable
            rvalue = avalue - 48;                                                                           // Defines the real value of the scanned number as the ASCII value (avalue) minus 48 (the ASCII value of 0)
            sum = sum + rvalue;                                                                             // Defines the sum variable as its value from the previous iteration plus the real value of the scanned number
            }
      }
    fclose(myFile);                                                                                         // Closes the file
    printf("The number of numbers is %d \n",count);                                                         // Tells the user the number of numbers found in the file using the count variable
    printf("The sum of numbers is %d \n",sum);                                                              // Tells the user the sum of numbers found in the file using the sum variable
    float average = mean(sum,count);                                                                        // Calls the function to calculate the mean of the numbers inputted
    if (average == 0)                                                                                       // If the returned value of the mean function is 0
        {
        printf("No numbers were found in the input, so a mean could not be calculated. \n");                // Tells the user that no numbers were scanned, so a mean cannot be found
        }
    else                                                                                                    // Otherwise, if the mean function returns anything other than 0
        {
        printf("The mean of the numbers is %.2f",average);                                                  // Tells the user the mean of the numbers found to two decimal places
        }
    repeat = 2;                                                                                             // Sets the repeat variable to 2, allowing the program to keep looping through the 'yes/no response' loop
    while (repeat == 2)                                                                                     // Creates a while loop to ask the user if they would like to run the program again
    {
        printf("\nWould you like to run the program again? (y/n)");                                         // Asks the user if they would like to run the program again
        repeatchar = getchar();                                                                             // Requests a single character input from the user
        if (repeatchar == 'y')                                                                              // If the character inputted is y
            {
            printf("\nRepeating program...");                                                               // Tells the user that the program will repeat
            repeat = 1;                                                                                     // Sets the value of repeat to 1, which causes it to break out of the first loop, but not the second, hence repeating the program.
            }
        else if (repeatchar == 'n')                                                                         // If the character inputted is n
            {
            printf("\nThank you for using this program. Terminating...");                                   // Thanks the user for using the program
            return 0;                                                                                       // Ends the program
            }
        else                                                                                                // For any other inputs which aren't y or n
            {
            printf("\nNeither of the requested characters were entered. Please enter either y or n.");      // Tells the user that neither of the requested inputs were entered, and they should try again
            repeat = 2;                                                                                     // Sets the value of repeat to 2, to go back and ask the user if they'd like to repeat the program again.
            }
    }
    avalue = 0; count = 0; sum = 0; rvalue = 0;                                                             // To prepare for the program to run a second time, the values of all relevant variables are reset to 0
    fflush(stdin);                                                                                          // Clears the input buffer memory
    fflush(stdout);                                                                                         // Clears the output buffer memory
    }while (repeat = 1);                                                                                    // The second part of the do while loop, which repeats the entire program while the integer value of repeat is equal to 1.
}

// TASK 4: Defining the mean function, which either calculates a mean value and returns it to main, or returns 0 if no numbers are input, with no printf statements involved

float mean(float sum, float N)                                                                              // Defines the mean function
{
    if (N==0)                                                                                               // Condition to return 0 from the function if the value of N is 0 (if no numbers are scanned)
        {
        return 0;                                                                                           // Returns the value 0 from the function
        }
    else                                                                                                    // If the value of N is anything other than 0 (so at least one number is found)
        {
        float avg = sum/N;                                                                                  // Declares the variable 'avg' as the sum of numbers divided by how many there are (N)
        return avg;                                                                                         // Returns the average calculated from the function
        }
}
