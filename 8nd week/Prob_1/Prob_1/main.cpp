#include <stdio.h>
#include <string.h>

#define Copy_size 1
#define Size 80

int main()
{
	char str[Size];

	strcpy(str, "wine");              // Copy and paste wine into str
	strcat(str, "apple");             // Stack apple on str
	strncpy(str, "pear", Copy_size);  // Copy pear as many as Copy_size and paste it into str
	printf("%s\n", str);
	return 0;
}