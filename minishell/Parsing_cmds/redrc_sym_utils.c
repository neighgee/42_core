/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redrc_sym_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:58:27 by mwin              #+#    #+#             */
/*   Updated: 2026/02/16 10:38:06 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	touch_outfile(char *file, int append)
{
	int	fd;
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(file, flags, 0644);
	if (fd < 0)
		return (perror(file), -1);
	close(fd);
	return (0);
}

int	handle_output_redrc(t_command *cmd, char *target, int append, int fd)
{
	if (touch_outfile(target, append) < 0)
		return (-1);
	if (fd == 2)
	{
		free(cmd->stderr_file);
		cmd->stderr_file = ft_strdup(target);
		if (!cmd->stderr_file)
			return (-1);
		cmd->stderr_append = append;
		return (0);
	}
	free(cmd->output_file);
	cmd->output_file = ft_strdup(target);
	if (!cmd->output_file)
		return (-1);
	cmd->check_changes = append;
	return (0);
}

int	redir_skip(const char *token, int symbol)
{
	int	len;

	if (!token)
		return (2);
	if (token[0] == '\2')
		token++;
	len = 1;
	if (symbol == 2 || symbol == 3)
		len = 2;
	if (token[len])
		return (1);
	return (2);
}

int	ambig_redrc(const char *target)
{
	if (!target || !target[0])
		return (1);
	return (0);
}

int	redrc_last(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	return (len > 0 && (s[len -1] == '<' || s[len -1] == '>'));
}
