#include <stdio.h>
#include <stdint.h>

void printArray(uint32_t arr[], uint32_t size);
void createArray(uint32_t arr[], uint32_t size);
void merge(uint32_t arr1[], uint32_t arr2[], uint32_t arr3[], uint32_t size1, uint32_t size2, uint32_t size3);

int main()
{
	uint32_t size1 = 0;
	uint32_t size2 = 0;
	uint32_t size3 = 0;

	while(1)
	{
		printf("Enter the size of the Array: \r\n");
		scanf("%d",&size1);

		uint32_t arr1[size1];
		createArray(arr1, size1);

		printf("Enter the size of the Array: \r\n");
		scanf("%d",&size2);
		uint32_t arr2[size2];
		createArray(arr2, size2);

		printArray(arr1, size1);
		printf("\n");
		printArray(arr2, size2);
		printf("\n");

		size3 = size1 + size2;
		uint32_t arr3[size3];

		merge(arr1,arr2,arr3,size1,size2,size3);
		printArray(arr3, size3);
		printf("\n");
	}
}

void merge(uint32_t arr1[], uint32_t arr2[], uint32_t arr3[], uint32_t size1, uint32_t size2, uint32_t size3)
{
	uint32_t i = 0;
	uint32_t j = 0;
	uint32_t k = 0;
	for(k = 0; k<size3; k++)
	{
		if(i<size1 && j<size2)
		{
			if(arr1[i] <= arr2[j])
			{
				arr3[k] = arr1[i];
				i++;
			}
			else
			{
				arr3[k] = arr2[j];
				j++;
			}
		}
		else if(i<size1 && j>=size2)
		{
			arr3[k] = arr1[i];
			i++;
		}
		else if(i>=size1 && j<size2)
		{
			arr3[k] = arr2[j];
			j++;
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
