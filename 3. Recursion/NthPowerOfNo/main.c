#include <stdio.h>
#include <stdint.h>

uint32_t nthPowerOfN(uint32_t no,uint32_t pow);

int main()
{
	uint32_t no;
	uint32_t pow;
	uint32_t result;

	while(1)
	{
		printf("Enter No: \r\n");
		scanf("%d",&no);

		printf("Enter Power: \r\n");
		scanf("%d",&pow);

		result = nthPowerOfN(no,pow);
		printf("%d\r\n",result);
	}
}


uint32_t nthPowerOfN(uint32_t no,uint32_t pow)
{
	int result;

	if(pow == 1)
	{
		return no;
	}

	result = no * nthPowerOfN(no, pow-1);

	return result;
}
