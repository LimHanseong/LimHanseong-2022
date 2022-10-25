#include<stdio.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<time.h>

#define ARRY_SIZE 100
#define AVERAGE_1 0
#define AVERAGE_2 0
#define STD_DEVIATION_1 1
#define STD_DEVIATION_2 1.2
#define RAND_MAX 32767
#define f_x_1_MIN 0.2419707245191
#define f_x_2_MIN 0.2861537987567
#define change_percent 100

// Generate a seed number using time clock information
void GenRandSeed()
{
	// Generate random numbers using time seeds
	srand((unsigned int)(time(NULL)));
	return;
}

// Random number generation
double GenRandNum(double Range)
{
	double Res = 0;
	double Num = rand();
	Res = Num / Range;   // Divide by maximum of rand
	return Res;
}

int main()
{
	// Seed number assignment
	GenRandSeed();
	// Declare and initialize variables
	int Range = RAND_MAX;
	double X_1[ARRY_SIZE];
	double X_2[ARRY_SIZE];
	double V, Z, K;
	int count = 0;
	double Z_arry[ARRY_SIZE];
	int i;
	double f_x_1[ARRY_SIZE];
	double f_x_2[ARRY_SIZE];
	int hit = 0;
	double Rate = 0;

	// A function that obtains the value of K through the operation, finds 100 Zs for the condition, and stores them in the array
	for (;;)
	{
		double r_1 = GenRandNum(Range);
		double r_2 = GenRandNum(Range);
		
		V = sqrt(2 / exp(1.0)) * (2 * r_2 - 1); // Calculation process
		Z = V / r_1;
		K = (Z * Z) / 4;

		if (K < 1 - r_1)
		{
			Z_arry[count] = Z;
			count++;
		}
		else if ((K >= 0.259 / r_1) + 0.35 || K > -log(r_1)) // Generate a random number again if the following conditions are met:
		{
			r_1 = 0;
			r_2 = 0;
		}

		if (count == ARRY_SIZE) break; // If you fill up all 100, you can escape
	}

	// Function to obtain X_1 and X_2 using probability variable relational expressions
	for (i = 0; i < ARRY_SIZE; i++)
	{
		X_1[i] = AVERAGE_1 + Z_arry[i] * STD_DEVIATION_1;
		X_2[i] = AVERAGE_2 + Z_arry[i] * STD_DEVIATION_2;
	}

	// Substituting probability variables into normal distribution probability density functions to obtain results
	for (i = 0; i < ARRY_SIZE; i++)
	{
		f_x_1[i] = 1 / sqrt(2 * M_PI * STD_DEVIATION_1) * pow(exp(1.0), -0.5 * pow(X_1[i] - AVERAGE_1, 2.0));
	}
	for (i = 0; i < ARRY_SIZE; i++)
	{
		f_x_2[i] = 1 / sqrt(2 * M_PI * STD_DEVIATION_2) * pow(exp(1.0), -0.5 * pow(X_2[i] - AVERAGE_2, 2.0));
	}
	
	// A function that verifies that it is within the range of the hit
	for (i = 0; i < ARRY_SIZE; i++)
	{
		if (f_x_1[i] >= f_x_1_MIN && f_x_2[i] >= f_x_2_MIN)
		{
			hit++;
		}
	}
	
	// Finding the Hit Rate
	Rate = ((double)hit / ARRY_SIZE) * change_percent;

	// Output hit rate to second decimal place
	printf("accuracy rate: %.2lf%%", Rate);

	system("pause");
	return 0;
}