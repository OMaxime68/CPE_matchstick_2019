##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	matchstick.c \
		match.c \
		stick.c \
		help.c \
		helped.c

NAME	=	matchstick

all:	$(NAME)

$(NAME):
	make -sC ./lib/my/
	gcc -o $(NAME) $(SRC) -L ./lib/my/ -I ./include/ -lmy -lm

clean:
	make fclean -sC ./lib/my/

fclean:	clean
	rm -f $(NAME)

re: fclean all

debug:
	make -sC ./lib/my/
	gcc -o $(NAME) $(SRC) -L ./lib/my/ -I ./include/ -lmy -g
