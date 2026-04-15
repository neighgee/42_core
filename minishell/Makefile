# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 15:33:11 by mwin              #+#    #+#              #
#    Updated: 2026/02/17 20:21:26 by mwin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
RLFLAG = -lreadline

SRC_DIR = .

SRC_FILES = minishell.c kinda_like_libft.c pipex/bonus_utils.c pipex/utilities.c frees.c\
			signals/exit_cmds.c signals/signals.c signals/signals2.c\
			Redrcs/input_redrcs.c Redrcs/input_redrcs2.c Redrcs/output_redrcs.c Redrcs/redrc_utils.c \
			Redrcs/heredoc_utils.c Redrcs/multiple_hd.c Redrcs/dealwith_space.c Redrcs/heredoc_child2.c\
			Parsing_cmds/check_redrc.c Parsing_cmds/check_remove_quotes.c Parsing_cmds/env_var.c Parsing_cmds/execute_cmds.c Parsing_cmds/execute_cmds_2.c\
			Parsing_cmds/input_checker.c Parsing_cmds/parser_utils.c Parsing_cmds/handle_quotes.c Parsing_cmds/redrc_sym_utils.c Parsing_cmds/fill_cmd.c\
			Parsing_cmds/store_cmd_list.c Parsing_cmds/syntax_utils.c Parsing_cmds/pipe_stuffs.c Parsing_cmds/redrc_syn.c Parsing_cmds/heredoc_syn.c\
			Parsing_cmds/fds.c  Parsing_cmds/syntax_utils2.c Parsing_cmds/check_remove_quotes2.c Redrcs/heredoc_child.c\
			Built_in_cmds/built_in_cmds.c Built_in_cmds/built_in_helper.c \
			Built_in_cmds/cd.c Built_in_cmds/cd2.c Built_in_cmds/echo.c Built_in_cmds/env.c Built_in_cmds/export.c \
			Built_in_cmds/export2.c Built_in_cmds/export_no_arg.c Built_in_cmds/pwd.c Built_in_cmds/unset.c \

SRC_OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = minishell

all: $(NAME)

$(NAME): $(LIBFT) $(SRC_OBJ_FILES)
	$(CC) $(CCFLAGS) $(SRC_OBJ_FILES) $(LIBFT) $(RLFLAG) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CCFLAGS) -I$(SRC_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(SRC_OBJ_FILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

it: re clean

.PHONY: all clean fclean re it
