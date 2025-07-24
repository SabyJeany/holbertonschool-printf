#include "main.h"

/**
 * handle_format - Handles conversion specifiers
 * @c: Specifier character
 * @args: Argument list
 *
 * Return: Characters printed
 */
int handle_format(char c, va_list args)
{
	char *str, ch;
	int count = 0;

	if (c == 'c')
	{
		ch = va_arg(args, int);
		write(1, &ch, 1);
		return (1);
	}
	else if (c == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		while (*str)
			count += write(1, str++, 1);
		return (count);
	}
	else if (c == '%')
		return (write(1, "%", 1));

	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}
