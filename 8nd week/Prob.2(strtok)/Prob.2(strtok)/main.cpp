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

void SplitPath(int count, char* ext_split[Size] = { NULL, }, char* truncated_path[Size] = { NULL, })
{
	char ext[Size];
	char rename[Size];

	printf("Rename the file: ");
	scanf_s("%s", rename,Size);
	strcpy_s(ext, ext_split[Extension_Location]);
	strcpy_s(truncated_path[count - Extension_Location], Size, rename);
	strcat_s(truncated_path[count - Extension_Location], Size, ext);
}

int main()
{
	char Path[Size] = "C:\\Document\\Github\\Test1\\test.txt";
	char* pPath = Path;
	char* truncated_path[Size] = { NULL, };
	char* context;
	char* split = strtok_s(pPath, "\\", &context);
	char* ext_split[Size] = { NULL, };
	
	
	int count1 = 0;
	while (split != NULL)
	{
		truncated_path[count1] = split;
		count1++;
		split = strtok_s(NULL, "\\", &context);
	}
	printf("Original file path: ");
	PrintPath(count1, truncated_path);

	split = strtok_s(truncated_path[count1 - Extension_Location], ".", &context);
	
	int count2 = 0;
	while (split != NULL)
	{
		ext_split[count2] = split;
		count2++;
		split = strtok_s(NULL, ".", &context);
	}

	SplitPath(count1, ext_split, truncated_path);

	printf("Changed path: ");
	PrintPath(count1, truncated_path);

	return 0;
}

