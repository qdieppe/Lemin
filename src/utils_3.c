/*
** EPITECH PROJECT, 2018
** utils2.c
** File description:
** utils2.c
*/

#include "my.h"

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')) {
		i++;
	}
	return (s1[i] - s2[i]);
}

char **str_to_word_tab(char *buff, char separator)
{
	char **str;
	int i = 0;
	int j = 0;

	for (; buff && buff[j]; j++)
		if (buff[j] == separator)
			i++;
	str = my_calloc(sizeof(char *) * (i + 4));
	for (i = 0; buff && *buff; i++) {
		for (j = 0; buff[j] && buff[j] != separator; j++);
		str[i] = my_calloc(sizeof(char) * (j + 1));
		for (j = 0; *buff && *buff != separator; buff++)
			str[i][j++] = *buff;
		str[i][j] = '\0';
		buff = *buff ? buff + 1 : buff;
	}
	str[i] = NULL;
	return (str);
}

void free_word_tab(char **str)
{
	int i = 0;

	for (; str[i]; free(str[i++]));
	free(str);
}

char *clear_str(char *buff)
{
	int i = 0;
	int j = 0;
	char *str = malloc(sizeof(char*) * (my_strlen(buff) + 1));

	for (; buff[i] != '\0'; i++)
		if (buff[i] == '\t')
			buff[i] = ' ';
	for (i = 0; buff[i] == ' '; i++);
	for (; buff[i] != '\0'; str[j++] = buff[i++]) {
		for (; buff[i] == ' ' && buff[i + 1] == ' '; i++);
		if ((buff[i] == ' ' || buff[i] == '\t') &&
			buff[i + 1] == '\0') {
			str[j] = '\0';
			return (str);
		}
	}
	str[j] = '\0';
	return (str);
}