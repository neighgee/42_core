/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kinda_like_libft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:34:24 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/10 21:34:27 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_arrlen(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}
