/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** ...
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

void my_putnbr(int nbr)
{
	if (nbr >= 0 && nbr < 10) {
		my_putchar(nbr + 48);
	} else if (nbr < 0) {
		my_putchar('-');
		my_putnbr(-nbr);
	} else {
		my_putnbr(nbr / 10);
		my_putchar(nbr % 10 + 48);
	}
}

static void disp_param(char *str, va_list ap)
{
	char *s;

	if (*str == 'c')
		my_putchar((char) va_arg(ap, int));
	else if (*str == 'd') {
		my_putnbr((int) va_arg(ap, int));
	} else {
		;
		if (*str == 's' && (s = va_arg(ap, char *)))
			write(1, s, my_strlen(s));
		else if (*str == 's')
			write(1, "(null)", 6);
		else {
			write(1, "%", 1);
			write(1, str, 1);
		}
	}
}

void my_printf(char *str, ...)
{
	va_list ap;

	for (va_start(ap, str); *str; str++) {
		if (*str == '%' && *(str + 1)) {
			disp_param(str + 1, ap);
			str += 1;
		} else {
			write(1, str, 1);
		}
	}
	va_end(ap);
}