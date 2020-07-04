/* NAME : BOKDONGJIN */
/* DATE : 2020.07.04 */
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char data;
	struct node* left;
	struct node* right;
}node;

node* a, * b, *c, * d, * e, * f, * g;

void Traverse_Node(node*);
void Visit_Node(node*);

void Traverse_Node(node* pnode)
{
	if (pnode != NULL)
	{
		Visit_Node(pnode);
		Traverse_Node(pnode->left);
		Traverse_Node(pnode->right);
	}
}

void Visit_Node(node* cnode)
{
	printf("%2c->", cnode->data);
}

int main()
{
	a = (node*)malloc(sizeof(node));
	b = (node*)malloc(sizeof(node));
	c = (node*)malloc(sizeof(node));
	d = (node*)malloc(sizeof(node));
	e = (node*)malloc(sizeof(node));
	f = (node*)malloc(sizeof(node));
	g = (node*)malloc(sizeof(node));

	a->data = 'a';
	b->data = 'b';
	c->data = 'c';
	d->data = 'd';
	e->data = 'e';
	f->data = 'f';
	g->data = 'g';

	a->left  = b;
	a->right = c;
	b->left  = d;
	b->right = e;
	c->left  = f;
	c->right = g;
	d->left  = NULL;
	d->right = NULL;
	e->left  = NULL;
	e->right = NULL;
	f->left  = NULL;
	f->right = NULL;
	g->left  = NULL;
	g->right = NULL;

	Traverse_Node(a);

	printf("\n");

	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
	free(g);
	return 0;
}