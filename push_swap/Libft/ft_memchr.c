/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:37:27 by mwin              #+#    #+#             */
/*   Updated: 2025/05/17 12:14:42 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pointer_s;
	unsigned char	*char_s;
	size_t			i;

	i = 0;
	char_s = (unsigned char *)s;
	while (i < n)
	{
		if (char_s[i] == (unsigned char) c)
		{
			pointer_s = &char_s[i];
			return (pointer_s);
		}
		i++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	char	str1[100] = "Where iS Sigangapore?";
// 	size_t	n1 = 25;
// 	char	*ptr1 = ft_memchr(str1, 'x', n1);
// 	char	str2[100] = "Where iS Sigangapore?";
// 	size_t	n2 = 25;
// 	char	*ptr2 = memchr(str2, 'x', n2);

// 	printf("ft_memchr - Matched character: %s\n", ptr1);
// 	printf("memchr - Matched character: %s\n", ptr2);
// }
