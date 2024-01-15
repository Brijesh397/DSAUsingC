#include <stdio.h>
#include <stdint.h>

uint32_t print1toN(uint32_t n);
uint32_t printNto1(uint32_t n);

int main()
{
	uint32_t i = 0;

	while(1)
	{

		printf("Enter No : \r\n");
		scanf("%d",&i);

		print1toN(i);
		printf("\n");
		printNto1(i);
	}

	return 0;
}


uint32_t print1toN(uint32_t n)
{
	if(n == 1)
	{
		printf("%d ",n);
		return 0;
	}

	print1toN(n-1);
	printf("%d ",n);

	return 0;
}

uint32_t printNto1(uint32_t n)
{
	printf("%d ",n);

	if(n == 1)
	{
		return 0;
	}

	printNto1(n-1);

	return 0;

}
