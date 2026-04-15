/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:36:09 by mwin              #+#    #+#             */
/*   Updated: 2026/02/14 02:23:13 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fd(int fd)
{
	if (fd >= 0 && fd != STDIN_FILENO && fd != STDOUT_FILENO
		&& fd != STDERR_FILENO)
		close(fd);
}

void	free_dupenvp(char ***dupenvp)
{
	int	i;

	if (!dupenvp || !*dupenvp)
		return ;
	i = 0;
	while ((*dupenvp)[i])
	{
		free((*dupenvp)[i]);
		i++;
	}
	free(*dupenvp);
	*dupenvp = NULL;
	free(dupenvp);
}

void	free_arr(char **cmds)
{
	int	i;

	i = 0;
	if (!cmds)
		return ;
	while (cmds[i])
	{
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

void	free_list(t_command *cmd)
{
	t_command	*next;

	while (cmd)
	{
		next = cmd->next_cmd;
		close_fd(cmd->infd_new);
		close_fd(cmd->outfd_new);
		if (cmd->arguments)
			free_arr(cmd->arguments);
		free(cmd->input_file);
		free(cmd->output_file);
		free(cmd->stderr_file);
		free_hd(cmd->heredocs);
		free(cmd);
		cmd = next;
	}
}

void	free_hd(t_hered *heredoc)
{
	t_hered	*next;

	while (heredoc)
	{
		next = heredoc->next;
		if (heredoc->temp_path)
			unlink(heredoc->temp_path);
		free(heredoc->temp_path);
		free(heredoc->symbol);
		free(heredoc);
		heredoc = next;
	}
}
