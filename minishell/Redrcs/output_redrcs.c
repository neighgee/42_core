/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redrcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:38:06 by mwin              #+#    #+#             */
/*   Updated: 2026/02/17 15:28:09 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 0644: Owner (6) - can read + write, Group(4) - can read, Others(4) - can read
Return -2 for no redirection
Return -1 for ERROR */
static int	open_outfile(char *file, int append)
{
	int	fd;

	if (append)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	return (fd);
}

static int	exec_stderr_redrc(t_command *cmd, int org_in, int *org_err)
{
	int	fd;

	*org_err = -1;
	if (!cmd->stderr_file)
		return (0);
	fd = open_outfile(cmd->stderr_file, cmd->stderr_append);
	if (fd < 0)
	{
		if (org_in != -1)
			restore_fd(org_in, cmd->infd_new);
		return (-1);
	}
	if (save_fd(2, org_err) < 0)
		return (close(fd), -1);
	if (redirect_fd(fd, 2) < 0)
		return (close(fd), restore_fd(*org_err, 2), *org_err = -1, -1);
	close(fd);
	return (0);
}

static int	exec_stdout_redrc(t_command *cmd, int org_in, int *org_out)
{
	int	fd;

	*org_out = -1;
	if (!cmd->output_file)
		return (0);
	fd = open_outfile(cmd->output_file, cmd->check_changes);
	if (fd < 0)
	{
		if (org_in != -1)
			restore_fd(org_in, cmd->infd_new);
		return (-1);
	}
	if (save_fd(1, org_out) < 0)
		return (close(fd), -1);
	if (redirect_fd(fd, 1) < 0)
		return (restore_fd(*org_out, 1), *org_out = -1, -1);
	return (0);
}

//Function does the below:
//1. Opens the output file using correct flags + permission
	//">>" then add appends flag
	//">" then add create flag to overwrite/create
	//permission: owner read+write, others read only
//2. Duplicates the default stdout using save_stdout
	//STDOUT_FILENO now still points to
	//default stdout, aka the terminal
//3. Change where STDOUT_FILENO aka the fd for standard outputs
	//using redirect_stdout function
	//STDOUT_FILENO changed to fd of output_file
//4. Returns:
	//0 on success, or no output_file
	//restore_fd if output_file cannot be, opened or saved
		//closes the fd of changed STDIN_FILENO in case it changed
		//restores the STDIN_FILENO to default
	//-1 for failure
		//This means STDOUT_FILENO did not change
int	exec_output_redrc(t_command *cmd, int *org_out, int *org_err, int org_in)
{
	*org_out = -1;
	*org_err = -1;
	if (exec_stderr_redrc(cmd, org_in, org_err) < 0)
		return (-1);
	if (exec_stdout_redrc(cmd, org_in, org_out) < 0)
	{
		if (*org_err != -1)
			restore_fd(*org_err, 2);
		*org_err = -1;
		return (-1);
	}
	return (0);
}

void	heredoc_child(t_hered *heredoc, int fd, char ***envp, t_command *head)
{
	int	code;

	g_sigint = 0;
	initialise_child_signals();
	signal(SIGINT, heredoc_sigint);
	signal(SIGQUIT, SIG_IGN);
	code = hd_loop(heredoc, fd, envp, head->hd_status);
	if (fd > 2)
		close(fd);
	if (code == 130)
		hd_exit(130, head, envp);
	if (code != 0)
		hd_exit(1, head, envp);
	hd_exit(0, head, envp);
}
