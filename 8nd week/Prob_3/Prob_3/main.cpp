#include <stdio.h>
#include <string.h>

#define size 80
#define WordNum 3
#define first 0
#define twice 1
#define third 2

// Functions that are sorted in the order that they appear in the dictionary
void Sort_in_order(char str[WordNum][size])
{
	int i, j;
	char(*pt)[size] = str;
	char temp[size];

	for (i = 0; i < WordNum; i++) // Specify a word to compare
	{
		for (j = i; j < WordNum; j++) // Compare to other words
		{
			if (strcmp(pt[i], pt[j])>0) //If a word to compare comes out faster than another word, replace it
			{
				strcpy_s(temp, pt[i]);
				strcpy_s(pt[i], pt[j]);
				strcpy_s(pt[j], temp);
			}
		}
	}
	printf("%s, %s, %s", pt[first], pt[twice], pt[third]);
}

int main()
{
	// Declare and initialize variables
	char str[WordNum][size];
	char(*pt)[size] = str;

	printf("Enter three words: ");
	scanf_s("%s%s%s", pt[first], size, pt[twice], size, pt[third], size);
	Sort_in_order(pt);

	return 0;
}