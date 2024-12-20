NAME=tinyC2

CC=gcc
CC_FLAGS= -Wall -Wextra -Werror -lpthread

SRC= ./src/main.c \
	 ./src/server.c \
	 ./src/utils/strlen.c \
	 ./src/utils/nblen.c \
	 ./stc/utils/hash.c \
	 ./src/print.c \
	 ./src/cleanup.c \
	 ./src/format.c \
	 ./src/listener.c \
	 ./src/client/handler.c \
	 ./src/client/linked_list.c \

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -g -fsanitize=address -o $(NAME)-server

%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

