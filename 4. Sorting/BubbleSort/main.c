/*
 * In bubble sort algorithm the two adjacent elements are compared of the array if the
 * first element is greater than the adjacent element that they are swapped. The array iterated
 * until the largest element is at the end of the array.
 * This process is done until the whole array is sorted.
 *
 */

#include <stdio.h>
#include <stdint.h>

void bubbleSort(uint32_t arr[], uint32_t size);
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

		bubbleSort(arr, size);
		printArray(arr, size);
		printf("\n");
	}
}

void bubbleSort(uint32_t arr[], uint32_t size)
{
	uint32_t temp = 0;
	uint32_t swaps = 0;	// To keep track if there are any swaps happening or not
	//If no swaps are happening that means the array has been sorted in less number of
	//iterations so we break from the loop

	for(uint32_t i=size-2; i>0; i--) //Iteratting the Array
	//Iterrating the array size-2 times as we want to traverse till the second last element
	{
		swaps = 0;
		for(uint32_t j=0; j<=i; j++)
		{
			if((arr[j] > arr[j+1]))
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swaps++;
			}
		}
		if(swaps == 0)	//Break form the loop if no swaps have happended
		{
			break;
		}
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
