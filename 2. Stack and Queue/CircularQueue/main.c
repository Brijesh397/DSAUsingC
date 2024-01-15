#include <stdio.h>
#include <stdint.h>

#define MAX		5

uint32_t front = -1;
uint32_t rear = -1;

uint32_t queue[MAX];

void enque();
void deque();
void display();
void peek();
void size();
uint8_t isEmpty();
uint8_t isFull();

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
	if(front == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

uint8_t isFull()
{
	if(front == rear+1)
	{
		return 1;
	}
	else if(front == 0 && rear == MAX-1)
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

	if(isFull())
	{
		printf("Queue Overflow\n");
	}


	else if(isEmpty())
	{
		printf("Enter Data to be inserted in Queue: ");
		scanf("%d",&data);
		front = 0;
		rear = 0;
		queue[front] = data;
	}
	else if(rear == (MAX-1))
	{
		printf("Enter Data to be inserted in Queue: ");
		scanf("%d",&data);
		rear = 0;
		queue[rear] = data;
	}
	else
	{
		printf("Enter Data to be inserted in Queue: ");
		scanf("%d",&data);
		rear++;
		queue[rear] = data;
	}
}

void deque()
{
	if(isEmpty())
	{
		printf("Queue Underflow\n");
	}

	else if(front == (MAX-1))
	{
		front = 0;
	}
	else if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front++;
	}
}

void display()
{
	uint32_t p = front;
	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}

	else if(front <= rear)
	{
		while(p <= rear)
		{
			printf("%d  ",queue[p]);
			p++;
		}
	}
	else if(front > rear)
	{
		while(p <= (MAX-1))
		{
			printf("%d  ",queue[p]);
			p++;
		}
		p = 0;
		while(p <= rear)
		{
			printf("%d  ",queue[p]);
			p++;
		}
	}
	printf("\n");

}

void peek()
{
	printf("Element in the front of the queue is %d",queue[front]);
}

void size()
{
	uint32_t nodes = 0,p = front;
	if(front <= rear)
	{
		while(p <= rear)
		{
			nodes++;
			p++;
		}
	}
	else if(front > rear)
	{
		while(p <= (MAX-1))
		{
			nodes++;
			p++;
		}
		p = 0;
		while(p <= rear)
		{
			nodes++;
			p++;
		}
	}
	printf("%d",nodes);
	printf("\n");
}
