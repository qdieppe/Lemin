/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** my_desc
*/

#ifndef NAVY_H
#define NAVY_H

#define MAP_SIZE 8
#define IS_DIGIT(c) (c >= '1' && c <= '8') //inferieur a 8 pour check direct valeur max
#define IS_POINT(c) (c == ':')
#define IS_CHAR(c) (c >= 'A' && c <= 'H') //inferieur a H pour check 8 max direct

typedef struct string_list
{
	char *my_pid;
	char *wait_enemy_co;
	char *success_co;
	char *success_enemy_co;
	char *my_position;
	char *enemy_position;
	char *attack;
	char *wrong_position;
	char *missed;
	char *hit;
	char *wait_enemy_attack;
	char *i_won;
	char *enemy_won;
}string_list;

typedef struct navy_map
{
	char map[MAP_SIZE][MAP_SIZE];
}navy_map;

typedef struct ressources
{
	navy_map my_pos;
	navy_map enemy_pos;
	string_list strings;
}ressources;

void init_navy_res(ressources *res);
ressources *get_navy_res();
string_list *get_navy_strings();
navy_map *get_navy_my_pos();
navy_map *get_navy_enemy_pos();
void init_my_map();
void init_enemy_map();
void init_maps();
char *get_code(char *line);
int get_attack_val(int *val, int *val2);
int first_to_attack(pid_t enemy_pid);
int second_to_attack(pid_t enemy_pid);
int attack(int argc, pid_t enemy_pid);
char *get_code(char *line_send);
int help(void);
void navy_putstr_my_map(int line);
void navy_putstr_enemy_map(int line);
void navy_print_my_map(void);
void navy_print_enemy_map(void);
int load_map_from_file(char *file_name);
int add_to_map(char *line);
int errorgestion(char *line, int nb);
int errorgestion_evolved(char *line);
char char_to_print(char *line);
void print_pos(void);
int main_navy_2(pid_t my_pid, pid_t enemy_pid);
int main_navy_3(pid_t my_pid, pid_t enemy_pid);
int no_boat(void);
int cross_says_you_win(void);
int cross_says_you_lose(void);
int update_enemy_map(int res, int x, int y);
int navy_3_arg(int argc, char **argv);
int navy_2_arg(int argc, char **argv);
pid_t *get_enemy_pid();
pid_t get_enemy_first_pid();
void send_value(pid_t pid, int nb);
char *get_next_line(int);
int *get_message_val(void);
int *get_running_value(void);
void handler_sigusr1(int dummy);
void handler_sigusr2(int dummy);
int binder(void);

#endif
