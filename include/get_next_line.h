/*
** EPITECH PROJECT, 2018
** gnl_header
** File description:
** 
*/

#ifndef GNL_H
#define GNL_H

#ifndef READ_SIZE
#define READ_SIZE 42
#endif

void make_buf(char buf[]);
char *alloc_strcat(char *str1, char *str2);
char *is_inbuf(char *buf);
char *get_new_line(int fd, char *buffer);
char *get_next_line(int fd);

#endif
