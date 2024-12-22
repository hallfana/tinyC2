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

fclean: clean
	rm -f $(NAME)-client
	rm -f $(NAME)-server

re: clean all

dev:
	make fclean
	git add .; git commit -m "dev"; git push origin wtf-i-am-doing
	make re
	make clean
	./$(NAME)-server

.PHONY: all clean fclean re