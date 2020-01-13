##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra

CPPFLAGS	+=	-I ./include

NAME_SOLVER	=	solver/solver

NAME_GENERATOR	=	generator/generator

SRC_GENERATOR	=	generator/browse_row.c	\
			generator/make_maze_perfect_imperfect.c \
			generator/generator.c	\
			generator/add_back_slash_0_and_n.c	\

SRC_SOLVER	=	solver/solve_maze.c		\
			solver/get_map.c		\
			solver/get_next_line.c		\
			solver/main.c			\

OBJS_GENERATOR	=	$(SRC_GENERATOR:.c=.o)

OBJS_SOLVER	=	$(SRC_SOLVER:.c=.o)

all: $(NAME_SOLVER) $(NAME_GENERATOR)

$(NAME_GENERATOR):	$(OBJS_GENERATOR)
		$(CC) -o $(NAME_GENERATOR) $(OBJS_GENERATOR)

$(NAME_SOLVER):	$(OBJS_SOLVER)
		$(CC) -o $(NAME_SOLVER) $(OBJS_SOLVER)
clean:
	$(RM) $(OBJS_SOLVER) $(OBJS_GENERATOR)

fclean: clean
	$(RM) $(NAME_SOLVER) $(NAME_GENERATOR)

re: fclean all

.PHONY: all clean fclean re
