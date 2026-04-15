/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:01:42 by smariapp          #+#    #+#             */
/*   Updated: 2026/02/16 12:47:23 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_extra_fds(void)
{
	int	fd;

	fd = 3;
	while (fd < 1024)
	{
		close(fd);
		fd++;
	}
}

void	close_stdfd(void)
{
	close(0);
	close(1);
	close(2);
}

void	close_once(int *fd)
{
	if (*fd > 2)
	{
		close(*fd);
		*fd = -1;
	}
}
