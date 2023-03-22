#include "3-calc.h"

/**
 * op_add - Add  two argument.
 * @a: First argument.
 * @b: Second argument.
 *
 * Return: Value.
 */
int op_add(int a, int b)
{
	int sum;

	sum = a + b;
	return (sum);
}

/**
 * op_sub - Subtract two argument.
 * @a: First argument.
 * @b: Second argument.
 *
 * Return: Value.
 */
int op_sub(int a, int b)
{
	int sub;

	sub = a - b;
	return (sub);
}

/**
 * op_mul - Multiplies two argument.
 * @a: First argument.
 * @b: Second argument.
 *
 * Return: Value.
 */
int op_mul(int a, int b)
{
	int mul;

	mul = a * b;
	return (mul);
}

/**
 * op_div - Divides two arguments.
 * @a: First argument.
 * @b: Second argument.
 *
 * Return: Value.
 */
int op_div(int a, int b)
{
	int div;

	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	div = a / b;
	return (div);
}

/**
 * op_mod - Modulus of two argument.
 * @a: First argument.
 * @b: Second argument.
 *
 * Return: Value.
 */
int op_mod(int a, int b)
{
	int mod;

	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	mod = a % b;
	return (mod);
}
