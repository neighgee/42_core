/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:41:18 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/17 10:36:27 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_inv(char *new, char ***envp, int fd)
{
	int	ret;

	ret = check_valid(new, fd);
	if (ret == 0 || ret == 1)
		return (ret);
	if (ft_getenv_custom(*envp, new) == NULL)
		export_var_add(envp, new);
	return (2);
}

int	indiv_export(char ***envp, char *new)
{
	int		i;
	int		j;
	char	*var;

	j = handle_inv(new, envp, 2);
	if (j >= 1)
		return (j % 2);
	i = 0;
	while (new[i] != '=')
		i++;
	var = malloc(i + 1);
	if (!var)
		return (0);
	j = -1;
	while (j++ < i - 1)
		var[j] = new[j];
	var[j] = '\0';
	if (ft_getenv_custom(*envp, var) != NULL)
		export_var_in_env(envp, new, var);
	else
		export_var_add(envp, new);
	return (free(var), 0);
}

int	write_no_arg(char *equal, char ***envp, int i, int fd)
{
	if (write(fd, (*envp)[i], equal - (*envp)[i] + 1) < (equal - (*envp)[i] + 1)
	|| write(fd, "\"", 1) < 1
	|| write(fd, equal + 1, ft_strlen(equal) - 1) < (long)(ft_strlen(equal) - 1)
	|| write(fd, "\"", 1) < 1)
	{
		write(2,
			"minishell: export: write error: No space left on device\n", 56);
		return (1);
	}
	return (0);
}

int	export(char ***envp, char **args, int fd)
{
	int	n;
	int	i;
	int	ret;

	n = ft_arrlen(args);
	i = 1;
	ret = 0;
	if (n == 1)
		return (export_no_arg(envp, fd));
	else
	{
		while (args[i])
		{
			n = indiv_export(envp, args[i]);
			if (ret != 1)
				ret = n;
			i++;
		}
	}
	return (ret);
}
