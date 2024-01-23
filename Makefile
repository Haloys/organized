##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME 	= organized

RM	= rm -f

MAKE 	= make

OBJ	= $(SRC:.c=.o)

INCLUDE = -I ./include/

LIB = -L ./lib/my/ -lmy

LIBSHELL = -L ./libshell/ -lshell

SRC =	src/main.c		\
	src/add.c		\
	src/del.c		\
	src/sort.c		\
	src/sort_utils.c	\
	src/disp.c		\
	src/merge_sort.c	\
	src/valid_add.c

all: $(NAME)

$(NAME):
	cd lib/my/ && $(MAKE)
	gcc $(SRC) -o $(NAME) $(INCLUDE) $(LIB) $(LIBSHELL)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
