##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## lem_in
##

NAME	=	lem_in

SRC	=	src/get_file.c \
		src/init_data_struct.c \
		src/main.c \
		src/my_printf.c \
		src/utils_1.c \
		src/utils_2.c \
		src/utils_3.c \
		src/utils_4.c \
		src/verif_file_1.c \
		src/verif_file_1_norm.c \
		src/verif_file_1_norm_2.c \
		src/verif_file_2.c \
		src/verif_rooms_and_pipes_match.c \
		src/backtrack.c \
		src/backtrack_utils_1.c \
		src/backtrack_utils_2.c \
		src/backtrack_utils_3.c \
		src/make_first_current.c \
		src/display_way.c \
		src/dijkstra.c \
		src/dijkstra_utils.c \
		src/clean_array.c \
		src/display_shortcut.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Wall -g3 -O3 -fno-builtin -Iinc/

LDFLAGS	=	-I include/

all: $(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
				$(RM) -f $(OBJ)

fclean: clean
				$(RM) -f $(NAME)

re: fclean
		@$(MAKE) all

.PHONY: all clean fclean re
