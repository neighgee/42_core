/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_hd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:36:36 by mwin              #+#    #+#             */
/*   Updated: 2026/02/17 14:55:45 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cleanup_hd(t_hered *heredoc)
{
	if (heredoc && heredoc->temp_path)
	{
		unlink(heredoc->temp_path);
		free(heredoc->temp_path);
		heredoc->temp_path = NULL;
	}
}

static int	sig_exit_c(int status, t_hered *heredoc)
{
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		cleanup_hd(heredoc);
		return (-130);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		cleanup_hd(heredoc);
		return (-130);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	{
		cleanup_hd(heredoc);
		return (-1);
	}
	return (0);
}

int	one_hd(t_hered *heredoc, char ***envp, t_command *head)
{
	pid_t	pid;
	int		status;
	int		fd;
	void	(*old_int)(int);
	void	(*old_quit)(int);

	if (!heredoc || !heredoc->symbol)
		return (-1);
	fd = open_hds(&heredoc->temp_path);
	if (fd < 0)
		return (-1);
	old_int = signal(SIGINT, SIG_IGN);
	old_quit = signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), close(fd)
			, signal(SIGINT, old_int), signal(SIGQUIT, old_quit)
			, cleanup_hd(heredoc), -1);
	if (pid == 0)
		heredoc_child(heredoc, fd, envp, head);
	close(fd);
	waitpid(pid, &status, 0);
	signal(SIGINT, old_int);
	signal(SIGQUIT, old_quit);
	return (sig_exit_c(status, heredoc));
}

int	many_hd(t_command *cmds, char ***envp)
{
	t_command	*curr;
	t_hered		*heredoc;
	int			exit_c;

	curr = cmds;
	while (curr)
	{
		heredoc = curr->heredocs;
		while (heredoc)
		{
			exit_c = one_hd(heredoc, envp, cmds);
			if (exit_c != 0)
				return (exit_c);
			heredoc = heredoc->next;
		}
		curr = curr->next_cmd;
	}
	return (0);
}
