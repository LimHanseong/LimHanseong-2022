#include <stdio.h>
#include<stdlib.h>
#include <string.h>

char* FileName_Extraction(char Path[80])
{
	char * fName = 0;
	char* pPath = Path;

	while (* pPath)
	{
		if (* pPath == '\\' && (pPath +1) != NULL)
		{
			fName = pPath + 1;
		}
		pPath++;
	}
	return fName;
}

char *Ext_Extraction(char Name[80])
{
	char* fName = Name;
	int len = strlen(fName);
	fName += len;
	char* ext = 0;
	int i;

	for (i = 0; i < len; i++)
	{
		if (*fName == '.')
		{
			ext = fName + 1;
			break;
		}
		fName--;
	}
	return ext;
}


int main()
{
	char Path[80] = "C:\\Document\\Github\\Test1\\test.txt";
	char* pPath = Path;
	char* ext;
	char* fName;
	int i;

	fName = FileName_Extraction(pPath);
	ext = Ext_Extraction(fName);
	printf("File name: %s, Extension : %s\n",fName, ext);

	return 0;
}