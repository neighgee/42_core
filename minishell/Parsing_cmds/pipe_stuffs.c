/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_stuffs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:28:44 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/16 14:27:51 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	empty_pipe(int *i, int *string, const char *s, int sq_dq[2])
{
	int	sq;
	int	dq;

	sq = sq_dq[0];
	dq = sq_dq[1];
	if (!sq && !dq && s[*i] == '|')
	{
		if (!*string)
			return (1);
		*string = 0;
		(*i)++;
		while (s[*i] && is_space(s[*i]))
			(*i)++;
		if (!s[*i] || s[*i] == '|')
			return (1);
	}
	return (0);
}

int	pipe_syntax(const char *s)
{
	int	i;
	int	sq_dq[2];
	int	string;

	i = 0;
	sq_dq[0] = 0;
	sq_dq[1] = 0;
	string = 0;
	while (s && s[i])
	{
		if (!sq_dq[1] && s[i] == '\'')
			sq_dq[0] = !sq_dq[0];
		else if (!sq_dq[0] && s[i] == '"')
			sq_dq[1] = !sq_dq[1];
		if (empty_pipe(&i, &string, s, sq_dq))
			return (0);
		if (!sq_dq[0] && !sq_dq[1] && !is_space(s[i]) && s[i] != '|')
			string = 1;
		i++;
	}
	return (1);
}

static void	set_params(int *prev_fd, int *pid, int p[2])
{
	*prev_fd = STDIN_FILENO;
	*pid = -1;
	p[0] = -1;
	p[1] = -1;
}

int	pidzero(t_command *head, t_command *curr, char ***envp, int fds[3])
{
	int	p[2];
	int	code;

	p[0] = fds[1];
	p[1] = fds[2];
	initialise_child_signals();
	code = child_fn(fds[0], curr, p, envp);
	free_list(head);
	close_stdfd();
	return (code);
}

int	create_pipeline(t_command *cmd_list, char ***envp)
{
	int			p[2];
	int			pid;
	int			prev_fd;
	t_command	*curr;
	int			fds[3];

	set_params(&prev_fd, &pid, p);
	curr = cmd_list;
	while (curr)
	{
		if (curr->next_cmd && pipe(p) == -1)
			return (perror("pipe"), -1);
		pid = fork();
		if (pid == -1)
			return (perror("fork"), -1);
		if (pid == 0)
		{
			fds[0] = prev_fd;
			fds[1] = p[0];
			fds[2] = p[1];
			exit(pidzero(cmd_list, curr, envp, fds));
		}
		curr = parent_fn(&prev_fd, curr, p);
	}
	return (pid);
}
