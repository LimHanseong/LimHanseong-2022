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
	Res = Num / Range;
	return Res;
}

int print_ary(double* print)
{
	int i;
	for (i = 0; i < ARRY_SIZE; i++)
	{
		printf("%lf\n", print[i]);
	}
	printf("\n");
	return 0;
}

int main()
{
	int Range = RAND_MAX;
	double X_1[ARRY_SIZE];
	double X_2[ARRY_SIZE];
	double V, Z, K;
	int count = 0;
	double Z_arry[ARRY_SIZE];
	int i;
	double f_x_1[ARRY_SIZE];
	double f_x_2[ARRY_SIZE];

	for (;;)
	{
		double r_1 = GenRandNum(Range);
		double r_2 = GenRandNum(Range);
		V = sqrt(2 / exp(1.0)) * (2 * r_2 - 1);
		Z = V / r_1;
		K = (Z * Z) / 4;

		if (K < 1 - r_1)
		{
			Z_arry[count] = Z;
			count++;
		}
		else if ((K >= 0.259 / r_1) + 0.35 || K > -log(r_1))
		{
			r_1 = 0;
			r_2 = 0;
		}
		
		if (count == 100) break;
	}

	X_1[1] = AVERAGE_1 + Z_arry[1] * STD_DEVIATION_1;
	X_2[1] = AVERAGE_2 + Z_arry[1] * STD_DEVIATION_2;


	f_x_1[1] = 1 / sqrt(2 * M_PI * STD_DEVIATION_1) * pow(exp(1.0), -0.5 * pow(X_1[1] - AVERAGE_1, 2.0));


	printf("X_1: %lf\n", X_1[1]);
	printf("f_x_1: %lf\n", f_x_1[1]);

	return 0;
}