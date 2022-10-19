#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINE 3
#define ROW 4
#define START_NUM 100

// Generate a seed number using time clock information
void GenRandSeed()
{
	// Generate random numbers using time seeds
	srand((unsigned int)(time(NULL)));
	return;
}

// Random number generation
unsigned int GenRandNum(unsigned int nRange)
{
	
	unsigned int nRes = 0;
	unsigned int nNum = rand();
	nRes = ((unsigned int)(nNum) % (nRange));
	return nRes;
}

int matrix_mul(int n1[LINE][ROW], int n2[ROW][LINE])
{
	int x, y, z;
	int Res[LINE][LINE];

	for (x = 0; x < LINE; x++)
	{
		for (y = 0; y < LINE; y++)
		{
			Res[x][y] = {0};
			for (z = 0; z < ROW; z++)
			{
				Res[x][y] += n1[x][z] * n2[z][y];
			}
		}
	}

	for (x = 0; x < LINE; x++)
	{
		for (y = 0; y < LINE; y++)
		{
			printf("%d\t", Res[x][y]);
		}
		printf("\n");
	}
	return 0;
}

int main()
{
	GenRandSeed();

	int nRange = START_NUM;
	int matrix_1[LINE][ROW];
	int matrix_2[ROW][LINE];
	int i, j;
	int x, y;

	printf("Matrix 1\n");
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j < ROW; j++)
		{
			matrix_1[i][j] = (float)GenRandNum(nRange);
			printf("%d\t", matrix_1[i][j]);
		}
		printf("\n");
	}
	printf("Matrix 2\n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < LINE; j++)
		{
			matrix_2[i][j] = (float)GenRandNum(nRange);
			printf("%d\t", matrix_2[i][j]);
		}
		printf("\n");
	}

	printf("Calculation result\n=>\n");
	matrix_mul(matrix_1, matrix_2);

	return 0;
}