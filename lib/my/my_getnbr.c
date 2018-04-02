/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** my_desc
*/

#include "my_getnbr.h"

void bypass_all_main(int a[], char *str)
{
	for (;str[a[3]] == 0x30; a[3] = a[3] + 1);
	if (str[a[3]] > 0x2f && str[a[3]] < 0x3a)
		str = str + a[3];
	else if (a[3] > 0)
		str = str + a[3] - 1;
	while (str[a[1]] != '\0' && a[1] < 2147483647 && \
		str[a[1]] > '/' && str[a[1]] < ':')
		a[1] = a[1] + 1;
	return;

}
const char *bypass_all(char const *str, int *sign, int *size)
{
	int a[] = {0, 0, 0, 0, 0};

	for (;str[a[0]] == '+' || str[a[0]] == '-'; a[0] = a[0] + 1) {
		if (str[a[0]] == '-')
			a[2] = a[2] + 1;
	}
	if ((a[2] % 2))
		*sign = (-1);
	else
		*sign = (1);
	str = str + a[0];
	bypass_all_main(a, (char *) str);
	*size = a[1];
	return (str);
}

int evolved_algo(int nb, const char *str, int end, int sign)
{
	int i = 1;

	if (end < 10) {
		while (i < end) {
			nb = nb * 10;
			nb = nb + (str[i] - 0x30);
			i = i + 1;
		}
		return (sign * nb);
	} else if (end == 10) {
		if (!verify_for_max("2147483648", str))
			return (0);
		while (i < 10) {
			nb = nb * 10;
			nb = nb + (str[i] - 0x30);
			i = i + 1;
		}
		return (sign * nb);
	} else
		return (0);
}

int my_getnbr(char const *str)
{
	char *str2;
	int sign;
	int end;
	int nb = 0;

	str2 = (char *) bypass_all(str, &sign, &end);
	if (str2[0] < 0x2f || str2[0] > 0x3a)
		return (0);
	if (sign == -1) {
		if (compare_min("2147483648", str2))
			return (-2147483648);
	}
	nb = str2[0] - 0x30;
	return (evolved_algo(nb, str2, end, sign));
}
