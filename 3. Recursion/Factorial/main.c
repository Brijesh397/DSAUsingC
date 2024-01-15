#include <stdio.h>
#include <stdint.h>

uint32_t fact(uint32_t no);

int main (void)
{
	uint32_t no;

	while(1)
	{
		printf("Enter number whose factorial you want to find: ");
		scanf("%d",&no);

		printf("Factorial of %d is %d\n",no,fact(no));
	}
}
uint32_t fact(uint32_t no)
{
	if(no == 0)
	{
		return 1;
	}

	no = no * (fact(no-1));

	return no;
}
