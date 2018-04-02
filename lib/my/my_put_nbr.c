/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** put_nbr recursive version
*/

#include "my.h"

void put_min_value(void)
{
	my_putstr("-2147483648");
	return;
}

int my_put_nbr(int nb)
{
	char c;

	if (nb < 0) {
		if (nb == -2147483648) {
			put_min_value();
			return (0);
		} else {
			my_putchar('-');
			nb = -nb;
		}
	}
	c = (nb % 10) + 0x30;
	nb = nb - (nb % 10);
	if (nb / 10 > 0)
		my_put_nbr(nb / 10);
	my_putchar(c);
	return (0);
}
