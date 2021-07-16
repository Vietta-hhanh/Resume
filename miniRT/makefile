FLAG = -Wall -Wextra -Werror

NAME = miniRT.a

SRC =	./srcs/get_next_line.c\
		./srcs/get_next_line_utils.c\
		./srcs/utils.c
ADD =	./srcs/ft_split.o\
		./srcs/ft_atoi.o

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ) $(ADD)

.c.o:
	gcc  -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re .c.o
