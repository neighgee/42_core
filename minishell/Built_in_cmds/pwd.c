/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:41:24 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/17 13:27:23 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	write_pwd(char *pwd)
{
	int	j;

	j = ft_strlen(pwd);
	if (write(1, pwd, j) < j
		|| write(1, "\n", 1) < 1)
		return (write(2, "minishell: pwd: write error: \
No space left on device\n", 53), 1);
	return (0);
}

int	pwd(char **envp)
{
	char	*pwd;
	int		j;

	pwd = ft_getenv_custom(envp, "PWD");
	if (!pwd)
	{
		pwd = getcwd(NULL, 0);
		if (pwd)
		{
			j = write_pwd(pwd);
			free(pwd);
			return (j);
		}
	}
	j = write_pwd(pwd);
	return (j);
}
