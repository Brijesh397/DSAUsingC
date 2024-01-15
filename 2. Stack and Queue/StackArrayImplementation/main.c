#include <stdint.h>
#include <stdio.h>

#define MAX		50 		//capacity of the Static Stack

int8_t top = -1;		// Initializing the top of the stack to be -1
uint32_t stack[MAX];	// Initializing the stack using an array

uint8_t isEmpty();
uint8_t isFull();
void push();
uint32_t pop();
void display();
void peek();
void size();

int main(void)
{
	uint32_t choice,x;

	while(1)
		{
			printf("1.Push an element on the stack\n");
			printf("2.Pop an element from the stack\n");
			printf("3.Display the top element\n");
			printf("4.Display all stack elements\n");
			printf("5.Display size of the stack\n");
			printf("6.Quit\n");
			printf("Enter your choice : ");
			scanf("%d",&choice);
			if(choice==6)
				break;
			switch(choice)
			{
			 case 1 :
				push();
				break;
			 case 2:
				x=pop();
				printf("Popped element is : %d\n",x);
				break;
			 case 3:
				peek();
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
	if(top == -1)
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
	if(top == (MAX-1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void push()
{
	if(isFull())
	{
		printf("Stack Overflow");
	}
	else
	{
		uint32_t data;
		printf("Enter data to be pushed: ");
		scanf("%d",&data);

		top++;
		stack[top] = data;
	}
}

uint32_t pop()
{
	if(isEmpty())
	{
		printf("Stack Underflow");
		return 1;
	}
	else
	{
		uint32_t x = stack[top];
		top--;
		return x;
	}
}

void display()
{
	if(isEmpty())
	{
		printf("Stack Empty");
	}

	for(uint8_t i=0;i<=(top);i++)
	{
		printf("%d\n",stack[i]);
	}
}

void peek()
{
	printf("The element at the top is %d\n",stack[top]);
}

void size()
{
	printf("The size of the stack is %d\n",(top+1));
}
