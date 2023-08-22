#include "main.h"
#include <stdarg.h>
#include <string.h>
/*
 * _printf - function to pint a nbr of char
 * @format: the string to print
 *
 * Return: Fotmat
 */
int _printf(const char *format, ...)
{
	int  j = 0, nchar = 0;
	const char *s;
	unsigned int lenn, i;
	va_list(args);

	va_start(args, format);
	lenn = strlen(format);

	if (format != NULL)
	{
	for (i = 0 ; i < lenn ; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			nchar++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
				_putchar(va_arg(args, int));
			if (format[i] == 's')
			{
				s = va_arg(args, char *);
				while (s[j] != '\0')
				{
					_putchar(s[j]);
					j++;
				}
			}
			if (format[i] == '%')
				_putchar('%');

			if (format[i] == 'd' || format[i] == 'i')
				_putchar(va_arg(args, int));
		}
	}
	}
	return (nchar);
	va_end(args);
}
