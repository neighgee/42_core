/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:41:03 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/16 15:13:45 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	write_echo(int fd, char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = write(fd, str, ft_strlen(str));
	if (i < len)
	{
		write(2, "minishell: echo: write error: No space left on device\n", 54);
		return (1);
	}
	return (0);
}

int	echo(char **args)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	if (!args || !*args)
		return (write_echo(1, "\n"));
	if (args[1] && ft_strncmp(args[1], "-n", 3) == 0)
		flag = 1;
	i = 1 + flag;
	j = 0;
	while (args[i] && !j)
	{
		j = write_echo(1, args[i]);
		i++;
		if (args[i] && !j)
			j = write_echo(1, " ");
	}
	if (j)
		return (1);
	if (!flag)
		write(1, "\n", 1);
	return (0);
}
