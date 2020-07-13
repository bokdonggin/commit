/************************************/
/* NAME : BOK DONG JIN              */
/* DATE : 2020.07.13                */
/************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#define SET 1
#define CLR 0
#define TRUE 1
#define FALSE 0

char* AddString(char*, char*);
char* CreateMemory(int);
int   DeleteMemory(char*);

void main()
{
	char data_1[80] = "i am superman";
	char data_2[80] = "who are you";

	char* ptr = NULL;
	int ret = CLR;
	
	ptr = AddString(data_1, data_2);

	if (ptr)
	{
		printf("%s\n", ptr);
	}

	ret = DeleteMemory(ptr);

	ptr = NULL;
}

char* AddString(char* src1, char* src2)
{
	int ptrSize = 0;
	int flag = CLR;
	char* retPtr = NULL;
	char* tempPtr = NULL;

	ptrSize = strlen(src1) + strlen(src2);
	retPtr = CreateMemory(ptrSize);
	tempPtr = retPtr;

	if (retPtr)
	{
		while (*src1)
			*retPtr++ = *src1++;
		while (*src2)
			*retPtr++ = *src2++;
		*retPtr = '\0';
		return tempPtr;
	}
	else
	{
		return NULL;
	}
}

char* CreateMemory(int size)
{
	char* p = NULL;
	if (!p)
	{
		p = (char*)malloc(size + 1);
		return p;
	}
	else
		return NULL;
}

int DeleteMemory(char* p)
{
	if (p)
	{
		free(p);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}