/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:52:55 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/17 12:10:15 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	no_space_for_exit(char *statement, int status)
{
	perror(statement);
	exit(status);
}

void	write_for_me(int writefd, int readfd)
{
	size_t	b_read;
	char	buffer[1024];

	b_read = read(readfd, buffer, sizeof(buffer));
	while (b_read > 0)
	{
		write(writefd, buffer, b_read);
		b_read = read(readfd, buffer, sizeof(buffer));
	}
}

static char	*ensure_trailing_slash(char *s)
{
	int		len;
	char	*tmp;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
	{
		free(s);
		return (ft_strdup("./"));
	}
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '/')
		return (s);
	tmp = ft_strjoin(s, "/");
	free(s);
	return (tmp);
}

char	**get_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	paths = ft_split(ft_getenv_custom(envp, "PATH"), ':');
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		paths[i] = ensure_trailing_slash(paths[i]);
		i++;
	}
	return (paths);
}

char	*path_constructor(char *arr, char **envp)
{
	char	**paths;
	char	*join;
	int		i;

	i = 0;
	if (ft_strchr(arr, '/') != NULL && access(arr, F_OK) == 0)
		return (ft_strdup(arr));
	else if (ft_strchr(arr, '/') != NULL)
		return (NULL);
	paths = get_paths(envp);
	while (paths && paths[i])
	{
		join = ft_strjoin(paths[i], arr);
		if (access (join, F_OK) == 0)
		{
			free_arr(paths);
			return (join);
		}
		free(join);
		i++;
	}
	return (free_arr(paths), NULL);
}
