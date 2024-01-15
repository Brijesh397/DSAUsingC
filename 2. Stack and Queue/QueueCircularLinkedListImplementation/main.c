#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX		50

typedef struct node_t
{
	uint32_t data;
	struct node_t *link;
}node_t;

node_t *rear = NULL;

void enque();
void deque();
void display();
void peek();
void size();
uint8_t isEmpty();

int main(void)
{
	int choice;

	while(1)
	{
		printf("1.Insert an element in the queue\n");
		printf("2.Delete an element from the queue\n");
		printf("3.Display element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Display size of the queue\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		if(choice==6)
			break;

		switch(choice)
		{
		case 1:
			enque();
			printf("\n");
			display();
			break;
		case 2:
			deque();
			printf("\n");
			display();
			break;
		case 3:
			peek();
			printf("\n");
			break;
		case 4:
			display();
			break;
		case 5:
			size();
			break;
		default:
			printf("Wrong choice\n");
		}
		printf("\n");
	}

}


uint8_t isEmpty()
{
	if(rear == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void enque()
{
	uint32_t data;
	node_t *temp;

	if(isEmpty())
	{
		printf("Enter Data to be inserted");
		scanf("%d",&data);

		temp = (node_t*)malloc(sizeof(node_t));
		temp->data = data;
		rear = temp;
		rear->link = rear;
	}
	else
	{
		printf("Enter Data to be inserted");
		scanf("%d",&data);

		temp = (node_t*)malloc(sizeof(node_t));
		temp->data = data;
		temp->link = rear->link;
		rear->link = temp;
		rear = temp;

	 }
}

void deque()
{
	node_t *temp;

	if(isEmpty())
	{
		printf("Queue underflow\n");
		exit(1);
	}
	if(rear->link==rear)  /*If only one element*/
	{
		temp=rear;
		rear=NULL;
	}
	else
	{
		temp = rear->link;
		rear->link = temp->link;
	}

	free(temp);
}

void display()
{
	node_t *p;

	p = rear->link;

	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}

	if(rear == rear->link)
	{
		printf("%d",rear->data);
	}
	else
	{
		do
			{
				printf("%d ",p->data);
				p=p->link;
			}while(p!=rear->link);
			printf("\n");
	}
}

void peek()
{
	node_t *p;

	p = rear->link;

	printf("Data at beginning of queue is %d",p->data);
}

void size()
{
	node_t *p;
	uint32_t nodes = 1;
	p = rear->link;

	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}

	if(rear == rear->link)
	{
		printf("Total Elements in queue are %d",nodes);
	}
	else
	{
		while(p != rear)
		{
			p = p->link;
			nodes++;
		}
		printf("Total Elements in queue are %d",nodes);
	}
}
