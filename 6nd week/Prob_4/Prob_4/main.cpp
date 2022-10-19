#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10
#define START_NUM 100
#define END_NUM 0
#define Ascending_order 1
#define Descending_order 2

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

int print_ary(int* pa)
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		printf("%5d", pa[i]);
	}
	printf("\n");
	return 0;
}

void ascending_order(int* num)
{
	int i, j;
	int temp;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (num[i] < num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	printf("ascending order: ");
	print_ary(num);
	
	return;
}

void descending_order(int* num)
{
	int i, j;
	int temp;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (num[i] > num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	printf("decending order: ");
	print_ary(num);
	
	return;
}

int main()
{
	// Seed assignment
	GenRandSeed();

	int nRange = START_NUM;
	int RNum[SIZE]={0};
	int* pt = RNum;
	int i;
	int type;

	for (i = 0; i < SIZE; i++)
	{
		pt[i] = GenRandNum(nRange);
	}
	print_ary(pt);

	while (1)
	{
		printf("\nChoose the array order you want.\n1.ascending order\n2.descending_order\n(Press 0 to exit)\n=>");
		scanf_s("%d", &type);

		// Escape when entering the end number
		if (type == END_NUM)
		{
			break;
		}
		else if (type == Ascending_order)
		{
			ascending_order(pt);
		}
		else if (type == Descending_order)
		{
			descending_order(pt);
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