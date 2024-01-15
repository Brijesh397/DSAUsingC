/************************DOUBLE LINKED LIST**************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node_t{
	struct node_t *prev;
	uint32_t data;
	struct node_t *next;
}node_t;

node_t* insertAtBegining(node_t *list,uint32_t data);
void insertAtEnd(node_t *list,uint32_t data);
void printList(node_t *list);
void countNodes(node_t *list);
void searchData(node_t *list,uint32_t data);
node_t* createList(node_t *list,uint32_t nodes);
void insertAfterNode(node_t *list,uint32_t data, uint32_t pos);
void insertBeforeNode(node_t *list,uint32_t data, uint32_t pos);
void insertAfterData(node_t *list,uint32_t data_after, uint32_t data_insert);
void insertBeforeData(node_t *list,uint32_t data_before, uint32_t data_insert);
node_t* reverseList(node_t* list);
node_t* deleteNode(node_t *list,uint32_t pos);

int main(void)
{

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
		printf("8.Delete node\n");
		printf("9.Search Data\n");
		printf("10.Count No of Nodes\n");
		printf("11.Reverse List\n");
		printf("12.Print List\n");

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
				printf("Enter Node you want to delete: ");
				scanf("%d",&pos);

				start = deleteNode(start, pos);
				printList(start);
				printf("\n");
				break;

			case 9:
				printf("Enter Data to be found: ");
				scanf("%d",&data);
				searchData(start, data);
				printf("\n");
				break;

			case 10:
				countNodes(start);
				printf("\n");
				break;

			case 11:
				start = reverseList(start);
				printList(start);
				printf("\n");
				break;

			case 12:
				printList(start);
				printf("\n");
				break;

			default:
				printf("\n");
				printf("Invalid Input");
		}
	}
}


node_t* insertAtBegining(node_t *list,uint32_t data)
{
	node_t *temp;

	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;

	temp->prev = NULL;
	temp->next = list;
	list->prev = temp;
	list = temp;

	return list;
}

void insertAtEnd(node_t *list,uint32_t data)
{
	node_t *temp,*p;

	temp=(node_t*)malloc(sizeof(node_t));
	temp->data = data;

	p = list;

	while(p->next != NULL)
	{
		p = p->next;
	}

	temp->next = NULL;
	p->next = temp;
	temp->prev = p;
}

node_t* createList(node_t *list,uint32_t nodes)
{
	uint32_t data;
	node_t *temp;

	if(nodes == 0)
	{
		printf("Invalid Input");
		return list;
	}

	else if(nodes >= 1)
	{
		printf("Enter Data for node 1: ");
		scanf("%d",&data);

		temp = (node_t*)malloc(sizeof(node_t));
		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;
		list = temp;
	}

	if(nodes >1)
	{
		for(uint32_t i = 2;i<=nodes;i++)
		{
			printf("Enter Data for node %d: ",i);
			scanf("%d",&data);
			insertAtEnd(list, data);
		}
	}
	return list;
}


void insertAfterNode(node_t *list,uint32_t data, uint32_t pos)
{
	node_t *temp,*p;

	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;

	p = list;

	for(uint32_t i=1;i<(pos);i++)
	{
		p = p->next;
	}

	if(p->next == NULL)	//If Last Node
	{
		insertAtEnd(list, data);
	}

	else
	{
		temp->prev = p;
		temp->next = p->next;
		p->next->prev = temp;
		p->next = temp;
	}
}

void insertBeforeNode(node_t *list,uint32_t data, uint32_t pos)
{
	node_t *temp,*p;

	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;

	p = list;

	for(uint32_t i=1;i<(pos) && (p->next != NULL);i++)
	{
		p = p->next;
	}

	temp->prev = p->prev;
	temp->next = p;
	p->prev->next = temp;
	p->prev = temp;
}

void insertAfterData(node_t *list,uint32_t data_after, uint32_t data_insert)
{
	node_t *temp,*p;

	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data_insert;

	p = list;

	while(p != NULL)
	{
		if(p->data == data_after)
		{
			break;
		}
		p = p->next;
	}

	if(p->next == NULL)	//If Last Node
	{
		insertAtEnd(list, data_insert);
	}
	else
	{
		temp->next = p->next;
		temp->prev = p;
		p->next->prev = temp;
		p->next = temp;
	}
}

void insertBeforeData(node_t *list,uint32_t data_before, uint32_t data_insert)
{
	node_t *temp,*p;

	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data_insert;

	p = list;

	while(p != NULL)
	{
		if(p->data == data_before)
		{
			break;
		}
		p = p->next;
	}

	temp->next = p;
	temp->prev = p->prev;
	p->prev->next = temp;
	p->prev = temp;

}

void printList(node_t *list)
{
	node_t *p;
	uint32_t nodes = 1;

	p = list;

	while(p != NULL)
	{
		printf("Data at node %d is %d\n",nodes,p->data);
		p = p->next;
		nodes++;
	}
}

node_t* deleteNode(node_t *list,uint32_t pos)
{
	node_t *temp,*p;

	p = list;

	for(uint32_t i=1;i<(pos);i++)
	{
		p = p->next;
	}

	temp = p;

	if(p->prev == NULL) //Deletion of first Node
	{
		p = p->next;
		p->prev = NULL;
		list = p;
		free(temp);
		return list;
	}
	else if(p->next == NULL)	//Deletion of Last Node
	{
		p = p->prev;
		p->next = NULL;
		free(temp);
		return list;
	}

	else	// Deletion of any other node
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(temp);
		return list;
	}
	return list;

}


void searchData(node_t *list,uint32_t data)
{
	node_t *p;
	uint32_t nodes = 1;

	p = list;

	while(p != NULL)
	{
		if(p->data == data)
		{
			break;
		}
		p = p->next;
		nodes++;
	}

	if(p == NULL)
	{
		printf("Data not present in List\n");
	}
	else
	{
		printf("Data %d is present at node %d\n",data,nodes);
	}
}

void countNodes(node_t *list)
{
	node_t *p;
	uint32_t nodes = 1;

	p = list;

	while(p->next != NULL)
	{
		p = p->next;
		nodes++;
	}
	printf("Number of Nodes in List are %d\n",nodes);
}

node_t* reverseList(node_t* list)
{
	node_t *p,*next;

	p =list;

	while(p != NULL)
	{
//		temp = p->prev;
//		p->prev = p->next;
//		p->next = temp;
//
//		temp = p;
//		p = p->prev;



		next = p->next;
		p->next = p->prev;
		p->prev = next;

		next = p;
		p = p->prev;

	}
	list = next;

	return list;
}
