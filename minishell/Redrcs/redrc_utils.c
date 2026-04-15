/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redrc_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:59:37 by mwin              #+#    #+#             */
/*   Updated: 2026/02/16 15:38:57 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Function is to handle redirections
1. If input redirections exist, execute accordingly
2. If output redirections exist, execute accordingly
3. Restore default STDIN_FILENO and STDOUT_FILENO after
all executions are done.
4. Returns
	0 on success
	-1 on failure to indicate that no changes done */
int	handle_redrcs(t_command *cmd, int *org_in, int *org_out, int *org_err)
{
	int	in_fd;
	int	status;

	in_fd = -2;
	status = exec_input_redrc(cmd, org_in, &in_fd);
	if (status == -130)
		return (-130);
	if (status == -2)
		*org_in = -1;
	else if (status < 0)
		return (-1);
	if (exec_output_redrc(cmd, org_out, org_err, *org_in) < 0)
		return (-1);
	return (0);
}

void	freehd_child(t_hered *heredoc)
{
	t_hered	*next;

	while (heredoc)
	{
		next = heredoc->next;
		free(heredoc->temp_path);
		free(heredoc->symbol);
		free(heredoc);
		heredoc = next;
	}
}

void	close_fd_child(int fd)
{
	if (fd > 2)
		close (fd);
}

void	freelist_child(t_command *cmd)
{
	t_command	*next;

	while (cmd)
	{
		next = cmd->next_cmd;
		close_fd_child(cmd->infd_new);
		close_fd_child(cmd->outfd_new);
		if (cmd->arguments)
			free_arr(cmd->arguments);
		free(cmd->input_file);
		free(cmd->output_file);
		free(cmd->stderr_file);
		freehd_child(cmd->heredocs);
		free(cmd);
		cmd = next;
	}
}

void	hd_exit(int code, t_command *head, char ***envp)
{
	if (head)
		freelist_child(head);
	if (envp)
		free_dupenvp(envp);
	exit(code);
}
