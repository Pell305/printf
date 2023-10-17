#include "main.h"

/**
 * printf_d_i - Print an integer using _printf
 * @args: Argument list that contains the integer to print
 * @flags: Flags to apply to the output
 * @width: Minimum width of the output
 * @precision: Number of decimal places for the output
 *
 * Return: Number of characters printed
 */
int printf_d_i(va_list args, int flags, int width, int precision)
{
	int len = 0;
	char padd = ' ';

	if (flags & F_ZERO)
		padd = '0';

	if (flags & F_LONG)
		len += write_number(va_arg(args, long), flags, width, precision, padd, 0);
	else if (flags & F_SHORT)
		len += write_number((short)va_arg(args, int), flags, width, precision, padd, 0);
	else
		len += write_number(va_arg(args, int), flags, width, precision, padd, 0);

	return (len);
}
