NAME = lem-in

SRC_PATH = ./src/

SRC_NAME =	algo.c check.c \
			display.c lsttool.c \
			multipass.c strtool.c \
			tool.c get_next_line.c \
			main.c read.c \
			takeallpath.c displaypars.c \
			printtool.c

CC = gcc
FLAGS = -Wall -Werror -Wextra
DEL = rm -rf

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
		$(DEL) ./include/lemin.h.gch

fclean: clean
		$(DEL) $(NAME)

re: fclean all

.PHONY: all clean fclean re
