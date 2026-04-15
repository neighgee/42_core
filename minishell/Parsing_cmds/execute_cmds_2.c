/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:11:12 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/16 16:53:02 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	int	check;

	check = 0;
	if (cmd && (!ft_strncmp(cmd, "cd", 3)
			||!ft_strncmp(cmd, "echo", 5)
			||!ft_strncmp(cmd, "env", 4)
			||!ft_strncmp(cmd, "export", 7)
			||!ft_strncmp(cmd, "unset", 6)
			||!ft_strncmp(cmd, "pwd", 4)))
		check = 1;
	return (check);
}

int	exit_help(int last_pid)
{
	int	pid;
	int	status;
	int	last;

	last = 1;
	pid = wait(&status);
	while (pid > 0)
	{
		if (pid == last_pid)
		{
			if (WIFEXITED(status))
				last = WEXITSTATUS(status);
			else if (WIFSIGNALED (status))
				last = 128 + WTERMSIG(status);
		}
		pid = wait (&status);
	}
	return (last);
}

int	redir_only(t_command	*cmd_list, int *exit_code, int hd)
{
	int			in;
	int			out;
	int			err;

	if (hd == -130)
		return (*exit_code = 130, 130);
	if (hd < 0)
		return (*exit_code = 1, 1);
	if (!cmd_list->arguments || !cmd_list->arguments[0])
	{
		in = -1;
		out = -1;
		err = -1;
		if (handle_redrcs(cmd_list, &in, &out, &err) < 0)
		{
			restore_fd(in, cmd_list->infd_new);
			restore_fd(out, cmd_list->outfd_new);
			*exit_code = 1;
			return (1);
		}
		restore_fd(in, cmd_list->infd_new);
		restore_fd(out, cmd_list->outfd_new);
		return (*exit_code = 0, 0);
	}
	return (-2);
}

int	exit_or_builtin(t_command *cmd_list, int *exit_code, int *can_ex
	, char ***envp)
{
	int	ret;

	if (!cmd_list || cmd_list->next_cmd)
		return (-2);
	if (!cmd_list->arguments || !cmd_list->arguments[0])
		return (-2);
	if (ft_strncmp(cmd_list->arguments[0], "exit", 5) == 0)
		return (exit_entry(cmd_list->arguments, exit_code, can_ex));
	if (!is_builtin(cmd_list->arguments[0]))
		return (-2);
	ret = no_pipes(cmd_list, envp);
	*exit_code = ret;
	return (ret);
}

int	execute_cmds(char **pipes, char ***envp, int *ec, int *can_ex)
{
	t_command	*cmd_list;
	int			last_pid;
	int			hd;
	int			status;

	cmd_list = store_cmds(pipes, envp, ec);
	if (!cmd_list)
		return (*ec);
	if ((!cmd_list->arguments || !cmd_list->arguments[0])
		&& !cmd_list->heredocs && !cmd_list->input_file
		&& !cmd_list->output_file)
		return (free_list(cmd_list), *ec);
	hd = many_hd(cmd_list, envp);
	status = redir_only(cmd_list, ec, hd);
	if (status != -2)
		return (free_list(cmd_list), status);
	status = exit_or_builtin(cmd_list, ec, can_ex, envp);
	if (status != -2)
		return (free_list(cmd_list), status);
	initialise_exec_signals();
	last_pid = create_pipeline(cmd_list, envp);
	if (last_pid == -1)
		return (initialise_signals(), free_list(cmd_list), *ec = 1, 1);
	*ec = exit_help(last_pid);
	return (initialise_signals(), free_list(cmd_list), *ec);
}
