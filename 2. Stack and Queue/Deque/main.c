#include <stdio.h>
#include <stdint.h>

#define MAX 	50

uint32_t dequeue[MAX];

uint32_t front = -1;
uint32_t rear = -1;

void insertFront();
void insertRear();
void deleteFront();
void deleteRear();
void display();
uint32_t isEmpty();
uint32_t isFull();

int main(void)
{
	int choice;
	while(1)
	{
		printf("1.Insert at the front end\n");
		printf("2.Insert at the rear end\n");
		printf("3.Delete from front end\n");
		printf("4.Delete from rear end\n");
		printf("5.Display all elements of dequeue\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		if(choice==6)
			break;

		switch(choice)
		{
		case 1:
			insertFront();
			break;
		case 2:
			insertRear();
			break;
		 case 3:
			deleteFront();
			break;
		 case 4:
			deleteRear();
			break;
		 case 5:
			display();
			break;
		 default:
			printf("Wrong choice\n");
		}
	}
}

uint32_t isEmpty()
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

uint32_t isFull()
{
	if((front==0 && rear==MAX-1) || (front==rear+1))
		return 1;
	else
		return 0;
}

void insertFront()
{
	uint32_t data;

	if(isFull())
	{
		printf("Queue Overflow\n");
		return;
	}
	else if(front == -1)
	{
		front = 0;
		rear = 0;

		printf("Enter data to be inserted into dequeue: ");
		scanf("%d",&data);

		dequeue[front] = data;
	}
	else if(front == 0)
	{
		front = (MAX-1);

		printf("Enter data to be inserted into dequeue: ");
		scanf("%d",&data);

		dequeue[front] = data;
	}
	else
	{
		front--;

		printf("Enter data to be inserted into dequeue: ");
		scanf("%d",&data);

		dequeue[front] = data;
	}
}

void insertRear()
{
	uint32_t data;

	if(isFull())
	{
		printf("Queue Overflow\n");
	}
	else if(front == -1)
	{
		front = 0;
		rear = 0;

		printf("Enter data to be inserted into dequeue: ");
		scanf("%d",&data);

		dequeue[front] = data;
	}
	else if(rear == (MAX-1))
	{
		rear = 0;

		printf("Enter data to be inserted into dequeue: ");
		scanf("%d",&data);

		dequeue[rear] = data;
	}
	else
	{
		rear++;

		printf("Enter data to be inserted into dequeue: ");
		scanf("%d",&data);

		dequeue[rear] = data;
	}
}


void deleteFront()
{
	if(isEmpty())
	{
		printf("Queue Underflow\n");
	}
	else if (front == (MAX-1))
	{
		front = 0;
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front++;
	}
}

void deleteRear()
{
	if(isEmpty())
	{
		printf("Queue Underflow\n");
	}
	else if(rear == 0)
	{
		rear = (MAX-1);
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		rear--;
	}
}

void display()
{
	uint32_t p;

	if(isEmpty())
	{
		printf("Queue Underflow\n");
	}
	else if(front<=rear)
	{
		p = front;
		while(p<=rear)
		{
			printf("%d  ",dequeue[p]);
			p++;
		}
	}
	else if(front>rear)
	{
		p = front;
		while(p<=(MAX-1))
		{
			printf("%d  ",dequeue[p]);
			p++;
		}
		p = 0;
		while(p<=rear)
		{
			printf("%d  ",dequeue[p]);
			p++;
		}
	}
	printf("\n");
}
