FLAG = -Wall -Wextra -Werror

NAME = libft.a

SRC =ft_toupper.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_strlen.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_itoadub.c 


OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

.c.o:
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re .c.o
