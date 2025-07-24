#include "main.h"

/**
 * _printf - Prints formatted output to stdout
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
<<<<<<< HEAD

			if (format[i] == '\0')
				va_end(args);
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == '%')
				count += print_percent();
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_int(args);
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}

=======
			count += handle_format(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
>>>>>>> 3e486b1547740751bd9d181cef26c285f55ea185
		}
		i++;
	}
	return (0);
}
