#include <stdio.h>
#include <stdint.h>

uint32_t dectobin(uint32_t no);

int main(void)
{
	uint32_t no;

	printf("Enter number to convert base: ");
	scanf("%d",&no);

	printf("The binary of %d is ",no);
	dectobin(no);

	while(1);

}


uint32_t dectobin(uint32_t no)
{
//	if(no == 1)
//	{
//		printf("1");
//		return 1;
//	}
//	else if(no == 0)
//	{
//		printf("0");
//		return 0;
//	}
//
//	printf("%d",no%2);
//	no = dectobin(no/2);
//
//
//	return no;

	uint32_t result;

	if(no == 0)
	{
		return 1;
	}

	result = dectobin(no/2);
	printf("%d",no%2);

	return result;

}
