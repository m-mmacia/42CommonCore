CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ./src/ft_printf.c ./src/ft_word.c ./src/ft_number.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : clean all
