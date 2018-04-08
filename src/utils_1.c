/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils.c
*/

#include "my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

int get_nbr(char const *str, int nbr, int signe, int start)
{
	if (*str == '\0')
		return (nbr * signe);
	else if (*str == '-' && start == 1 && (*(str + 1) > 48 || *(str + 1)
		<= 57 || *(str + 1) == '-'))
		return (get_nbr(str + 1, nbr, -signe, 1));
	else {
		if ((*str == '\0') || ((*str > 57 || *str < 48) && start == 0))
			return (nbr * signe);
		else if (*str >= '0' && *str <= '9')
			return (get_nbr(str + 1, (nbr * 10 + *str - 48),
				signe, 0));
		else
			return (*str++ ? get_nbr(str++, nbr, signe, start) : 0);
	}
}

int my_getnbr(char const *str)
{
	if (!str || !*str)
		return (0);
	return ((get_nbr(str, 0, 1, 1)));
}

void my_put_nbr(int nb)
{
	if (nb < -2147483647)
		my_putstr("-2147483648");
	else if (nb < 0) {
		nb = nb * -1;
		my_putchar('-');
	} else if (nb >= 10) {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	} else
		my_putchar(nb + '0');
}