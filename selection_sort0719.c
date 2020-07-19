/* name : bokdongjin */
/* date : 2020.07.19 */

#include<stdio.h>
#include<stdlib.h>

#define LIMIT 100

void sel_sort(void);
int  array_data[LIMIT];

void sel_sort(void)
{
	int i, j, min, temp;
	for (i = 0; i < LIMIT; i++)
	{
		min = i;
		for (j = i + 1; j < LIMIT; j++)
		{
			if (array_data[j] < array_data[min])
				min = j;
		}
		temp = array_data[min];
		array_data[min] = array_data[i];
		array_data[i] = temp;
	}
}

int main()
{
	int data = 0;
	int i = 0;

	for (i = 0; i < LIMIT; i++)
	{
		data = rand() % LIMIT;
		array_data[i] = data;
		printf("%4d", array_data[i]);
		if ((i % 10) == 9)
			printf("\n");
	}

	printf("\n");

	sel_sort();

	for (i = 0; i < LIMIT; i++)
	{
		printf("%4d", array_data[i]);
		if ((i % 10) == 9)
			printf("\n");
	}

	printf("\n");
}