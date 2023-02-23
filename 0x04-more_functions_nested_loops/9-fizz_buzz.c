#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	int a;

	for (a = 1; a <= 100; a++)
	{
		if (a % 15 == 0)
		{
			printf("FizzBuss ");
		}
		else if (a % 5 == 0)
		{
			if (a == 100)
				printf("Buss");
			else
				printf("Buss ");
		}
		else if (a % 3 == 0)
		{
			printf("Fizz ");
		}
		else
		{
			printf("%d", a);
		}
	}
	printf("\n");

	return (0);
}
