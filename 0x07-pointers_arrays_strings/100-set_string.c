#include "main.h"

/**
 * set_string -  a function that sets the value of a pointer to a char
 * @s: source
 * @to: the variable to set it to.
 */
void set_string(char **s, char *to)
{
	while (*to != '\0')
	{
		**s = *to;
		(*s)++;
		to++;
	}
	**s = '\0';
}
