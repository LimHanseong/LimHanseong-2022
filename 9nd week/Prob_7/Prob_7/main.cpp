#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NameLength 20
#define Size 6
#define PeopleNum 5
#define SubjectsNum 3
#define Acut 90
#define Bcut 80
#define Ccut 70

// Declaration of Structure
struct Grade
{
	int StudentNum;
	char StudentName[NameLength];
	float math;
	float eng;
	float kor;
	float total;
	float aver;
	char grade;
};
// Functions that enter information
void fInput(Grade list[Size])
{
	int i;
	struct Grade* plist = list;
	
	for (i = 0; i < PeopleNum; i++)
	{
		printf("Student number: ");
		scanf_s("%d", &(plist[i].StudentNum));
		printf("Student name: ");
		scanf_s("%s", plist[i].StudentName, NameLength);
		printf("korean, english, math score: ");
		scanf_s("%f%f%f", &(plist[i].kor), &(plist[i].eng), &(plist[i].math));
	}
}
// Function to calculate total points
void fTotal(Grade list[Size])
{
	int i;
	struct Grade* plist = list;

	for (i = 0; i < PeopleNum; i++)
	{
		list[i].total = list[i].kor + list[i].eng + list[i].math;
	}
}
// A function to obtain average
void fAverage(Grade list[Size])
{
	int i;
	struct Grade* plist = list;

	for (i = 0; i < PeopleNum; i++)
	{
		list[i].aver = plist[i].total / SubjectsNum;
	}
}
// A function that is graded according to the rating
void fGrade(Grade list[Size])
{
	int i;
	struct Grade* plist = list;

	for (i = 0; i < PeopleNum; i++)
	{
		if (plist[i].aver >= Acut)
		{
			plist[i].grade = 'A';
		}
		else if (plist[i].aver >= Bcut)
		{
			plist[i].grade = 'B';
		}
		else if (plist[i].aver >= Ccut)
		{
			plist[i].grade = 'C';
		}
		else
		{
			plist[i].grade = 'F';
		}
	}
}
// Functions arranged in order of high total points
void fSwap(Grade list[Size])
{
	int i, j;
	Grade temp;
	struct Grade* plist = list;

	for (i = 0; i < PeopleNum; i++) // Specify a number to compare
	{
		for (j = 0; j < PeopleNum; j++) // Compare to other numbers

		{
			if (plist[i].total > plist[j].total) //Replace place if the number you compare is greater than the other number
			{
				temp = plist[i];
				plist[i] = plist[j];
				plist[j] = temp;
			}
		}
	}
}
// Function that outputs structure information
void fPrint(Grade list[Size])
{
	int i;
	struct Grade* plist = list;

	for (i = 0; i < PeopleNum; i++)
	{
		printf("%3d%7s%4.0f%4.0f%4.0f%5.0f%7.1f%3c\n",
			plist[i].StudentNum, plist[i].StudentName, plist[i].kor, plist[i].eng, plist[i].math, plist[i].total, plist[i].aver, plist[i].grade);
	}
}

int main()
{
	// Declare structure arrangement
	struct Grade list[Size];
	struct Grade *plist = list;

	fInput(plist);
	// Derive required calculations
	fTotal(plist);
	fAverage(plist);
	fGrade(plist);
	// Output in the order entered
	printf("\n# Data before swap...\n");
	fPrint(plist);
	// Output in total score order
	fSwap(plist);
	printf("\n# Data after swap...\n");
	fPrint(plist);

	return 0;
}