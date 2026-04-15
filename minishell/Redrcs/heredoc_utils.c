/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:05:22 by mwin              #+#    #+#             */
/*   Updated: 2026/02/13 12:37:07 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join2(char *one, char *two)
{
	char	*onetwo;

	onetwo = ft_strjoin(one, two);
	return (onetwo);
}

static char	*make_hd_path(int count)
{
	char	*nbr;
	char	*path;

	nbr = ft_itoa(count);
	if (!nbr)
		return (NULL);
	path = join2("/tmp/.minishell_hd_", nbr);
	free(nbr);
	return (path);
}

t_hered	*last_hd(t_hered *heredoc)
{
	while (heredoc && heredoc->next)
		heredoc = heredoc->next;
	return (heredoc);
}

// 600 means only the file's owner has the ability
//to read and write (modify) the file
int	open_hds(char **out_path)
{
	static int	count;
	int			fd;
	char		*path;

	if (!out_path)
		return (-1);
	*out_path = NULL;
	while (count < 1000000)
	{
		path = make_hd_path(count);
		if (!path)
			return (-1);
		fd = open(path, O_CREAT | O_EXCL | O_WRONLY, 0600);
		if (fd >= 0)
			return (*out_path = path, count++, fd);
		if (access(path, F_OK) == 0)
		{
			free(path);
			count++;
			continue ;
		}
		perror(path);
		return (free(path), -1);
	}
	return (-1);
}
