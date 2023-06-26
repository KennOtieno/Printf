#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_SHORT 1
int _printf(const char *format, ...);

/**
 * typedef struct format - the format for printf
 * @f1: format character
 * @ff1: funtion for the format
 */
typedef struct format
{
	char f1;
	int (ff1)(
#endif
