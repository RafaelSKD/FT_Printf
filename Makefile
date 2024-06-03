SRC = ft_printf.c \
      ft_putchar.c \
      ft_putnbr.c \
      ft_putstr.c \
      put_hex.c \
      put_pointer.c \
      putnbr_u.c \
      ft_itoa.c \
      ft_utoa.c \
      ft_strlen.c \
      ft_strchr.c \

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror

HEADER = printf.h

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME) main

re: fclean all

main: $(SRC)
	$(CC) $(FLAGS) $^ -o $@

.PHONY: all clean fclean re main
