/*
 * In Tower Of Hanoi we have three towers(A,B,C) and n disks of different sizes.
 * We need to move all disks from tower A to tower C without placing the large disks
 * on small disks using tower B as an helping tower.
 *
 */

#include <stdio.h>
#include <stdint.h>

uint32_t towerOfHanoi(uint32_t n, char a, char b, char c);

int main()
{
	char source = 'a';
	char helper = 'b';
	char destination = 'c';
	int n;

	while(1)
	{
		printf("Enter no of disks: \r\n");
		scanf("%d",&n);

		towerOfHanoi(n, source, helper, destination);
	}
}

uint32_t towerOfHanoi(uint32_t n, char a, char b, char c)
{
	if(n == 1)
	{
		printf("Move Disk %d from %c to %c\n",n,a,c);
		return 1;
	}
	towerOfHanoi(n-1, a, c, b);	//Move n-1 disks from a to b using c as helping
	printf("Move Disk %d from %c to %c\n",n,a,c);
	towerOfHanoi(n-1, b, a, c);	//Move n-1 disks from b to c using a as helping
	return 1;
}
