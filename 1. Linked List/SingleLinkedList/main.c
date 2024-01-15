/************************SINGLE LINKED LIST**************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node_t{
	uint32_t data;
	struct node_t *link;
}node_t;

node_t* insertAtBegining(node_t *list,uint32_t data);
void insertAtEnd(node_t *list,uint32_t data);
void insertAtPosition(node_t *list,uint32_t data, uint32_t pos);
void printList(node_t *list);
void countNodes(node_t *list);
void searchData(node_t *list,uint32_t data);
node_t* createList(node_t *list,uint32_t nodes);
void insertAfterNode(node_t *list,uint32_t data, uint32_t pos);
void insertBeforeNode(node_t *list,uint32_t data, uint32_t pos);
void insertAfterData(node_t *list,uint32_t data_after, uint32_t data_insert);
void insertBeforeData(node_t *list,uint32_t data_before, uint32_t data_insert);
node_t* reverseList(node_t* list);
void deleteNode(node_t *list,uint32_t pos);

int main(void){

	node_t *start = NULL;
	uint32_t option,nodes,data,pos,data_after,data_before;

	while(1)
	{
		printf("Select from the options given below\n");
		printf("1.Create List\n");
		printf("2.Insert node at beginning of List\n");
		printf("3.Insert node at end of List\n");
		printf("4.Insert node before node\n");
		printf("5.Insert node after node\n");
		printf("6.Insert node before data\n");
		printf("7.Insert node after data\n");
		printf("8.Insert node at position\n");
		printf("9.Delete node\n");
		printf("10.Search Data\n");
		printf("11.Count No of Nodes\n");
		printf("12.Reverse List\n");
		printf("13.Print List\n");

		printf("Enter Option: ");
		scanf("%d",&option);

		switch (option)
		{
			case 1:
				printf("Enter Number of nodes: ");
				scanf("%d",&nodes);
				start = createList(start, nodes);
				printList(start);
				printf("\n");
				break;

			case 2:
				printf("Enter Data to be inserted: ");
				scanf("%d",&data);
				start = insertAtBegining(start, data);
				printList(start);
				printf("\n");
				break;

			case 3:
				printf("Enter Data to be inserted: ");
				scanf("%d",&data);
				insertAtEnd(start, data);
				printList(start);
				printf("\n");
				break;

			case 4:
				printf("Enter Position before which data has to be inserted: ");
				scanf("%d",&pos);
				printf("Enter Data to be inserted: ");
				scanf("%d",&data);

				insertBeforeNode(start, data,pos);
				printList(start);
				printf("\n");
				break;

			case 5:
				printf("Enter Position after which data has to be inserted: ");
				scanf("%d",&pos);
				printf("Enter Data to be inserted: ");
				scanf("%d",&data);

				insertAfterNode(start, data,pos);
				printList(start);
				printf("\n");
				break;

			case 6:
				printf("Enter Data before which data has to be inserted: ");
				scanf("%d",&data_before);
				printf("Enter Data to be inserted: ");
				scanf("%d",&data);

				insertBeforeData(start, data_before, data);
				printList(start);
				printf("\n");
				break;

			case 7:
				printf("Enter Data after which data has to be inserted: ");
				scanf("%d",&data_after);
				printf("Enter Data to be inserted: ");
				scanf("%d",&data);

				insertAfterData(start, data_after, data);
				printList(start);
				printf("\n");
				break;

			case 8:
				printf("Enter Position: ");
				scanf("%d",&pos);
				printf("Enter Data to be inserted: ");
				scanf("%d",&data);

				insertAtPosition(start, data,pos);
				printList(start);
				printf("\n");
				break;

			case 9:
				printf("Enter Node you want to delete: ");
				scanf("%d",&pos);

				deleteNode(start, pos);
				printList(start);
				printf("\n");
				break;

			case 10:
				printf("Enter Data to be found: ");
				scanf("%d",&data);
				searchData(start, data);
				printf("\n");
				break;

			case 11:
				countNodes(start);
				printf("\n");
				break;

			case 12:
				start = reverseList(start);
				printList(start);
				printf("\n");
				break;

			case 13:
				printList(start);
				printf("\n");
				break;

			default:
				printf("Invalid Input");
		}
	}

}


node_t* insertAtBegining(node_t *list,uint32_t data)
{
	node_t *temp;

	temp =(node_t*)malloc(sizeof(node_t));
	temp->data = data;
	temp->link = list;
	list = temp;
	return list;
}

void insertAtEnd(node_t *list,uint32_t data)
{
	node_t *temp,*p;
	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;

	p = list;

	while(p->link != NULL)
	{
		p = p->link;
	}

	temp->link = NULL;
	p->link = temp;
}

node_t* createList(node_t *list,uint32_t nodes)
{
	uint32_t data;

	if(nodes == 0)
	{
		printf("Invalid Input");
		return list;
	}

	else if(nodes == 1)
	{
		printf("Enter Data for node 1: ");
		scanf("%d",&data);
		list = insertAtBegining(list, data);
		return list;
	}

	else
	{
		printf("Enter Data for node 1: ");
		scanf("%d",&data);
		list = insertAtBegining(list, data);

		for(uint32_t i = 2;i<=nodes;i++)
		{
			printf("Enter Data for node %d: ",i);
			scanf("%d",&data);
			insertAtEnd(list, data);
		}
	}
	return list;
}

void insertAtPosition(node_t *list,uint32_t data, uint32_t pos)
{
	node_t *temp,*p;
	uint32_t i;

	if(pos == 0)
	{
		printf("Enter a Valid Position");
	}
	else if (pos == 1)
	{
		list = insertAtBegining(list, data);
	}

	p = list;

	for(i=1;i<(pos-1) && (p->link != NULL);i++)
	{
		p = p->link;
	}

	if(p->link == NULL)
	{
		printf("Position out of bond");
	}
	else
	{
		temp = (node_t*)malloc(sizeof(node_t));
		temp->data = data;
		temp->link = p->link;
		p->link = temp;
	}
}

void insertAfterNode(node_t *list,uint32_t data, uint32_t pos)
{
	node_t *temp,*p;
	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;

	p = list;

	for(uint32_t i=1;i<(pos) && (p->link != NULL);i++)
	{
		p = p->link;
	}

	temp->link = p->link;
	p->link = temp;
}

void insertBeforeNode(node_t *list,uint32_t data, uint32_t pos)
{
	node_t *temp,*p;
	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;

	p = list;

	for(uint32_t i=1;i<(pos-1) && (p->link != NULL);i++)
	{
		p = p->link;
	}

	temp->link = p->link;
	p->link = temp;
}

void insertAfterData(node_t *list,uint32_t data_after, uint32_t data_insert)
{
	node_t *temp,*p;
	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data_insert;

	p =list;

	while(p->link != NULL)
	{
		if(p->data == data_after)
		{
			break;
		}
		p = p->link;
	}

	temp->link = p->link;
	p->link = temp;
}

void insertBeforeData(node_t *list,uint32_t data_before, uint32_t data_insert)
{
	node_t *temp,*p;
	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data_insert;

	p =list;

	while(p->link != NULL)
	{
		if(p->link->data == data_before)
		{
			break;
		}
		p = p->link;
	}

	temp->link = p->link;
	p->link = temp;
}


void printList(node_t *list)
{
	node_t *p;
	uint32_t nodes = 1;

	p = list;

	while(p != NULL)
	{
		printf("Data at node %d is %d\n",nodes,p->data);
		p = p->link;
		nodes++;
	}
}

void countNodes(node_t *list)
{
	uint32_t nodes = 0;
	node_t *p;

	p = list;

	while(p != NULL)
	{
		p = p->link;
		nodes++;
	}
	printf("Number of Nodes in Linked List are %d\n",nodes);

}

void searchData(node_t *list,uint32_t data)
{
	uint32_t nodes = 0;
	node_t *p;

	p = list;

	while(p != NULL)
	{
		nodes++;
		if(p->data == data)
		{
			printf("Data %d is present at node %d\n",data,nodes);
			break;
		}
		p = p->link;
	}
	if(p == NULL)
	{
		printf("Data %d is not present in Linked List",data);
	}

}

void deleteNode(node_t *list,uint32_t pos)
{
	node_t *p,*temp;

	p = list;

	for(uint32_t i=1; i<(pos-1) && (p->link != NULL);i++)
	{
		p = p->link;
	}

	temp = p->link;
	p->link = p->link->link;

	free(temp);
}

node_t* reverseList(node_t* list)
{
	node_t *prev,*ptr,*next;

	prev = NULL;
	ptr = list;

	while(ptr != NULL)
	{
		next = ptr->link;
		ptr->link = prev;

		prev = ptr;
		ptr = next;
	}
	list = prev;

	return list;
}
