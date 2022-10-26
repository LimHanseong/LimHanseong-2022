#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>    //Header file declared to use the sqrt function

#define END_NUM 0
#define START_NUM 100
#define ARRAY_SIZE 6
#define SIZE 5
#define AVERAGE 1
#define VARIANCE 2
#define STANDARD_DEVIATION 3

// Initialize seed numbers using time clock information
void InitializationRandSeed()
{
	// Generate random numbers using time seeds
	srand((unsigned int)(time(NULL)));
	return;
}

// Random number creation
unsigned int CreatRandNum(unsigned int nRange)
{
	unsigned int res = 0;
	unsigned int num = rand();
	res = ((unsigned int)(num) % (nRange));
	return res;
}

//Generate Mean Calculation Function
float Average(float RNum[ARRAY_SIZE])
{
	float res = 0;
	float sum = 0;
	int i;
	float* pt = RNum;

	for (i = 0; i < SIZE; i++)
	{
		sum += pt[i];
	}
	res = sum / SIZE;
	return res;
}

//Create a function to obtain variance
float Variance(float RNum[ARRAY_SIZE])
{
	float res = 0;
	float sum = 0;
	int i;
	float* pt = RNum;

	for (i = 0; i < SIZE; i++)
	{
		sum += (pt[i] - Average(pt)) * (pt[i] - Average(pt));
	}
	res = sum / SIZE;
	return res;
}

//Generate a function to obtain standard deviations
float Standard_deviation(float RNum[ARRAY_SIZE])
{
	float res = 0;
	float* pt = RNum;

	res = sqrt(Variance(pt));
	return res;
}

int main(void)
{
	// Seed assignment
	InitializationRandSeed();

	// Initialize variables
	int nRange = START_NUM;
	int type = 0;
	float RandNum[ARRAY_SIZE];
	float* RNum = RandNum;
	float res;

	int i, k;

	printf("Let's generate a random number.\n");
	
	// Create a random number and save it to an array
	for (i = 0; i < SIZE; i++)
	{
		RNum[i] = (float)CreatRandNum(nRange);
	}
	// Show generated random numbers
	printf("Generated number:");
	for (k = 0; k < SIZE; k++)
	{
		printf("%5.0f", RNum[k]);
	}
	// Select Average, Variances, and Standard Deviations to view results
	while (1)
	{
		printf("\nChoose the calculation you want.\n1.Average\n2.Variance\n3.Standard deviation\n(Press 0 to exit)\n=>");
		scanf_s("%d", &type);
		// Escape when entering the end number
		if (type == END_NUM)
		{
			break;
		}
		else if (type == AVERAGE)
		{
			res = Average(RNum);
			printf("\nAverage: %.2f\n", res);
		}
		else if(type == VARIANCE)
		{
			res = Variance(RNum);
			printf("\nVariance: %.2f\n", res);
		} 
		else if(type == STANDARD_DEVIATION)
		{
			res = Standard_deviation(RNum);
			printf("\nStandard deviation: %.2f\n", res);
		}
		else
		{
			printf("\nThis is not a valid input. Please re-enter.\n");
		}
	}
	printf("Exit the program\n");

	system("pause");
	return 0;
}