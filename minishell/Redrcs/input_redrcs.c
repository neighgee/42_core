/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redrcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:16:51 by mwin              #+#    #+#             */
/*   Updated: 2026/02/18 18:37:19 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	restore_fd(int org_fd, int target_fd)
{
	if (org_fd == -1)
		return ;
	if (org_fd == target_fd)
		return ;
	if (dup2(org_fd, target_fd) < 0)
		perror("dup2");
	if (org_fd > 2)
		close(org_fd);
}

/*
Function checks if heredoc symbol/input redirect
1. If heredoc, it setups heredoc first,
	before changing the STDIN_FILENO
2. If input redirect, it opens input_file,
	saves the fd of input_file
3. Return fd of input_file on success
4. Return -1 or -2 on failure
	-1 means cannot open fd, fd now set to /dev/null
		this is to help with multiple pipes
	-2 means no input redirections or heredoc,
		aka, does nothing */
static int	open_input_fd(t_command *cmd)
{
	int		fd;
	t_hered	*heredoc;

	if (cmd->last_in_redrc)
	{
		heredoc = last_hd(cmd->heredocs);
		if (heredoc && heredoc->temp_path)
		{
			fd = open(heredoc->temp_path, O_RDONLY);
			if (fd < 0)
				return (perror(heredoc->temp_path), -1);
			unlink(heredoc->temp_path);
			free(heredoc->temp_path);
			return (heredoc->temp_path = NULL, fd);
		}
	}
	if (!cmd->input_file)
		return (-2);
	fd = open(cmd->input_file, O_RDONLY);
	if (fd < 0)
		return (perror(cmd->input_file), -1);
	return (fd);
}

/* Functions saves the default STDIN_FILENO
This is so that it can be reused to
restore after command has been run */
int	save_fd(int target_fd, int *org)
{
	*org = dup(target_fd);
	if (*org < 0)
	{
		perror("dup");
		return (-1);
	}
	return (0);
}

/*
STDIN_FILENO by default is the terminal
dup2 uses fd specified by user - 2nd argument

It changes the fd of the 2nd argument to the 1st argument

Function changes the fd of current fd so that it
1. points to input_file aka file specified by user
2. points to heredoc aka take inputs from terminal,
	until certain symbol is given */
int	redirect_fd(int opened_fd, int target_fd)
{
	if (dup2(opened_fd, target_fd) < 0)
	{
		perror("dup2");
		if (opened_fd > 2)
			close(opened_fd);
		return (-1);
	}
	if (opened_fd != target_fd)
		close(opened_fd);
	return (0);
}

/*
Function checks if inputfile (<) or (<<)

1. Check if input_file can be opened in open_input_fd
	If can be opened, saves fd of input_file
	If no input file, open_input_fd returns -2
		and does nothing
	If opening input_file failed, return -1,
		this is to indicate 0 change to stdin_file
2. Duplicates default fd for standard inputs using,
	save_stdin
		-> stdin_file now points
			to default fd for standard inputs
	This is to help with restoring stdin_file later
3. Change where STDIN_FILENO aka the fd for standard inputs
	using redirect_stdin function
	STDIN_FILENO changed to heredoc pipe or fd of input_file
4. Returns:
	0 on success,
	-1 for failure, aka STDIN_FILENO did not change */
int	exec_input_redrc(t_command *cmd, int *org_fd, int *in_fd)
{
	int	fd;
	int	target;

	*org_fd = -1;
	*in_fd = -2;
	fd = open_input_fd(cmd);
	if (fd == -2)
		return (-2);
	if (fd == -130)
		return (-130);
	if (fd < 0 && fd != -130)
		return (-1);
	target = cmd->infd_new;
	if (save_fd(target, org_fd) < 0)
		return (close(fd), -1);
	if (redirect_fd(fd, target) < 0)
		return (restore_fd(*org_fd, target), *org_fd = -1, -1);
	*in_fd = target;
	return (0);
}
