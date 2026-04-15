/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:40:31 by mwin              #+#    #+#             */
/*   Updated: 2026/02/16 16:52:52 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//1 if whitespace, 0 if not whitespace
int	check_whitespace(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

//join string and append c to the end of string
char	*ft_strjoin_char(char *string, char c)
{
	char	temp[2];

	temp[0] = c;
	temp[1] = '\0';
	return (ft_strjoin(string, temp));
}

char	*substr_len(const char *s, int start, int len)
{
	char	*result;

	if (len < 0)
		return (NULL);
	result = malloc((size_t)len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s + start, (size_t)len);
	result[len] = '\0';
	return (result);
}

void	restore_ctrls(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\3')
			s[i] = '<';
		else if (s[i] == '\4')
			s[i] = '>';
		i++;
	}
}

int	which_redir(t_command *cmd, int symbol, int fd)
{
	if (symbol == 1 || symbol == 2)
	{
		if (fd < 0)
			fd = 0;
		cmd->infd_new = fd;
		cmd->last_in_redrc = (symbol == 2);
	}
	else if (symbol == 3 || symbol == 4)
	{
		if (fd < 0)
			fd = 1;
		cmd->outfd_new = fd;
	}
	return (0);
}
