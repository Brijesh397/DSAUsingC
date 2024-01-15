#include <stdio.h>
#include <stdint.h>

void printArray(uint32_t arr[], uint32_t size);
void createArray(uint32_t arr[], uint32_t size);
uint32_t partion(uint32_t arr[], uint32_t lb, uint32_t ub);
void quickSort(uint32_t arr[], uint32_t lb, uint32_t ub);

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

		quickSort(arr, 0, size-1);
		printArray(arr, size);
		printf("\n");
	}
}

/********************* Function Description *********************************
 * FUNCTION		:	quickSort
 *
 * DESCRIPTION	:	This is the recursive function to sort the array
 *
 * PARAMETERS	:	void
 *
 * RETURN		:	Void
 *
 * **************************************************************************/
void quickSort(uint32_t arr[], uint32_t lb, uint32_t ub)
{
	if(lb < ub)	//the lb should be less than ub
	{
		uint32_t p = partion(arr, lb, ub);	//We place the pivot at the its right place and get its position
		quickSort(arr, lb, p-1);	//Then we sort the left sub-array
		quickSort(arr, p+1, ub);	//Then we sort the right sub-array
	}
}

/********************* Function Description *********************************
 * FUNCTION		:	partion
 *
 * DESCRIPTION	:	This function places the pivot in an array in such a way that
 * 					all the elements on the left of the pivot are less than the pivot
 * 					and all the elements on the right of the pivot are greater than pivot.
 *
 * PARAMETERS	:	void
 *
 * RETURN		:	Void
 *
 * **************************************************************************/
uint32_t partion(uint32_t arr[], uint32_t lb, uint32_t ub)
{
	uint32_t pivot = arr[lb];
	uint32_t start = lb;
	uint32_t end = ub;
	uint32_t temp = 0;

	while(start < end)
	{
		while(arr[start] <= pivot)	//start is incremented
		{
			start++;
		}
		while(arr[end] > pivot)	//end is decremented
		{
			end--;
		}
		if(start < end)	//Once both the above while loops are executed swap the start and end
		{
			temp = arr[end];
			arr[end] = arr[start];
			arr[start] = temp;
		}
	}
	//At the end swap the end and pivot element
	temp = arr[end];
	arr[end] = arr[lb];
	arr[lb] = temp;

	//Return the position of the pivot element
	return end;
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
