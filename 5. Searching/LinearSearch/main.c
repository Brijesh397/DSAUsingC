#include <stdio.h>
#include <stdint.h>

int32_t linearSearch(uint32_t arr[], uint32_t size, uint32_t element);
void printArray(uint32_t arr[], uint32_t size);
void createArray(uint32_t arr[], uint32_t size);

int main()
{
	uint32_t size = 0;
	int32_t index = -1;
	uint32_t element = 0;

	while(1)
	{
		printf("Enter the size of the Array: \r\n");
		scanf("%d",&size);

		uint32_t arr[size];

		createArray(arr, size);
		printArray(arr, size);
		printf("\n");

		printf("Enter the element you want to find: \r\n");
		scanf("%d",&element);

		index = linearSearch(arr, size,element);
		if(index != -1)
		{
			printf("The %d is at index %d",element,index);
		}
		else
		{
			printf("Element not found");
		}
		printf("\n");
	}
}


int32_t linearSearch(uint32_t arr[], uint32_t size, uint32_t element)
{
	for(uint32_t i=0; i<size; i++)
	{
		if(arr[i] == element)
		{
			return i;
		}
	}
	return -1;
}

void createArray(uint32_t arr[], uint32_t size)
{
	for(uint32_t i=0; i<size; i++)
	{
		printf("Enter data for pos %d: \r\n",i);
		scanf("%d",&arr[i]);
	}
}

void printArray(uint32_t arr[], uint32_t size)
{
	for(uint32_t i=0; i<size; i++)
	{
		printf("%d ",arr[i]);
	}
}
