/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:49:28 by mwin              #+#    #+#             */
/*   Updated: 2026/02/16 14:34:46 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	rdrcs_builtin(t_command *cmd_list, char ***envp)
{
	int	ret;

	ret = 0;
	if (cmd_list->arguments && cmd_list->arguments[0])
	{
		if (ft_strncmp(cmd_list->arguments[0], "exit", 5) == 0)
			ret = exit_status_only(cmd_list->arguments);
		else if (is_builtin(cmd_list->arguments[0]))
			ret = dw_builtin(cmd_list->arguments, envp);
		else
			ret = process1_5(0, 1, cmd_list->arguments, *envp);
	}
	return (ret);
}

static int	handle_fds(int prev_fd, t_command *curr, int p[2])
{
	int	dummy_in;
	int	dummy_out;
	int	dummy_err;

	if (prev_fd != STDIN_FILENO)
	{
		if (dup2(prev_fd, STDIN_FILENO) < 0)
			return (perror("dup2"), close(prev_fd), -1);
		close(prev_fd);
	}
	if (curr->next_cmd && p)
	{
		close(p[0]);
		if (dup2(p[1], STDOUT_FILENO) < 0)
			return (perror("dup2"), close(p[1]), -1);
		close(p[1]);
	}
	if (!curr->input_file && !curr->output_file
		&& !curr->heredocs && !curr->stderr_file)
		return (0);
	dummy_in = -1;
	dummy_out = -1;
	dummy_err = -1;
	return (close_fds(handle_redrcs(curr, &dummy_in, &dummy_out, &dummy_err)
			, dummy_in, dummy_out, dummy_err));
}

t_command	*parent_fn(int *prev_fd, t_command *curr, int p[2])
{
	if (*prev_fd != STDIN_FILENO)
		close(*prev_fd);
	if (curr->next_cmd)
	{
		close(p[1]);
		*prev_fd = p[0];
	}
	return (curr->next_cmd);
}

int	child_fn(int prev_fd, t_command *curr, int p[2], char ***envp)
{
	int	code;
	int	status;

	status = handle_fds(prev_fd, curr, p);
	if (status > 0)
		return (free_dupenvp(envp), status);
	code = rdrcs_builtin(curr, envp);
	free_dupenvp(envp);
	return (code);
}

int	no_pipes(t_command *curr, char ***envp)
{
	int	code;
	int	in;
	int	out;
	int	redrc_r;
	int	error;

	in = -1;
	out = -1;
	error = -1;
	if (curr->input_file || curr->output_file || curr->heredocs)
	{
		redrc_r = handle_redrcs(curr, &in, &out, &error);
		if (redrc_r == -130)
			return (restore_fd(in, curr->infd_new)
				, restore_fd(out, curr->outfd_new), 130);
		if (redrc_r == -1)
			return (restore_fd(in, curr->infd_new)
				, restore_fd(out, curr->outfd_new)
				, g_sigint && (code = 130), !g_sigint && (code = 1), code);
	}
	code = dw_builtin(curr->arguments, envp);
	return (restore_fd(in, curr->infd_new)
		, restore_fd(out, curr->outfd_new), code);
}
