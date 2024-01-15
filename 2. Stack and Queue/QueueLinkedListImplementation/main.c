#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX		50

typedef struct node_t
{
	uint32_t data;
	struct node_t *link;
}node_t;

node_t *front = NULL;
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
			display();
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
	if (front == NULL)
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
	node_t *temp;
	uint32_t data;
	printf("Enter data to inserted into queue: ");
	scanf("%d",&data);

	if(isEmpty())
	{
		temp = (node_t*)malloc(sizeof(node_t));
		temp->data = data;
		temp->link = NULL;
		front = temp;
		rear = temp;
	}
	else
	{
		temp = (node_t*)malloc(sizeof(node_t));
		temp->data = data;
		rear->link = temp;
		rear = temp;
	}
}

void deque()
{
	node_t *temp,*p;
	temp = front;
	p = rear;

	front = front->link;

	free(temp);
}

void display()
{
	node_t *p;

	p = front;

	if(isEmpty())
	{
		break;
	}
	else
	{
		while(p != NULL)
		{
			printf("%d  ",p->data);
			p = p->link;
		}
	}

}

void peek()
{
	printf("Data at top of the queue is %d",front->data);
}

void size()
{
	uint32_t nodes = 0;
	node_t *p;

	p = front;

	while(p != NULL)
	{
		nodes++;
		p = p->link;
	}

	printf("The size of queue is %d",nodes);
}
