/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_no_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:31:41 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/18 18:37:25 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr_m(char *a, char c)
{
	char	*ret;

	ret = ft_strchr(a, c);
	if (ret)
		return (ret);
	return (a + ft_strlen(a));
}

static int	key_cmp(char *a, char *b)
{
	int	len_a;
	int	len_b;
	int	min;
	int	ret;

	len_a = ft_strchr_m(a, '=') - a;
	len_b = ft_strchr_m(b, '=') - b;
	min = len_a;
	if (len_b < min)
		min = len_b;
	ret = ft_strncmp(a, b, min);
	if (ret != 0)
		return (ret);
	if (len_a == len_b)
		return (0);
	if (len_a < len_b)
		return (-1);
	return (1);
}

static void	sort_env_keys(char **arr)
{
	int		i;
	int		swapped;
	char	*tmp;

	if (!arr)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (arr[i] && arr[i + 1])
		{
			if (key_cmp(arr[i], arr[i + 1]) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

int	no_arg_write(char ***envp, int fd)
{
	int		n;
	int		i;
	char	*equal;

	i = 0;
	n = 0;
	while ((*envp)[i])
	{
		n = write(fd, "declare -x ", 11);
		if (n < 0)
			return (1);
		equal = ft_strchr((*envp)[i], '=');
		if (equal == NULL)
			n = write(fd, (*envp)[i], ft_strlen((*envp)[i]));
		else
		{
			n = write(fd, (*envp)[i], equal - (*envp)[i] + 1);
			n = write(fd, "\"", 1);
			n = write(fd, equal + 1, ft_strlen(equal) - 1);
			n = write(fd, "\"", 1);
		}
		n = write(fd, "\n", 1);
		i++;
	}
	return (n < 0);
}

int	export_no_arg(char ***envp, int fd)
{
	int		count;
	char	**sorted;
	int		i;
	int		n;

	if (!envp || !*envp)
		return (0);
	count = 0;
	while (*envp && (*envp)[count])
		count++;
	sorted = (char **)malloc(sizeof(char *) * (count + 1));
	if (!sorted)
		return (1);
	i = 0;
	while (i < count)
	{
		sorted[i] = (*envp)[i];
		i++;
	}
	sorted[i] = NULL;
	sort_env_keys(sorted);
	n = no_arg_write(&sorted, fd);
	return (free(sorted), n);
}
