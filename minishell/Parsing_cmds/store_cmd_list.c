/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_cmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:13:38 by mwin              #+#    #+#             */
/*   Updated: 2026/02/17 15:11:08 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_segments(char *s, int str_len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < str_len)
	{
		while (i < str_len && (s[i] == '\0' || s[i] == ' '))
			i++;
		if (i >= str_len)
			break ;
		count++;
		while (i < str_len && s[i] != '\0')
			i++;
	}
	return (count);
}

void	real_sep_with_null(char *s, int str_len, char sep)
{
	int		i;
	int		sq;
	int		dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (i < str_len)
	{
		if (!dq && s[i] == '\'')
			sq = !sq;
		else if (!sq && s[i] == '"')
			dq = !dq;
		else if (s[i] == sep && !sq && !dq)
			s[i] = '\0';
		i++;
	}
}

char	**split_on_null(char *s, int str_len)
{
	char	**array;
	int		i;
	int		j;
	int		start;

	array = malloc(sizeof(char *) * (count_segments(s, str_len) + 1));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (i < str_len)
	{
		while (i < str_len && (s[i] == '\0' || s[i] == ' '))
			i++;
		if (i >= str_len)
			break ;
		start = i;
		while (i < str_len && s[i] != '\0')
			i++;
		array[j++] = substr_len(s, start, i - start);
		if (!array[j - 1])
			return (array[j - 1] = NULL, free_arr(array), NULL);
	}
	array[j] = NULL;
	return (free(s), array);
}

static t_command	*initialise_cmds(char *pipes_unsep, char ***envp,
	int *exit_code)
{
	t_command	*cmd;
	int			i;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	ft_bzero(cmd, sizeof(t_command));
	cmd->hd_envp = *envp;
	cmd->hd_status = *exit_code;
	cmd->arguments = check_remove_quotes(pipes_unsep, envp, exit_code);
	if (!cmd->arguments)
		return (free(cmd), NULL);
	if (!store_symbols(cmd, exit_code))
		return (free_list(cmd), NULL);
	i = 0;
	while (cmd->arguments && cmd->arguments[i])
		restore_ctrls(cmd->arguments[i++]);
	if (!cmd->arguments[0] && !cmd->heredocs
		&& !cmd->input_file && !cmd->output_file)
		return (free_list(cmd), NULL);
	if (cmd->arguments[0])
		cmd->first_arg = cmd->arguments[0];
	return (cmd);
}

t_command	*store_cmds(char **pipes, char ***envp, int *exit_code)
{
	t_command	*top;
	t_command	*current;
	t_command	*next;
	int			i;

	top = NULL;
	current = NULL;
	i = 0;
	while (pipes[i])
	{
		next = initialise_cmds(pipes[i], envp, exit_code);
		if (!next)
			return (free_arr(pipes), NULL);
		if (!top)
			top = next;
		else
			current->next_cmd = next;
		current = next;
		i++;
	}
	return (free_arr(pipes), top);
}
