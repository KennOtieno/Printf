#include <unistd.h>
/**
 * _putchar - writes character 'c' into the stdout
 * @c: character to be written
 * Return: interger value of character
 */
int _putchar(char c)
{
	return(write(1, &c, 1));
}
