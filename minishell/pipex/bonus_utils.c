/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:29:29 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/17 13:39:34 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "minishell.h"

int	helper_free(char **args, char *argv, char *path, int ret)
{
	free_arr(args);
	perror(argv);
	if (path != NULL)
		free(path);
	return (ret);
}

int	slash_found(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

static void	fd_check(int read, int write)
{
	if (read != STDIN_FILENO && dup2(read, STDIN_FILENO) < 0)
		(perror("dup2"), exit(1));
	if (write != STDOUT_FILENO && dup2(write, STDOUT_FILENO) < 0)
		(perror("dup2"), exit(1));
	if (read > 2)
		close(read);
	if (write > 2)
		close(write);
}

static int	pre_checks(char	*path, char **argv, int slash)
{
	struct stat	st;

	if (stat(path, &st) == -1)
	{
		if (!slash && errno == ENOENT)
			return (free(path), bad_path(argv), 127);
		return (free(path), perror(argv[0]), 127);
	}
	if (S_ISDIR(st.st_mode))
	{
		write(2, "minishell: ", 11);
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, ": Is a directory\n", 17);
		return (free(path), 126);
	}
	if (access(path, X_OK) == -1)
		return (free(path), perror(argv[0]), 126);
	return (0);
}

int	process1_5(int read, int write, char **argv, char **envp)
{
	char	*path;
	int		slash;
	int		status;

	fd_check(read, write);
	if (!argv || !argv[0])
		return (1);
	slash = slash_found(argv[0]);
	if (slash)
		path = ft_strdup(argv[0]);
	else
		path = path_constructor(argv[0], envp);
	if (!path)
		return (bad_path(argv), 127);
	status = pre_checks(path, argv, slash);
	if (status > 0)
		return (status);
	execve(path, argv, envp);
	if (!slash && errno == ENOENT)
		return (free(path), bad_path(argv), 127);
	if (errno == ENOENT)
		return (free(path), perror(argv[0]), 127);
	if (errno == EACCES)
		return (free(path), perror(argv[0]), 126);
	return (free(path), perror(argv[0]), 1);
}
