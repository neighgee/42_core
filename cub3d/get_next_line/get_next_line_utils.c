/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:29:58 by smariapp          #+#    #+#             */
/*   Updated: 2025/08/22 18:37:55 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcopy(char *src, char *dst, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

size_t	ft_strlen(const char *s)
{
	int	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++ ;
	return (len);
}

int	ft_strchrm(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_allocate_rem(char *rem)
{
	size_t	length;
	size_t	i;
	char	*ptr;

	if (rem == NULL || *rem == '\0')
		return (NULL);
	length = ft_strlen(rem);
	ptr = malloc(length + 1);
	i = 0;
	while (i < length)
	{
		ptr[i] = rem[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
