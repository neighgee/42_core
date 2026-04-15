/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:43:41 by mwin              #+#    #+#             */
/*   Updated: 2026/02/16 16:28:21 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unexpected_msg(char c)
{
	ft_putstr_fd("minishell: syntax error near token `", 2);
	if (c == '\n')
		ft_putstr_fd("newline", 2);
	else
		write(2, &c, 1);
	ft_putendl_fd("'", 2);
}

int	wrong_target(char *token)
{
	if (!token || !token[0])
		return (1);
	if (!ft_strncmp(token, "<<", 3) || !ft_strncmp(token, ">>", 3))
		return (1);
	if ((token[0] == '<' || token[0] == '>' || token[0] == '|'))
		return (1);
	return (0);
}

//Function checks for herestring & skips over redirection symbols
int	check_append_heredoc(char *token, int *checker)
{
	if (!token)
		return (0);
	if (token[0] == '\2')
		token++;
	if (token[0] == '\3' || token[0] == '\4')
		return (0);
	if (!ft_strncmp(token, "<<<", 3) || !ft_strncmp(token, ">>>", 3))
		return (-1);
	if (!ft_strncmp (token, "<<", 2))
		return (2);
	if (!ft_strncmp (token, ">>", 2))
	{
		*checker = 1;
		return (3);
	}
	if (token[0] == '<')
		return (1);
	if (token[0] == '>')
		return (4);
	return (0);
}

int	heredoc_inputs(t_command *cmd, int symbol, char *target)
{
	if (symbol == 2)
	{
		if (append_hd(cmd, target) < 0)
			return (-1);
		cmd->last_in_redrc = 1;
		return (1);
	}
	if (symbol == 1)
	{
		free(cmd->input_file);
		cmd->input_file = ft_strdup(target);
		if (!cmd->input_file)
			return (-1);
		cmd->last_in_redrc = 0;
		return (1);
	}
	return (0);
}

char	*redir_target(char **args, int i, int symbol, int	*skip)
{
	int		sym_len;
	int		len;
	char	*token;

	sym_len = 1;
	if (symbol == 2 || symbol == 3)
		sym_len = 2;
	token = args[i];
	if (!token)
		return (*skip = 2, NULL);
	if (token[0] == '\2')
		token++;
	len = (int)ft_strlen(token);
	if (len > sym_len)
		return (*skip = 1, token + sym_len);
	*skip = 2;
	if (!args[i + 1])
		return (NULL);
	return (args[i + 1]);
}
