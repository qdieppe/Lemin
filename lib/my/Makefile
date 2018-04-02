NAME = libmy.a
OBJ = my.h

all : $(NAME)

$(NAME) : *.c
	gcc -c *.c -I ../../include/
	ar rc libmy.a *.o
	cp $(NAME) ../
	cp $(NAME) ../../
	cp $(OBJ) ../../include/
clean : *.o
	rm *.o
fclean : clean
	rm -f $(NAME)
re : fclean all
	
