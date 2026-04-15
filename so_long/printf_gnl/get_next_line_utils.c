/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:36:38 by mwin              #+#    #+#             */
/*   Updated: 2025/08/07 14:55:43 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_gnl.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pointer_s;
	char	char_c;
	int		i;

	i = 0;
	pointer_s = NULL;
	char_c = (char)c;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == char_c)
		{
			pointer_s = (char *) &s[i];
			return (pointer_s);
		}
		i++;
	}
	if (char_c == '\0')
		return ((char *) &s[i]);
	return (pointer_s);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;

	if (n == 0 || dest == src)
		return (dest);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	if (char_dest < char_src)
	{
		while (n--)
			*char_dest++ = *char_src++;
	}
	else
	{
		char_dest += n - 1;
		char_src += n -1;
		while (n--)
		{
			*char_dest-- = *char_src--;
		}
	}
	return (dest);
}

void	duplicate_strings(char *combined_string, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		combined_string[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		combined_string[i + j] = s2[j];
		j++;
	}
	combined_string[i + j] = '\0';
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*combined_string;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (NULL);
	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	combined_string = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!combined_string)
		return (NULL);
	duplicate_strings(combined_string, s1, s2);
	free(s1);
	return (combined_string);
}
