/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redrc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:42:09 by mwin              #+#    #+#             */
/*   Updated: 2026/02/17 16:21:16 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_target(char **args, int i, int symbol, int *checker)
{
	char	*target;
	int		skip;

	skip = 0;
	target = redir_target(args, i, symbol, &skip);
	if (!target)
		return (*checker = -2, unexpected_msg('\n'), NULL);
	if (symbol == 2)
	{
		if (wrong_target(target))
			return (*checker = -2, unexpected_msg(target[0]), NULL);
		return (target);
	}
	if (ambig_redrc(target))
		return (*checker = -1,
			ft_putendl_fd("minishell: ambiguous redirect", 2), NULL);
	if (wrong_target(target))
		return (*checker = -2, unexpected_msg(target[0]), NULL);
	return (target);
}

static int	check_in_redirs(t_command *cmd, char *target,
	int symbol, int *checker)
{
	if (symbol == 1)
	{
		free(cmd->input_file);
		cmd->input_file = ft_strdup(target);
		if (!cmd->input_file)
			return (*checker = -1, -1);
	}
	else if (append_hd(cmd, target) < 0)
		return (*checker = -1, -1);
	return (*checker = 0, 1);
}

static int	check_out_redirs(t_command *cmd, char *target,
	int symbol, int *checker)
{
	int	append;

	append = (symbol == 3);
	if (handle_output_redrc(cmd, target, append, cmd->outfd_new) < 0)
		return (*checker = -1, -1);
	return (*checker = 0, 1);
}

static int	check_redirects(t_command *cmd, char **args, int *checker, int *i)
{
	int		symbol;
	int		fd;
	char	*target;

	symbol = parse_redir_symbol_fd(args, checker, i, &fd);
	if (symbol == 0)
		return (0);
	if (symbol < 0)
		return (bad_symbol(checker, args[*i]), -1);
	target = get_target(args, *i, symbol, checker);
	if (!target)
		return (-1);
	if (symbol >= 3 && fd < 0)
		fd = 1;
	which_redir(cmd, symbol, fd);
	if (symbol < 3)
	{
		if (check_in_redirs(cmd, target, symbol, checker) < 0)
			return (-1);
	}
	else if (check_out_redirs(cmd, target, symbol, checker) < 0)
		return (-1);
	*i += redir_skip(args[*i], symbol);
	return (1);
}

int	skip_redrcs(t_command *cmd, char **old, char **new, int *exit_code)
{
	int	i;
	int	j;
	int	checker;
	int	r;

	i = 0;
	j = 0;
	checker = 0;
	while (old[i])
	{
		r = check_redirects(cmd, old, &checker, &i);
		if (r == -1)
			return (*exit_code = 1, (checker == -2)
				&& (*exit_code = 2), 0);
		if (r == 1)
			continue ;
		if (old[i][0] == '\2')
			new[j++] = ft_strdup(old[i++] + 1);
		else
			new[j++] = ft_strdup(old[i++]);
		if (!new[j - 1])
			return (*exit_code = 1, 0);
	}
	return (new[j] = NULL, 1);
}
