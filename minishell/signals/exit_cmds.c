/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:08:11 by mwin              #+#    #+#             */
/*   Updated: 2026/02/16 12:11:05 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	code(char *code)
{
	int	len;

	len = ft_strlen(code);
	if (len <= 8)
		return (ft_atoi(code) % 256);
	code += len - 8;
	return (ft_atoi(code) % 256);
}

int	str_is_num(const char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

// might have to change fd
int	exit_entry(char **cmds, int *exit_code, int *can_ex)
{
	int	len;

	len = ft_arrlen(cmds);
	if (len == 1)
	{
		write(1, "exit\n", 5);
		*can_ex = 1;
		return (*exit_code);
	}
	if (len >= 3 && str_is_num(cmds[1]))
		return (write(1, "exit\n", 5)
			, write(2, "minishell: exit: too many arguments\n", 36)
			, *exit_code = 1, 1);
	if (str_is_num(cmds[1]))
		return (write(1, "exit\n", 5), *exit_code = code(cmds[1])
			, *can_ex = 1, *exit_code);
	write(1, "exit\n", 5);
	write(2, "minishell: exit: ", 17);
	write(2, cmds[1], ft_strlen(cmds[1]));
	write(2, ": numeric argument required\n", 28);
	return (*exit_code = 2, *can_ex = 1, 2);
}

void	exit_cmd(char ***envp, int status, t_command *cmd)
{
	if (cmd)
		free_list(cmd);
	if (envp)
		free_dupenvp(envp);
	rl_clear_history();
	exit(status);
}

int	exit_status_only(char **cmds)
{
	int	len;
	int	i;

	len = ft_arrlen(cmds);
	i = 0;
	if (len == 1)
		return (0);
	while (cmds[1][i] && ft_isdigit(cmds[1][i]))
		i++;
	if (len >= 3 && cmds[1][i] == '\0')
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		return (1);
	}
	if (cmds[1][i] == '\0')
		return (code(cmds[1]));
	write(2, "minishell: exit: ", 17);
	write(2, cmds[1], ft_strlen(cmds[1]));
	write(2, ": numeric argument required\n", 28);
	return (2);
}
