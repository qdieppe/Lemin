all : make

make :
	gcc -o lem-in *.c -I include
clean :
	rm -f *.o
fclean :
	rm -f lem-in
re : fclean all
