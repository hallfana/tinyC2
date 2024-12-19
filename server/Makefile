NAME=tinyC2

CC=gcc
CC_FLAGS= -Wall -Wextra -Werror -g

SRC= ./src/main.c \
	 ./src/server.c \
	 ./src/utils.c \
	 ./src/error.c \

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)-server

%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

