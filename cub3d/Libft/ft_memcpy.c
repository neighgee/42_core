/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:49:40 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/20 16:21:24 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (s2 == NULL || n == 0)
		return ((void *)s1);
	d = (unsigned char *)s1;
	s = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)s1);
}
