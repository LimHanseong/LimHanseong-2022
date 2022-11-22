#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Size 1000
#define Extension_Location 1

void PrintPath(int count, char* truncated_path[Size] = { NULL, })
{
	int i;
	
	for (i = 0; i < count - Extension_Location; i++)
	{
		printf("%s\\", truncated_path[i]);
	}
	printf("%s\n", truncated_path[count - Extension_Location]);
}

int main()
{
	char Path[Size] = "C:\\Document\\Github\\Test1\\test.txt";
	char* pPath = Path;
	char* truncated_path[Size] = { NULL, };
	char* context;
	char* split = strtok_s(pPath, "\\", &context);
	int count = 0;

	while (split != NULL)
	{
		truncated_path[count] = split;
		count++;
		split = strtok_s(NULL, "\\", &context);
	}
	
	printf("Original file path: ");
	PrintPath(count, truncated_path);

	split = strtok_s(truncated_path[count - Extension_Location], ".", &context);
	
	count = 0;
	while (split != NULL)
	{
		truncated_path[count] = split;
		count++;
		split = strtok_s(NULL, ".", &context);
	}

	printf("File name: %s, Extension name: %s\n", truncated_path[0], truncated_path[1]);

	return 0;
}