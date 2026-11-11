C = -Wall -Wextra -Werror
NAME = libft.a
files = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

all : $(NAME)

ob = $(files:.c=.o)

$(NAME) : $(ob)
	ar rcs $(NAME) $(ob)
%.o : %.c
	cc $(C) -I includes -c $< -o $@

clean:
	rm -f $(ob)
fclean: clean
	rm -f $(NAME)
re : fclean all
