/*************************************/
/* NAME : Free_Pointer               */
/* DATE : 2020.07.01                 */
/*************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Display(char*);

void main()
{
	char* ptr1, * ptr2, * ptr3;
	int i;

	ptr1 = (char*)malloc(10);
	memset(ptr1, 0x00, sizeof(10));
	ptr2 = ptr3 = ptr1;

	for (i = 0; i < 10; i++)
	{
		*ptr2++ = 'A' + i;
		printf("ptr : %c\n", *(ptr1+ i));
	}
	printf("Display Before Free\n");
	Display(ptr3);
	free(ptr1);

	printf("free ptr1 !! \n");
	Display(ptr3);

}
void Display(char* ptr)
{
	int i;
	for (i = 0; i < 10; i++)
		printf("ptr : %c\n", *ptr++);
}