#include "main.h"

/**
 * num - function without argument
 * @root: int type
 * @n: int type
 *
 * Description: Test the conditions.
 * Return: value of root
 */
int num(int root, int n)
{
	if (n == (root * root))
		return (root);
	else if (root == n || root == -n)
		return (-1);
	else
		return (num(root + 1, n));
}

/**
 * _sqrt_recursion - function that returns the natural square root of a number
 * @n: int variable.
 *
 * Description: returns the natural square root of a number.
 * Return: value of n
 */
int _sqrt_recursion(int n)
{
	return (num(0, n));
}
