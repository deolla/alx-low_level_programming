#include "main.h"

/**
 * num - helper function
 * @sum: variable.
 * @n: variable.
 *
 * Description: helper function for counter argument
 * Return: 1 if prime, 0 else.
 */
int num(int sum, int n)
{
	if (n % sum ==  0 || n < 2)
		return (0);
	else if (n / sum == 1)
		return (1);
	else
		return (num(sum + 1, n));
}

/**
 * is_prime_number -  a function that returns a value if
 * the input integer is a prime number.
 * @n: variable
 *
 * Description: a function that returns a value.
 * Return: 1 or 0
 */
int is_prime_number(int n)
{
	return (num(2, n));
}
