/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_remove_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:20:35 by mwin              #+#    #+#             */
/*   Updated: 2026/02/17 20:25:24 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static char	*copy_cmds(const char **string, char ***envp,
// 	int *exit_code, int *quoted)
// {
// 	const char	*start;
// 	const char	*end;
// 	char		*cmd;

// 	start = *string;
// 	end = skip_quotes(*string, quoted);
// 	cmd = copy_and_remove_quotes(envp, start, end, exit_code);
// 	if (!cmd)
// 		return (NULL);
// 	cmd = hd_quoted(cmd, *quoted);
// 	if (!cmd)
// 		return (NULL);
// 	*string = end;
// 	return (cmd);
// }

static char	**malloc_cmd(const char *input_string, int *quoted)
{
	char		**cmds;
	int			count;

	count = count_cmds(input_string, quoted);
	cmds = malloc(sizeof(char *) * (count + 1));
	if (!cmds)
		return (NULL);
	return (cmds);
}

static int	is_prev_heredoc(char **cmds, int i)
{
	char	*prev;

	if (i <= 0)
		return (0);
	prev = cmds[i - 1];
	if (!prev)
		return (0);
	if (prev[0] == '\2')
		prev++;
	if (ft_strncmp(prev, "<<", 3) == 0)
		return (1);
	return (0);
}

static int	fill_cmd(char **cmds, const char *input_string,
	char ***envp, int *exit_code)
{
	t_fillc	fc;

	fc.ptr = input_string;
	fc.envp = envp;
	fc.exit_code = exit_code;
	fc.i = 0;
	fc.heredoc_next = 0;
	while (*(fc.ptr))
	{
		skip_spc(&fc);
		if (!*(fc.ptr))
			break ;
		if (copy_one_token(&fc, cmds) < 0)
			return (-1);
		if (empty_tok(cmds[fc.i]) && !fc.quoted && !is_prev_heredoc(cmds, fc.i))
			drop_tok(&fc, cmds);
		else
			eat_tok(&fc, cmds);
	}
	cmds[fc.i] = NULL;
	return (0);
}

char	**check_remove_quotes(const char *input_string
	, char ***envp, int *exit_code)
{
	char	**cmds;
	int		quoted;

	cmds = malloc_cmd(input_string, &quoted);
	if (!cmds)
		return (NULL);
	if (fill_cmd(cmds, input_string, envp, exit_code) < 0)
	{
		free_arr(cmds);
		return (NULL);
	}
	return (cmds);
}
