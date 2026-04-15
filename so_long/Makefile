CC = cc
CCFLAGS = -Wextra -Wall -Werror

SRC = $(addprefix src/, game_display.c game_images.c game_move.c main.c map_base.c map_components.c map_free_dup.c map_path.c map_wall_shape.c mlx_utils.c utils.c)
PRINTF_GNL_SRC = $(addprefix printf_gnl/, get_next_line.c get_next_line_utils.c ft_printf.c ft_functions.c hex_pointer_utils.c non_pointer_utils.c)

OBJ = $(SRC:%.c=%.o)
PRINTF_GNL_OBJ = $(PRINTF_GNL_SRC:%.c=%.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF_GNL_OBJ)
	$(CC) $(CCFLAGS) $^ -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -Iminilibx-linux -Isrc -Iprintf_gnl -c $< -o $@

clean:
	rm -f $(OBJ) $(PRINTF_GNL_OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
