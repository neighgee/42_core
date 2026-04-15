# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 17:22:36 by mwin              #+#    #+#              #
#    Updated: 2025/09/12 10:02:16 by mwin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = Libft
SRC_DIR = .

SRC = check_arguments.c check_integers.c input_rank.c main.c operations.c pa_pb.c ra_rb_rr.c radix_sort.c rra_rrb_rrr.c sa_sb_ss.c small_stack_sort.c stack_node_utils.c utils.c
OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CCFLAGS) -I$(SRC_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
