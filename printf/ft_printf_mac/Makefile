FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = 	./ft_prinft.c\
		./sources/ft_converter.c\
		./sources/ft_dissolve.c\
		./sources/ft_predeterminer.c\
		./sources/ft_xupcsolve.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) heade.h
	@make all -C ./libft
	@cp ./libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJ)

.c.o:
	@gcc $(FLAG) -c $< -o $@

clean:
	make clean -C ./libft
	@rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re .c.o
