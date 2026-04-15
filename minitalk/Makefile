# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 15:33:11 by mwin              #+#    #+#              #
#    Updated: 2025/09/20 11:26:58 by mwin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = .
CLIENT_DIR = client_files
SERVER_DIR = server_files

CLIENT_SRC = client_main.c
SERVER_SRC = server_main.c
CLIENT_BONUS_SRC = client_main_bonus.c
SERVER_BONUS_SRC = server_main_bonus.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

NAME_CLIENT = client
NAME_SERVER = server
NAME_BONUS_CLIENT = client_bonus
NAME_BONUS_SERVER = server_bonus

all: $(NAME_CLIENT) $(NAME_SERVER)
bonus: $(NAME_BONUS_CLIENT) $(NAME_BONUS_SERVER)

$(NAME_CLIENT): $(LIBFT) $(CLIENT_OBJ)
	$(CC) $(CCFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_BONUS_CLIENT): $(LIBFT) $(CLIENT_BONUS_OBJ)
	$(CC) $(CCFLAGS) $(CLIENT_BONUS_OBJ) $(LIBFT) -o $(NAME_BONUS_CLIENT)

$(NAME_SERVER): $(LIBFT) $(SERVER_OBJ)
	$(CC) $(CCFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(NAME_SERVER)

$(NAME_BONUS_SERVER): $(LIBFT) $(SERVER_BONUS_OBJ)
	$(CC) $(CCFLAGS) $(SERVER_BONUS_OBJ) $(LIBFT) -o $(NAME_BONUS_SERVER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CCFLAGS) -I$(SRC_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_BONUS_CLIENT) $(NAME_BONUS_SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
