/**************************
 * Name : Stack0629
 * Date : 2020.06.29
 *************************/


#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node* head, * end;
node* ptr;

void Create_Stack(void);
void Push_Stack(int);
int  Pop_Stack(void);
void Display_Stack(void);

int main()
{
	Create_Stack();

	Push_Stack(1);
	Push_Stack(2);
	Push_Stack(12);
	Push_Stack(23);
	Push_Stack(2);
	Push_Stack(244);

	Display_Stack();

	printf("\n");

	Pop_Stack();
	Pop_Stack();
	Pop_Stack();

	Display_Stack();

}

void Create_Stack(void)
{
	head = (node*)malloc(sizeof(node));
	end = (node*)malloc(sizeof(node));
	head->next = end;
	end->next = end;
}

void Push_Stack(int num)
{
	ptr = (node*)malloc(sizeof(node));
	ptr->data = num;
	ptr->next = head->next;
	head->next = ptr;
}

int Pop_Stack(void)
{
	ptr = head->next;
	head->next = head->next->next;

	int data;
	data = ptr->data;

	free(ptr);
	return data;
}

void Display_Stack(void)
{
	node* current_node;
	printf("head = > ");
	for (current_node = head->next; current_node != end; current_node = current_node->next)
	{
		printf("%d =>", current_node->data);
	}
	printf("end");
}