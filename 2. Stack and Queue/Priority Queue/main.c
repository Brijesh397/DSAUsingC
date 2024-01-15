#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct p_queue{
	uint32_t priority;
	uint32_t data;
	struct p_queue *link;
}p_queue;

p_queue *front = NULL;

void insert(uint32_t data, uint32_t priority);
void delete();
void display();
uint8_t isEmpty();


int main(void)
{
	int choice,data,priority;
	while(1)
	{
		printf("1.Insert a new element\n");
		printf("2.Delete an element\n");
		printf("3.Display the queue\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		if(choice==4)
			break;

		switch(choice)
		{
		 case 1:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter its priority : ");
			scanf("%d",&priority);
			insert(data, priority);
			display();
			break;
		 case 2:
			delete();
			display();
			break;
		 case 3:
			display();
			break;
		 default :
			printf("Wrong choice\n");
		}
	}
}

uint8_t isEmpty()
{
	if(front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void insert(uint32_t data, uint32_t priority)
{
	p_queue *temp,*p;

	temp = (p_queue*)malloc(sizeof(p_queue));
	temp->data = data;


	if(isEmpty())
	{
		temp->priority = priority;
		temp->link = NULL;
		front = temp;
	}
	else
	{
		p = front;

		while( p->link!=NULL && p->link->priority<=priority )
		{
			p = p->link;
		}

		temp->priority = priority;
		temp->link = p->link;
		p->link = temp;
	}
}

void delete()
{
	if(isEmpty())
	{
		printf("Queue Underflow");
	}
	else
	{
		p_queue *temp;

		temp = front;
		front = front->link;
		free(temp);
	}
}

void display()
{
	p_queue *p;
	p = front;

	while(p != NULL)
	{
		printf("%d  ",p->data);
		p = p->link;
	}
	printf("\n");
}
