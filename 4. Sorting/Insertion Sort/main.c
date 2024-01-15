#include <stdio.h>
#include <stdint.h>

void insertionSort(uint32_t arr[], uint32_t size);
void printArray(uint32_t arr[], uint32_t size);
void createArray(uint32_t arr[], uint32_t size);

int main()
{
	uint32_t size;

	while(1)
	{
		printf("Enter the size of the Array: \r\n");
		scanf("%d",&size);

		uint32_t arr[size];

		createArray(arr, size);
		printArray(arr, size);
		printf("\n");

		insertionSort(arr, size);
		printArray(arr, size);
		printf("\n");
	}
}

void insertionSort(uint32_t arr[], uint32_t size)
{
	int32_t j;
	for(uint32_t i=1; i<size; i++)	//Iterating the unsorted part of the array
	{
		uint32_t temp = arr[i];
		for(j=i-1; j>=0 && arr[j] > temp; j--)	//Iterating the sorted part of the array
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = temp;
	}
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
