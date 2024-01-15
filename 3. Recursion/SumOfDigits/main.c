#include <stdio.h>
#include <stdint.h>

uint32_t sumOfDigits(uint32_t no);

int main(void)
{
	uint32_t no;

	while(1)
	{
		printf("Enter the number who's sum of digits you want to find: ");
		scanf("%d",&no);

		printf("The sum of digits of %d is %d\n",no,sumOfDigits(no));

	}

}


uint32_t sumOfDigits(uint32_t no)
{
	if(no/10 == 0)
	{
		return no;
	}

	no = sumOfDigits(no/10) + no%10;

	return no;
}
