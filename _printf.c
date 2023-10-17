#include "main.h"
#include <stdarg.h>  /* Include the necessary header for va_list */

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);  /* Ensure _putchar is defined */
			count++;
		}
		else if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);  /* Ensure _putchar is defined */
				count++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				if (str)
				{
					while (*str)
					{
						_putchar(*str);  /* Ensure _putchar is defined */
						count++;
						str++;
					}
				}
			}
			else if (format[i] == '%')
			{
				_putchar('%');  /* Ensure _putchar is defined */
				count++;
			}
			else
			{
				_putchar('%');  /* Ensure _putchar is defined */
				_putchar(format[i]);  /* Ensure _putchar is defined */
				count += 2;
			}
		}
		i++;
	}

	va_end(args);
	return (count);
}
