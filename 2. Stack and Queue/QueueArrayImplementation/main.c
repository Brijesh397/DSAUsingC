#include <stdint.h>
#include <stdio.h>

#define MAX		50

uint32_t front = -1;
uint32_t rear = -1;

void enque(uint32_t queue[]);
void deque();
void display(uint32_t queue[]);
void peek(uint32_t queue[]);
void size();
uint8_t isEmpty();
uint8_t isFull();

int main(void)
{
	uint32_t queue[MAX];

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
			enque(queue);
			printf("\n");
			display(queue);
			break;
		case 2:
			deque();
			printf("\n");
			display(queue);
			break;
		case 3:
			peek(queue);
			printf("\n");
			display(queue);
			break;
		case 4:
			display(queue);
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

uint8_t isFull()
{
	if(front == MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
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

void enque(uint32_t queue[])
{
	uint32_t data;

	if(isFull())
	{
		printf("Queue is Full");
	}

	else
	{
		printf("Enter Data to be inserted: ");
		scanf("%d",&data);

		if(front == -1)
		{
			front = 0;
		}

		rear++;
		queue[rear] = data;
	}
	printf("\n");
}

void deque()
{
	if(isEmpty())
	{
		printf("Queue is Empty");
	}
	else
	{
		front++;
	}
	if(front > rear)
	{
		front = rear = -1;
	}
	printf("\n");
}

void display(uint32_t queue[])
{
	if(isEmpty())
	{
		printf("Queue is Empty");
	}
	else
	{
		printf("Elements in the queue are:\n");
		for(uint32_t i = front;i<=rear;i++)
		{
			printf("%d  ",queue[i]);
		}
	}
	printf("\n");
}

void peek(uint32_t queue[])
{
	printf("First Element of the queue is %d",queue[front]);
	printf("\n");
}

void size()
{
	printf("Size of queue is %d",((rear - front) + 1));
	printf("\n");
}
