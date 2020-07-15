/********************************/
/* name : bokdongjin            */
/* date : 2020.07.15            */
/********************************/

#include<stdio.h>

char* TrimString(char*);

void main()
{
	char data[80] = "1243gfsdads324%^^.wefw58///21";
	char* ret;

	ret = TrimString(data);

	printf("[%s]", ret);

}

char* TrimString(char* src)
{
	char* ret, * ptr;

	ret = src;
	ptr = src;

	while (*src)
	{
		if ((*src >= 'A' && *src <= 'Z') || (*src >= 'a' && *src <= 'z')) {
			*ptr++ = *src++;
		}
		else
			src++;
	}

	*ptr = '\0';

	return ret;
}