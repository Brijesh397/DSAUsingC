/*
 * In Selection Sort repeatedly select the smallest (or largest) element from the unsorted portion
 * of the list and moving it to the sorted portion of the list.
 *
 */

#include <stdio.h>
#include <stdint.h>

void selectionSort(uint32_t arr[], uint32_t size);
void printArray(uint32_t arr[], uint32_t size);
void createArray(uint32_t arr[], uint32_t size);

int main()
{
	uint32_t size;
	printf("Enter the size of the Array: \r\n");
	scanf("%d",&size);

	uint32_t arr[size];

	createArray(arr, size);
	printArray(arr, size);
	printf("\n");

	selectionSort(arr, size);
	printArray(arr, size);

	while(1);
}

void selectionSort(uint32_t arr[], uint32_t size)
{
	uint32_t temp = 0;
	uint32_t pos = 0;

	for(uint32_t i=0; i<size-1; i++)	//Iterating the Array
	//size - 1 because the last element will be the largest
	{
		pos = i;	//Making ith element of the array as the smallest
		for(uint32_t j=i+1; j<size; j++) //Iterating the Array from i+1 pos
		{
			if(arr[j] < arr[pos])	//Comparing and finding the smallest element
			{
				pos = j;			//Storing the Position of the smallest element
			}
		}

		//Swapping the smallest element with the ith element
		if(i != pos)//If the element is at its proper place then there is no need of swapping
		{
			temp = arr[i];
			arr[i] = arr[pos];
			arr[pos] = temp;
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
