/* Program: prob1.c
Author: Mohammad Askari
Date written: 05/10/2021 */
/*.
2. Use arrays and pointers. Input 5 integer values from the keyboard and store these in an array,
using array indexing. Create a pointer that points to the array. Write a table to the screen:
• the first column containing the memory addresses of the array elements printed via the
pointer,
• the second column containing the memory addresses of the array elements printed via
the array name, and
• the third column containing the contents of the array printed via the pointer.

What do you notice about the memory address printed via the pointer and via the array
name? Repeat the operation with 5 float values and for 5 char values- you can add the
code to the same script. Observe the memory addresses: what patterns do you see for
each type? (For the char, you might need to add fflush(stdin) which flushes the buffer
to remove issues with reading in chars).
*/

/* SOLUTION: */

// Program to use arrays and pointers and look at memory addresses as well as contents of memory.
// Input 5 integer values from the keyboard and store these in an array, using array indexing.
// Write a table to the screen, with the first column containing the memory addresses
// of the array elements printed via the pointer, and the second column containing the memory addresses
// of the array elements printed via the array name, and the third column containing the
// contents of the array printed via the pointer.
// Repeat with floats and char
// TB  January 2021

#include <stdio.h>

#define SIZE 2

void main()
{
	int i;
	int intArray[SIZE];
	float floatArray[SIZE];
	char charArray[SIZE];

	int *ptrIntArray;
	float *ptrFloatArray;
	char *ptrCharArray;

	//assign pointers to arrays to point to the start of each array
	ptrIntArray=intArray;
	ptrFloatArray=floatArray;
	ptrCharArray=charArray;

	printf("enter %d integers: \n", SIZE);
	for(i=0; i<SIZE; i++)
	{
		scanf("%d", &intArray[i]);
	}
	printf("enter %d floats: \n", SIZE);
	for(i=0; i<SIZE; i++)
	{
		scanf("%f", &floatArray[i]);
	}
	printf("enter %d chars: \n", SIZE);
	for(i=0; i<SIZE; i++)
	{
	    fflush(stdin);
		scanf("%c", &charArray[i]);
		fflush(stdin);
	}


	printf("Memory address base 10\tMemory address integer\tcontents at address\n");
	printf("Integers:\n\n");
	for(i=0; i<SIZE; i++)
	{
		printf("%d\t\t\t%d\t\t\t%d\n",ptrIntArray+i,intArray+i,*(ptrIntArray+i));  // printing pointer without dereferencing will result in memory address being printed
	}
	printf("\nFloats:\n\n");
	for(i=0; i<SIZE; i++)
	{
		printf("%d\t\t\t%d\t\t\t%0.2f\n",ptrFloatArray+i,floatArray+i,*(ptrFloatArray+i));  // printing pointer without dereferencing will result in memory address being printed
	}
	printf("\nChars:\n\n");
	for(i=0; i<SIZE; i++)
	{
		printf("%d\t\t\t%d\t\t\t%c\n",ptrCharArray+i,charArray+i,*(ptrCharArray+i));  // printing pointer without dereferencing will result in memory address being printed
	}


}
