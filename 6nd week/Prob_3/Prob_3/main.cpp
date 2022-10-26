#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINE 3
#define ROW 4
#define START_NUM 100

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

//Creating a Printer Function
void print_arry(int p_arry[LINE][LINE])
{
	int x, y;
	int(*print)[LINE] = p_arry;
	
	for (x = 0; x < LINE; x++)
	{
		for (y = 0; y < LINE; y++)
		{
			printf("%d\t", print[x][y]);
		}
		printf("\n");
	}

	printf("\n");
	return;
}

// Functions that multiply and output matrices
int matrix_mul(int m1[LINE][ROW], int m2[ROW][LINE])
{
	int x, y, z;
	int Res[LINE][LINE];
	int (* R_pt)[LINE] = Res;
	int(*m1_pt)[ROW] = m1;
	int(*m2_pt)[LINE] = m2;

	for (x = 0; x < LINE; x++) // Specifying rows in an array
	{
		for (y = 0; y < LINE; y++) // Specifying line in an array
		{
			R_pt[x][y] = {0};
			for (z = 0; z < ROW; z++)
			{
				R_pt[x][y] += m1_pt[x][z] * m2_pt[z][y]; // Store calculated values in the specified array space
			}
		}
	}
	print_arry(R_pt);

	return 0;
}

int main()
{
	// Seed assignment
	InitializationRandSeed();

	// Initialize variables
	int nRange = START_NUM;
	int matrix_1[LINE][ROW];
	int matrix_2[ROW][LINE];
	int i, j;
	int(*m_1_pt)[ROW] = matrix_1;
	int(*m_2_pt)[LINE] = matrix_2;

	printf("Matrix 1\n");
	//Set the initial value of matrix_1 with any integer
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j < ROW; j++)
		{
			m_1_pt[i][j] = (float)CreatRandNum(nRange);
			printf("%d\t", m_1_pt[i][j]);
		}
		printf("\n");
	}
	printf("Matrix 2\n");
	//Set the initial value of matrix_2 with any integer
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < LINE; j++)
		{
			m_2_pt[i][j] = (float)CreatRandNum(nRange);
			printf("%d\t", m_2_pt[i][j]);
		}
		printf("\n");
	}

	printf("Calculation result\n=>\n");
	// Recall matrix multiplication function
	matrix_mul(m_1_pt, m_2_pt);

	return 0;
}