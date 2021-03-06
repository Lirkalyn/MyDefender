##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

#.PHONY : clean fclean re
.PHONY	:	$(NAME) clean fclean re

NAME	=	my_defender

SRC		=	main.c \
			main_2.c \
			scr/display.c \
			scr/cmp.c \
			scr/interaction.c \
			scr/fill.c \
			scr/enemy.c \
			scr/tower.c \
			scr/tower_2.c \
			scr/tower_3.c \
			scr/tower_4.c \
			scr/menu.c \
			scr/draw.c \
			scr/pause.c

OBJ		=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
			gcc $(OBJ) -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -Wall -Wextra

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean $(NAME)

#.PHONY	:	all $(NAME) clean fclean re
