#include <stdio.h>
#include <string.h>

#define LimitNum 16
#define ChangeNum 5

// Word-input function
void Get_str(char* str, int size)
{
	int st;
	int i = 0;

	printf("Enter a word: ");
	st = getchar();
	while ((st != '\n') && i < size - 1)
	{
		str[i] = st;
		i++;
		st = getchar();
	}
	str[i] = '\0';
}
// Function of omit the word
void Change(char* str, int size)
{
	int len = strlen(str);
	char star[LimitNum] = "**********";

	str[ChangeNum] = '\0';
	strncat(str, star, len - ChangeNum); // From the 6th letter, express it in a star shape
}

int main()
{
	char str[LimitNum];
	char Change_str[LimitNum];

	Get_str(str, sizeof(str));
	strcpy(Change_str, str);
	if (strlen(str) > ChangeNum)
	{
		Change(Change_str, sizeof(Change_str));
	}
	printf("Word entered: %s, Omitted words:%s\n", str, Change_str);

	return 0;
}