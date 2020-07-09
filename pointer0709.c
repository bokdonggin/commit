/* DATE : 2020.07.09 */
/* NAME : BOKDONGJIN */
/* POINTER           */

#include<stdio.h>
#include<stdlib.h>

char* AddString(char*, char*);
int main()
{
	char data_1[80] = "i am bokdongjin";
	char data_2[80] = "who that";
	char* ret;

	ret = AddString(data_1, data_2);

	printf("data 1 : [%s]", data_1);
	printf("data 2 : [%s]", data_2);
	printf("ret    : [%s]", ret   );

	return 0;
}

char* AddString(char* src1, char* src2)
{
	char* ret, * ptr;
	ptr = (char*)malloc(strlen(src1) + strlen(src2) + 1);
	ret = ptr;
	while (*src1)
		*ptr++ = *src1++;

	while (*src2)
		*ptr++ = *src2++;
	*ptr = '\0';

	return ret;
}