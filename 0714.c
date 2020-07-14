#include<stdio.h>

#define TRUE  1
#define FALSE 0

int TrimString(char*);

void main()
{
	char data[80] = "##i am superman !! who are you?";
	int ret = 0;
	printf("data = [%s]\n", data);

	ret = TrimString(data);
	if (ret == TRUE)
	{
		printf("change of data = [%s] \n", data);
	}
	else
	{
		printf("Error of TrimString\n");
	}
}

int TrimString(char* src)
{
	char* ptr;
	ptr = src;

	if (src == NULL)
	{
		return FALSE;
	}
	while (*src)
	{
		if ((*src >= 'A' && *src <= 'Z') || (*src >= 'a' && *src <= 'z'))
		{
			*ptr++ = *src++;
		}
		else
			src++;
	}
	*ptr = '\0';

	return TRUE;
}