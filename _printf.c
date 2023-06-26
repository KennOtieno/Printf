#include "main.h"
#include <stdarg.h>

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - printf
 * @format: format
 *
 * Return: none
 */
int _printf(const char *format, ...)
{
	int a, printed = 0, printed_chars = 0;
	int flags, precision, width, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[a], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &a);
			precision = get_precision(format, &a, list);
			width = get_width(format, &a, list);
			size = get_size(format, &a);
			++a;
			printed = handle_print(
				format, &a, list, buffer, flags,
				precision, width, size
				);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - print every buffer
 * @buff_ind: index
 * @buffer: characters arrays
 *
 * Return: none
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
