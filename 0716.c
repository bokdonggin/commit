/* name : bokdongjin */
/* date : 2020.07.16 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

typedef struct node {
	int  key;
	char counter;
}node;

void initData(void);
void makeData(void);
void dispData(void);
void dispTable(void);
void dispTableCounter(void);

int data[MAX];
node table[50];

void initData(void)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		data[i] = -1;
	}
	for (i = 0; i < 20; i++)
	{
		table[i].key = -1;
		table[i].counter = 0;
	}
}

void makeData(void)
{
	int i, num, index;
	i = 0;

	srand((unsigned)time(NULL));
	while (i < 50)
	{
		num = rand() % 100;
		data[num] = num;
		index = num % 50;
		table[index].key = num;
		table[index].counter++;
		i++;
	}
}

void dispTable(void)
{
	int i;
	for (i = 0; i < 50; i++)
	{
		if ((i % 10) == 0)
			printf("\n");
		printf("%4d", table[i].key);
	}
	printf("\n\n");
}

void dispTableCounter(void)
{
	int i;

	for (i = 0; i < 50; i++)
	{
		if ((i % 10) == 0)
			printf("\n");
		printf("%4d", table[i].counter);
	}
	printf("\n");
}

void main()
{
	initData();
	makeData();
	dispTableCounter();
}

