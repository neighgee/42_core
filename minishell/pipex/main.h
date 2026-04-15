/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:58:54 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/16 15:33:44 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "Libft/libft.h"
# include "pipex/main.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "minishell.h"

// Utility functions
char	**get_paths(char **envp);
char	*path_constructor(char *arr, char **envp);
void	no_space_for_exit(char *statement, int status);
void	free_arr(char **arr);
void	write_for_me(int writefd, int readfd);

// Main functions
int		helper_free(char **args, char *argv, char *path, int ret);

//bonus_utils
int		process1_5(int read, int write, char **argv, char **envp);

void	initialise_child_signals(void);
#endif