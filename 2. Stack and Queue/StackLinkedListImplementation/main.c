#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
	uint32_t data;
	struct node_t *link;
}node_t;

node_t *top = NULL;

uint8_t isEmpty();
void push();
void pop();
void display();
void peek();
void size();

int main(void)
{

	int choice;

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
		case 1:
			push();
			break;

		case 2:
			pop();
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

	 	default :
			printf("Wrong choice\n");
		}
		printf("\n");
	}
}

uint8_t isEmpty()
{
	if(top == NULL)
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
	node_t *temp;
	uint32_t data;

	printf("Enter element to be pushed: ");
	scanf("%d",&data);

	temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;
	temp->link = top;
	top = temp;
}

void pop()
{
	node_t *temp;

	temp = top;
	printf("Popped element is : %d\n",temp->data);

	top = top->link;
	free(temp);
}

void display()
{
	node_t *temp;

	temp = top;

	while(temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->link;
	}
}

void peek()
{
	printf("The element at the top is %d\n",top->data);
}

void size()
{
	uint32_t nodes = 0;
	node_t *temp;

	temp = top;

	while(temp != NULL)
	{
		nodes++;
		temp = temp->link;
	}

	printf("The size of the stack is %d\n",nodes);
}
