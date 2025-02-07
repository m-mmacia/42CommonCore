NAME = so_long

SRC = so_long.c moves.c map_utils.c map_read.c map_check.c draw_game.c \
      libs/ft_printf/src/ft_printf.c libs/ft_printf/src/ft_number.c \
      libs/ft_printf/src/ft_word.c libs/gnl/get_next_line.c \
      libs/gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

INC_DIR = -Ilibs/ft_printf -Ilibs/gnl -Ilibs/minilibx

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -Llibs/minilibx -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(OBJ) $(CFLAGS) $(LFLAGS) -o $(NAME)

%.o: %.c
	@gcc -c $< -o $@ $(CFLAGS) $(INC_DIR)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
