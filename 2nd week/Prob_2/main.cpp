#include<stdio.h>

int main()
{
	char ch;                      // Specify a variable to store characters with ch

	printf("Character input : "); // Output input information message
	scanf_s("%c", &ch);           // Scan typed characters
	printf("The ASCII code value of the '%c' character is '%d'.", ch, ch); // Convert and inform
	return 0;
}