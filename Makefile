NAME=tinyC2

all: $(NAME)

$(NAME):
	make -C client
	make -C server
	mv client/$(NAME)-client ./$(NAME)-client
	mv server/$(NAME)-server ./$(NAME)-server

clean:
	make -C client clean
	make -C server clean
	rm -f $(NAME)-client $(NAME)-server

fclean: clean
	rm -f $(NAME)

re: clean all

dev:
	git add .; git commit -m "dev"; git push
	make re

.PHONY: all clean fclean re