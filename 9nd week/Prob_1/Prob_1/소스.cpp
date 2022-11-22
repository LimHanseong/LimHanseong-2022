#include<stdio.h>
#include<stdlib.h>

#define MinNum 2 // Minimum Input Number
#define LineChange 5 // Number of numbers to output per line

// A function that outputs an array of prime numbers
void print_ary(int Max_PrimeNum, char* Ary)
{
	int i, j;
	int count = 0;

	for (i = MinNum; i <= Max_PrimeNum; i++)
	{
		for (j = MinNum; j <= i; j++)
		{
			if ((i % j) == 0)
			{
				if (i > j)
				{
					printf("%5c", Ary[i]);
					count++;
					if (count % LineChange == 0) printf("\n");
					break;
				}
				else
				{
					printf("%5d", Ary[i]);
					count++;
					if (count % LineChange == 0) printf("\n");
				}
			}
		}
	}
}
// A function that determines prime numbers and stores them in an array
int Get_PrimeNum(int number, char* Ary)
{
	int i, j;
	int count = 0;
	int Max_PrimeNum = 0;

	for (i = MinNum; i <= number; i++)
	{
		for (j = MinNum; j <= i; j++)
		{
			if ((i % j) == 0)
			{
				//If it's not a prime number, save X and escape
				if (i > j)
				{
					Ary[i] = 'X';
					break;
				}
				//Store numbers if they are prime number
				else
				{
					Ary[i] = i;
					Max_PrimeNum = j;
				}
			}
		}
	}

	return Max_PrimeNum;
}

int main()
{
	// Declare and initialize variables
	int i, j;
	int number;
	int count = 0;
	char* Ary;
	int Max_PrimeNum = 0;

	// Get numeric input
	printf("Enter an integer greater than or equal to 2: ");
	scanf_s("%d", &number);
	// Dynamic allocation of pointer memory
	Ary = (char*)malloc(sizeof(number));

	Max_PrimeNum = Get_PrimeNum(number, Ary);

	print_ary(Max_PrimeNum, Ary);

	return 0;
}