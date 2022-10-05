#include<stdio.h>
#include<stdlib.h>

#define MINIMUMNUMBER 2 // Minimum Input Number
#define LINENUMBERMAX 5 // Number of numbers to output per line

int main()
{
	int i, j;    // Specifies the variable to use in the for statement. We will assume that i is a prime number and use j to determine if i is a prime number.
	int number;  // Specify the variable to store the number you received.
	int count=0; // Specify variables to count numbers to replace lines for every five numbers

	printf("Enter an integer greater than or equal to 2: ");
	scanf_s("%d", &number);

	for (i = MINIMUMNUMBER; i <= number; i++) // Check all numbers less than or equal to the number entered are prime
	{
		for (j = MINIMUMNUMBER; j <= i; j++)  // Determining whether it is a prime number
		{
			if ((i % j) == 0)                 // divide i by j and check the rest
			{
				if (i > j)break;              // If i is divided by a number less than i, it escapes.
				else                          // Otherwise, print the value
				{
					printf("%5d", i);
					count++;                  // Counting the number of outputs
					if (count% LINENUMBERMAX == 0) 
					printf("\n");             // If printed out 5 numbers, replace the line
				}
			}
		}
	}
	system("pause");
	return 0;
}