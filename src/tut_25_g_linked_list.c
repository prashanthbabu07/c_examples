#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
	void *data;
	struct node *nextnode;
} node;

typedef struct linked_list {
	node *head;
	node *tail;
	int elementsize;
	int logicallength;
} linkedlist;

void init_linkedlist(linkedlist *root, int elementsize)
{

	assert(elementsize > 0);
	
	root->head = NULL;
	root->tail = NULL;
	root->elementsize = elementsize;
	root->logicallength = 0;
}

void append_linkedlist(linkedlist *root, void *data)
{
	node *newnode = malloc(sizeof(node));
	newnode->data = malloc(root->elementsize);
	newnode->nextnode = NULL;

	memcpy(newnode->data, data, root->elementsize);

	if(root->logicallength == 0) {
		root->head = newnode;
		root->tail = newnode;
	} else {
		root->tail->nextnode = newnode;
		root->tail = newnode;
	}
	root->logicallength++;
}

void int_display_linkedlist(node *n)
{
	printf("{|%d|%p|}-->", *(int *)n->data, n);
}

void display_linkedlist(linkedlist *root, void(*display)(node *))
{

	assert(display != NULL);

	node *n = root->head;

	while(n!=NULL) {
		display(n);
		n = n->nextnode;
	}
	printf("\n");
	
}

void add_ints_list()
{
	int i;
	int numbers = 10;

	linkedlist root;
	init_linkedlist(&root, sizeof(int));

	for(i=0; i<numbers; i++) {
		append_linkedlist(&root, &i);
	}

	display_linkedlist(&root, int_display_linkedlist);

}

void main()
{
	printf("linked list...\n");
	add_ints_list();
}



