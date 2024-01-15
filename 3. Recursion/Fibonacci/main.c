/*
 * Fibonacci means the output is the sum of previous two numbers
 * 1,1,2,3,5 ......
 *
 * We need to find the nth fibonacci number
 */

#include <stdio.h>
#include <stdint.h>

uint32_t nthFib(uint32_t n);

int main()
{
	uint32_t i = 0;
	uint32_t result = 0;

	while(1)
	{
		printf("Enter no : \r\n");
		scanf("%d",&i);

		result = nthFib(i);
		printf("%d\r\n",result);
	}

	return 0;
}

uint32_t nthFib(uint32_t n)
{
	uint32_t result;

	if(n == 1)
	{
		return 1;
	}
	else if(n == 0)
	{
		return 0;
	}

	result = nthFib(n-1) + nthFib(n-2);

	return result;
}
