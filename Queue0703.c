/* NAME : BOKDONGJIN */
/* DATE : 20200703   */

/* 1. QUEUE 초기화                    */
/* 2. 큐에 데이터를 저장하는 함수     */
/* 3. 큐에서 데이터를 가져오는 함수   */

/* Queue + Linked_List                */

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}node;

node* front, * rear;
node* pnode;

void Create_Queue(void);
void Enqueue(int num);
int Dequeue(void);
void Display_Queue(void);

int main()
{
	int ret;
	Create_Queue();
	Enqueue(11);
	Enqueue(162);
	Enqueue(122);
	Enqueue(121);
	Enqueue(332);
	Enqueue(12);
	Enqueue(22);

	Display_Queue();


	printf("\n\n\n");
	Dequeue();
	Dequeue();
	Dequeue();
	Dequeue();

	Display_Queue();

	return 0;
}

void Create_Queue(void)
{
	front = (node*)malloc(sizeof(node));
	rear = (node*)malloc(sizeof(node));
	front->link = rear;
	rear->link = front;
}

void Enqueue(int num)
{
	pnode = (node*)malloc(sizeof(node));
	pnode->data = num;
	if (front->link == rear)
	{
		front->link = pnode;
		pnode->link = rear;
		rear->link = pnode;
	}
	else
	{
		rear->link->link = pnode;
		pnode->link = rear;
		rear->link = pnode;
	}
}

int Dequeue(void)
{
	int ret;
	node* del_node;
	printf("\n");

	if (front->link == rear)
		printf("queue is empty\n");
	else
	{
		del_node = front->link;
		front->link = del_node->link;
		ret = del_node->data;
		printf("Dequeue() : [%d]\n", ret);
		free(del_node);
	}
	return ret;
}

void Display_Queue(void)
{
	node* ptemp;
	if (front->link != rear)
	{
		for (ptemp = front->link; ptemp->link != rear; ptemp = ptemp->link)
		{
			printf("%d->", ptemp->data);
		}
		printf("%d\n", ptemp->data);
	}
	else if (front->link == rear)
		printf("Queue is empty");
	printf("\n");
}

