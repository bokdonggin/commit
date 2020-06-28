/************************************
* Name : BokDongging                *
* Date : 2020.06.28                 *
************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char data;
	struct node* Next_Node;
	struct node* Prev_Node;
}node;

node* head, * end, * tmp;
node* node1, * node2, * node3, * node4;

void Create_Linked_List(void);
void Insert_Node(node*);
void Delete_Node(node*);
void Display_Node(void);

int main()
{
	node* Insert_node;
	int i = 0;

	Create_Linked_List();
	Display_Node();

	Insert_node = (node*)malloc(sizeof(node));
	Insert_node->data = 'C';

	Insert_Node(Insert_node);
	Display_Node();
	
	Delete_Node(Insert_node);
	Display_Node();

	return 0;
}

void Create_Linked_List(void)
{
	head = (node*)malloc(sizeof(node));
	end = (node*)malloc(sizeof(node));

	node1 = (node*)malloc(sizeof(node));
	node2 = (node*)malloc(sizeof(node));
	node3 = (node*)malloc(sizeof(node));
	node4 = (node*)malloc(sizeof(node));
    
	node1->data = 'A';
	node2->data = 'B';
	node3->data = 'D';
	node4->data = 'E';

	
	head->Next_Node = node1;
	head->Prev_Node = end;

	end->Next_Node = head;
	end->Prev_Node = node4;


	node1->Next_Node = node2;
	node1->Prev_Node = head;
	
	node2->Next_Node = node3;
	node2->Prev_Node = node1;

	node3->Next_Node = node4;
	node3->Prev_Node = node2;

	node4->Next_Node = end;
	node4->Prev_Node = node3;
}

void Insert_Node(node* p_node)
{
	node* loop_node;

	for (loop_node = head; loop_node != end; loop_node = loop_node = loop_node->Next_Node)
	{
		if (loop_node->Next_Node->data > p_node->data)
			break;
	}

	p_node->Next_Node = loop_node->Next_Node;
	loop_node->Next_Node->Prev_Node = p_node;
	loop_node->Next_Node = p_node;
	p_node->Prev_Node = loop_node;
}

void Delete_Node(node* p_node)
{
	node* loop_node;
	node* del_node;
	del_node = (node*)malloc(sizeof(node));
	for (loop_node = head; loop_node != end; loop_node = loop_node->Next_Node)
	{
		if (loop_node->Next_Node->data == p_node->data)
		{
			del_node = loop_node->Next_Node;
			break;
		}
	}
	loop_node->Next_Node = loop_node->Next_Node->Next_Node;
	loop_node->Next_Node->Next_Node->Prev_Node = loop_node;

	free(del_node);
}

void Display_Node()
{
	node* loop_node;
	loop_node = head->Next_Node;

	while (loop_node != end)
	{
		printf("%2c", loop_node->data);
		loop_node = loop_node->Next_Node;
	}
	printf("\n");
}


