/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <ncurses.h>
#include <dirent.h>
#include <getopt.h>

#ifndef MY_H
#define MY_H

typedef struct data {
	char** file_copy;
	int ants_nb;
	int cursor;
	char* room_name;
	int room_coor_x;
	int room_coor_y;
	char** tmp_rooms;
	char** tmp_only_rooms;
	char** tmp_tunnels;
	char* start_room;
	char* end_room;
} data;

typedef struct room {
	char *name;
	char *prev;
	int min_value;
	int visited;
} room;

typedef struct ways {
	char *room_name;
	int ant_number_present;
	int ant_present;
} ways;

typedef struct keeper {
	char **keep;
} keeper;

typedef struct garb {
	int line_of_ants_nb;
	int line_of_room_ref;
	int line_of_pipe_ref;
} garb;

struct garb *get_garb();

int room_verif(char *line, data *pdata, char **file_copy, int i);
int room_verif_norm(char **tab_line, char *line, data *pdata);
int links_verif(char *str);
void clean_input_file_norm(char **tab, int i, int j);
void clean_input_file(data *pdata);

char *make_new_current(struct data *pdata, char *current, char *room);
char *make_new_room(char *tunnel, char *room);
char **craft_new_room_table(char **room_table, char *room);
char **craft_new_rooms(char *tunnel, char **new_room);
int is_used(struct data *pdata, char *str, char *current, char *room);

char *get_room_name(char *str, char *self);
struct room *get_next_room(struct room *rooms, int size);
struct room *init_room_table(struct data *pdata);
struct room *get_room_named(char *name, struct room *rooms, int size);

char **clean_array(char **tab);
char **clear_tunnels(char **tab);

int get_file(data *pdata, char **av);
void init_data_struct(data *pdata);

int verif_file(data *pdata);
int verif_all_char(char **file_copy);
int start_and_end_verif(char **file_copy);
int get_verif_ant_nb(data *pdata, char *);

void fill_tmp_rooms(data *pdata, char *line);
void fill_tmp_tunnels(data *pdata, char *line);
char *clear_str(char *buff);

int verif_rooms_and_pipes_match(data *pdata);
char **clean_void_line(char **tab);
void select_only_rooms(data *pdata);

int start_chamber(data *pdata, char **, int i);
int end_chamber(data *pdata, char **, int i);

char **backtrack(struct data *pdata, char *current, char *room, char **room_table);
char *make_first_current(struct data *pdata, char *room);
unsigned int get_table_size(char **rooms);

keeper *room_keeper();
char **dijkstra(struct data *pdata);
char **add_to_ret(char **ret, char **other);
char *alloc_add(char *str, char *str2);
char **split_to_str(char **room_table);
char **add_str(char **ret, char *other);
int real_path(char **tab, ways **pways, data *pdata);
int value_of_rooms(data *pdata, ways **pways, int last_room);
int is_linked(char *, char *);

void display_shortcut(int x, char *str);

void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char *str);
char *my_strdup(char *src);
int my_getnbr(char const *str);
int my_strlen(char *str);
char *my_strcat(char *dest, char *src);
int my_strcmp(char *s1, char *s2);
int line_nb(char **tab);
void *my_calloc(int q);
int my_getnbr(char const *str);
char **str_to_word_tab(char *buff, char separator);
void *my_calloc(int q);
void free_word_tab(char **str);
int my_show_array(char **);
void *to_zero(void *data, int q);
int my_is_num(char *str);
int my_has_char(char *str, char c);
void my_printf(char *str, ...)
__attribute__((format(printf, 1, 2)));

#endif
