/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:14:43 by smariapp          #+#    #+#             */
/*   Updated: 2026/04/09 14:59:41 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_arr(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*arr != NULL)
	{
		free(*arr);
		arr++;
	}
	free(tmp);
}

void	free_list(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free(list->content);
		free(list);
		list = next;
	}
}

void	free_params(t_params *par)
{
	if (!par)
		return ;
	if (par->n)
		free(par->n);
	if (par->s)
		free(par->s);
	if (par->e)
		free(par->e);
	if (par->w)
		free(par->w);
	if (par->fd > 0)
		close(par->fd);
	if (par->maplist)
		free_list(par->maplist);
	if (par->map)
		free_arr(par->map);
	free(par);
}
