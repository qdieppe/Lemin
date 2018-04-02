/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header lib
*/

#ifndef MY_H
#define MY_H

void bypass_all_main(int a[], char *str);
const char *bypass_all(char const *str, int *sign, int *size);
int evolved_algo(int nb, const char *str, int end, int sign);
int my_getnbr(char const *str);
int compare_min(char *str, char *my_str);
int verify_for_max(const char *str, const char *my_str);
int my_put_nbr(int nb);
void put_min_value(void);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char *src);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char *str);
char *my_strlowcase(char *str);

#endif
