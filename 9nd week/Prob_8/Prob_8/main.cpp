#include <stdio.h>
#include <stdlib.h>

#define Size 100
// Enter the information entered in the new file
void fInput(FILE *fp, int integer, double real_number, char character, char string[80])
{
	fprintf(fp, "Integer: %d\n", integer);
	fprintf(fp, "Real number: %f\n", real_number);
	fprintf(fp, "Character: %c\n", character);
	fprintf(fp, "String: %s\n", string);
}
// Output information entered in a file
void fPrint(FILE* fp)
{
	int ch;
	printf("\nFile Contents: \n");

	fopen_s(&fp, "new.txt", "r");

	if (fp == NULL)
	{
		printf("The file will not open.\n");
	}
	while (1)
	{
		ch = fgetc(fp);
		putchar(ch);
		if (ch == EOF)
		{
			break;
		}
	}
}

int main()
{
	// Declare and initialize variables
	FILE* fp;
	int integer =0;
	float real_number=0;
	char character=0;
	char string[Size]={NULL, };
	char *pstring = string;
	
	// Create a new file
	fopen_s(&fp,"new.txt", "w");
	// Print if file creation fails
	if (fp == NULL)
	{
		printf("Failed to create file.\n");
		return 1;
	}
	// Get information to enter into a file
	printf("Input integer: ");
	scanf_s("%d", &integer);
	printf("Input real number: ");
	scanf_s("%f", &real_number);
	printf("Input character: ");
	scanf_s(" %c", &character,2);
	printf("Input string: ");
	scanf_s("%s", string, Size);
	// Enter the information entered in the new file
	fInput(fp, integer, real_number, character, pstring);
	fclose(fp);
	// Output information entered in a file
	fPrint(fp);
	fclose(fp);

	return 0;
}