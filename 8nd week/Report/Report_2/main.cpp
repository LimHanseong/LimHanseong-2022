#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Size 1000
#define Extension_Location 1

int main()
{
	char Path[Size] = "C:\\Document\\Github\\Test1\\test.txt";
	char* pPath = Path;
	char* truncated_path[Size] = { NULL, };
	int i = 0;
	char* split = strtok(pPath, "\\");
	int count1 = 0;
	char* ext_split[Size] = { NULL, };
	char ext[Size];

	while (split != NULL)
	{
		truncated_path[count1] = split;
		count1++;
		split = strtok(NULL, "\\");
	}
	printf("Original file path: ");
	for (i = 0; i < count1- Extension_Location; i++)
	{
		printf("%s\\", truncated_path[i]);
	}
	printf("%s\n", truncated_path[count1 - Extension_Location]);

	split = strtok(truncated_path[count1- Extension_Location], ".");
	int count2 = 0;
	while (split != NULL)
	{
		ext_split[count2] = split;
		count2++;
		split = strtok(NULL, ".");
	}

	printf("File name: %s, Extension name: %s\n", ext_split[0], ext_split[1]);
	
	strcpy(ext, ext_split[Extension_Location]);
	strcpy(truncated_path[count1 - Extension_Location], "test2.");
	strcat(truncated_path[count1 - Extension_Location], ext);

	printf("Changed path: ");
	for (i = 0; i < count1 - Extension_Location; i++)
	{
		printf("%s\\",truncated_path[i]);
	}
	printf("%s", truncated_path[count1 - Extension_Location]);

	return 0;
}