/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:16:03 by mwin              #+#    #+#             */
/*   Updated: 2026/02/18 18:36:19 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bad_path(char **args)
{
	char	*cmd;
	char	buffer[1024];
	int		j;
	int		k;

	if (!args || !args[0])
		return (1);
	cmd = args[0];
	j = 0;
	k = 0;
	while ("minishell: "[k] && j < 1023)
		buffer[j++] = "minishell: "[k++];
	k = 0;
	while (cmd[k] && j < 1023)
		buffer[j++] = cmd[k++];
	k = 0;
	while (": command not found\n"[k] && j < 1023)
		buffer[j++] = ": command not found\n"[k++];
	write(2, buffer, j);
	return (1);
}

static int	ign_empty_quotes(const char *s)
{
	int	sq;
	int	dq;

	sq = 0;
	dq = 0;
	while (s && *s)
	{
		if (!dq && *s == '\'')
			sq = !sq;
		else if (!sq && *s == '"')
			dq = !dq;
		s++;
	}
	if (sq || dq)
		return (0);
	return (1);
}

static int	blank(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (s[i] == '\0');
}

//Function splits input_string into a 2D array
//That 2D array is cmds
static char	**sep_pipes(char *s)
{
	int	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	real_sep_with_null(s, str_len, '|');
	return (split_on_null(s, str_len));
}

/*
1. checks if valid input + handles pipes & redirects
3. stores pipes & redirects into linkedlist of cmds
4. check against builtin cmds (execute if found, exit if not) */
int	check_input(char **input_string, char ***envp, int *exit_code, int *can_ex)
{
	char	**pipes;
	char	*temp;
	int		ret;

	pipes = NULL;
	ret = 0;
	if (!input_string || !*input_string || (*input_string)[0] == '\0'
		|| check_whitespace(*input_string) || !ign_empty_quotes(*input_string))
		return (free(input string), 0);
	add_history(*input_string);
	if (!pipe_syntax(*input_string))
	{
		write(2, "minishell: syntax error near unexpected token `|'\n", 50);
		return (*exit_code = 2, 0);
	}
	temp = add_spc_redrc(*input_string);
	if (!temp)
		return (*exit_code = 1, 0);
	free(*input_string);
	*input_string = temp;
	pipes = sep_pipes(*input_string);
	if (!pipes || !pipes[0] || blank(pipes[0]))
		return (free_arr(pipes), 0);
	ret = execute_cmds(pipes, envp, exit_code, can_ex);
	return (ret);
}
