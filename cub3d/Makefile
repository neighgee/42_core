# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/20 16:17:53 by smariapp          #+#    #+#              #
#    Updated: 2026/04/11 20:23:06 by mwin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
BONUS_NAME = cub3D_bonus

CC = cc
FLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./Libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = ./minilibx-linux/
MLX = $(MLX_DIR)libmlx.a

SRC = main.c kinda_like_libft.c frees.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	validation/colours_check.c validation/map_check.c validation/parse.c \
	validation/textures_check.c  validation/map_check2.c\
	mlx_fns/cleanup.c mlx_fns/initialise.c mlx_fns/textures.c\
	rendering/game_colours.c rendering/map_size.c rendering/player.c\
	rendering/rays_utils.c rendering/raycasting.c rendering/textures.c rendering/minimap.c
SRC_MAN = $(SRC) mlx_fns/movement.c
SRC_BONUS = $(SRC) mlx_fns/movement_bonus.c

OBJ = $(SRC_MAN:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -L/usr/lib/X11 -lm -o $(NAME)

$(BONUS_NAME): $(OBJ_BONUS) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(OBJ_BONUS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -L/usr/lib/X11 -lm -o $(BONUS_NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(FLAGS) -I. -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all

iclean:
	rm -f $(OBJ) $(OBJ_BONUS)

it: re iclean

.PHONY: all clean fclean re iclean it
