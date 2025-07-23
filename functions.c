#include "main.h"

/**
 * print_char - Prints a character
 *@args: list of arguments from _printf
 *
 * Return: Number of characters printed (1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @args: list of arguments from _printf
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0;

	if (!s)
		s = "(null)";

	while (s[i])
		write(1, &s[i++], 1);

	return (i);
}

/**
 * print_percent - Prints a percent sign(%)
 *
 * Return: Number of charcters printed (1)
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}

/**
 * print_int - Prints an integer
 * @args: list of arguments from _printf
 *
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	char buffer[20];
	int i = 0;

	if (n == 0)
		return (write(1, "0", 1));

	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}

	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}
