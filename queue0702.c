/***********************/
/* DATE : 2020.07.02   */
/* NAME : BOK DONG GIN */
/***********************/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100


int Queue[MAX];
int Front, Rear;

void Create_Queue(void);
void EnQueue(int num);
int DeQueue(void);
void Display_Queue(void);

int main()
{
	int ret;
	Create_Queue();
	EnQueue(1);
	EnQueue(12);
	EnQueue(13);
	EnQueue(14);
	EnQueue(15);
	EnQueue(16);
	EnQueue(21);

	Display_Queue();

	ret = DeQueue();

	ret = DeQueue();

	Display_Queue();

	return 0;
}

void Create_Queue(void)
{
	Front = Rear = 0;
}

void EnQueue(int num)
{
	Queue[Rear++] = num;
	if (Rear >= MAX)
		Rear = 0;
}

int DeQueue(void)
{
	int ret;
	ret = Queue[Front++];
	if (Front >= MAX)
		Front = 0;
	return ret;
}

void Display_Queue(void)
{
	int i;
	printf("Front->");
	for (i = Front; i < Rear; i++)
		printf("%2d->", Queue[i]);
	printf("Rear");
	printf("\n");
}