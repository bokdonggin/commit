/*********************************/
/* Name : Delete Linked List     */
/* Date : 2020.06.27             */
/*********************************/
#include<stdio.h>
#include<stdlib.h>

/* Node 선언                     */
typedef struct node{
	char data;
	struct node* link;
}node;

/* head=> 1, 2, 3, 4, => end     */
/* 중간 삽입 : temp              */
node* head ,  * end  , * temp         ; 
node* node1, * node2, * node3, * node4;

void Create_Linked_List(void);
void Insert_Node(node*);
void Display_Node(void);
void Delete_Node(node*);

int main()
{
	node* insert_node;
	int i = 0;
	Create_Linked_List();
	Display_Node();

	insert_node = (node*)malloc(sizeof(node));
	insert_node->data = 'C';

	Insert_Node(insert_node);
	Display_Node();

	Delete_Node(insert_node);
	Display_Node();

	return 0;
}

void Create_Linked_List(void)
{
	node* p_node;
	head  =  (node*)malloc(sizeof(node));
	end   =  (node*)malloc(sizeof(node));
	/* head, end 메모리 할당           */
	node1 =  (node*)malloc(sizeof(node));
	node1->data = 'A';
	head->link  = node1;
	node1->link = end;
	end->link = end;
	/*Head => 1 => end                 */
	p_node = node1;

	node2 = (node*)malloc(sizeof(node));
	node2->data = 'B';
	p_node->link = node2;
	node2->link = end;

	p_node = node2;

	node3 = (node*)malloc(sizeof(node));
	node3->data = 'D';
	p_node->link = node3;
	node3->link = end;

	p_node = node3;
	node4 = (node*)malloc(sizeof(node));
	node4->data = 'E';
	
	p_node->link = node4;
	node4->link = end;
}

void Insert_Node(node* p_node)
{
	node* loop_node = (node*)malloc(sizeof(node));
	memset(loop_node, 0x00, sizeof(node));
	for (loop_node = head; loop_node != end; loop_node = loop_node->link)
	{
		if (loop_node->link->data > p_node->data)
			break;
	}
	p_node->link = loop_node->link;
	loop_node->link = p_node;
}

void Delete_Node(node* p_node)
{
	node* loop_node = (node*)malloc(sizeof(node));
	memset(loop_node, 0x00, sizeof(node));
	loop_node = head;
	node* del_node = (node*)malloc(sizeof(node));
	char del_data = p_node->data;

	while (loop_node != end)
	{
		if (loop_node->link->data == del_data)
		{
			del_node = loop_node->link;
			break;
		}
		else 
		{ 
			loop_node = loop_node->link;
		}
	}
	if(loop_node->link == end)
	    loop_node = loop_node->link->link;

	free(del_node);
}

void Display_Node()
{
	node* display_node;
	display_node = head->link;

	while (display_node != end)
	{
		printf("%2c", display_node->data);
		display_node = display_node->link;
	}
	printf("\n");

}


