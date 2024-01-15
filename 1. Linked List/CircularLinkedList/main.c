/************************CIRCULAR LINKED LIST**************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node_t{
	uint32_t data;
	struct node_t *link;
}node_t;

void insertAtBegining(node_t *list,uint32_t data);
node_t* insertAtEnd(node_t *list,uint32_t data);
void printList(node_t *list);
node_t* createList(node_t *list,uint32_t nodes);
node_t* reverseList(node_t* list);
node_t* deleteNode(node_t *list,uint32_t pos);

int main(void){

	node_t *last = NULL;
	uint32_t option,nodes,data,pos;

	while(1)
	{
		printf("Select from the options given below\n");
		printf("1.Create List\n");
		printf("2.Insert node at beginning of List\n");
		printf("3.Insert node at end of List\n");
		printf("4.Delete node\n");
		printf("5.Reverse List\n");
		printf("6.Print List\n");

		printf("Enter Option: ");
		scanf("%d",&option);

		switch (option)
		{
			case 1:
				printf("Enter Number of nodes: ");
				scanf("%d",&nodes);
				last = createList(last, nodes);
				printList(last);
				printf("\n");
				break;

			case 2:
				printf("Enter Data to be inserted: ");
				scanf("%d",&data);
				insertAtBegining(last, data);
				printList(last);
				printf("\n");
				break;

			case 3:
				printf("Enter Data to be inserted: ");
				scanf("%d",&data);
				last = insertAtEnd(last, data);
				printList(last);
				printf("\n");
				break;

			case 4:
				printf("Enter Node you want to delete: ");
				scanf("%d",&pos);

				last = deleteNode(last, pos);
				printList(last);
				printf("\n");
				break;

			case 5:
				last = reverseList(last);
				printList(last);
				printf("\n");
				break;

			case 6:
				printList(last);
				printf("\n");
				break;

			default:
				printf("Invalid Input");
		}
	}

}


void insertAtBegining(node_t *list,uint32_t data)
{
	node_t *temp;

	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;
	temp->link = list->link;
	list->link = temp;

}

node_t* insertAtEnd(node_t *list,uint32_t data)
{
	node_t *temp;

	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;
	temp->link = list->link;
	list->link = temp;

	list = temp;

	return list;
}

node_t* createList(node_t *list,uint32_t nodes)
{
	node_t *temp;
	uint32_t data;

	if(nodes == 0)
	{
		return list;
	}

	else if(nodes >=1)
	{
		printf("Enter Data for node 1: ");
		scanf("%d",&data);

		temp = (node_t*)malloc(sizeof(node_t));
		temp->data = data;
		list = temp;
		temp->link = temp;
	}
	if(nodes >1)
	{
		for(uint32_t i=2;i<=nodes;i++)
		{
			printf("Enter Data for node %d: ",i);
			scanf("%d",&data);
			list = insertAtEnd(list, data);
		}
	}
	return list;

}

void printList(node_t *list)
{
	node_t *p;
	uint32_t nodes = 1;

	p = list;
	uint32_t temp = p->data;
	p = p->link;

	while( p->data != temp)
	{
		printf("Data at Node %d is %d\n",nodes,p->data);
		p = p->link;
		nodes++;
	}
	printf("Data at Node %d is %d\n",nodes++,p->data);
}

node_t* deleteNode(node_t *list,uint32_t pos)
{
	node_t *temp,*p;

	p = list;

	if(pos == 1)
	{
		temp = p->link;
		p->link = temp->link;
		free(temp);
		return list;
	}

	p = p->link;	//Coming On First Node

	for(uint32_t i=1;i<(pos-1);i++)	//First Node
	{
		p = p->link;
	}

	if(p->link == list)//Last Node
	{
		temp = p->link;
		list = p;
		p->link = temp->link;
		free(temp);
	}
	else
	{
		temp = p->link;
		p->link = temp->link;
		free(temp);
	}
	return list;
}

node_t* reverseList(node_t* list)
{
	node_t *temp,*next,*prev;

	temp = list->link;
	prev = list;

	while(temp != list)
	{
		next = temp->link;
		temp->link = prev;
		prev = temp;
		temp = next;
	}
	temp->link = prev;
	list = prev->link;

	return list;
}
