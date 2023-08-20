SRCS = main.c push_swap.h

CC = gcc 
CC_FLAGS = -Llibft 
%.o: %.c libft/libft.a
	$(CC) -c $< -o $@
all: libft main
libft:
	@make -C libft
main: $(SRCS:.c=.o)
	$(CC) $(CC_FLAGS) $^ -o main
clean:
	@make -C libft clean
	@rm -f $(SRCS:.c=.o)
fclean: clean
	@make -C libft fclean
	@rm -f main
re: fclean all
