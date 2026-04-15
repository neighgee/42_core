/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:10:53 by mwin              #+#    #+#             */
/*   Updated: 2025/05/22 12:47:20 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*char_s1;
	const unsigned char	*char_s2;
	size_t				i;

	char_s1 = (const unsigned char *)s1;
	char_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (char_s1[i] != char_s2[i])
		{
			return (char_s1[i] - char_s2[i]);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	size_t n1 = 1;
// 	char	*s1_1 = "Hello World";
// 	char	*s1_2 = "Hello";

// 	size_t n2 = 1;
// 	char	*s2_1 = "Hello World";
// 	char	*s2_2 = "Hello";

// 	printf("ft_memcmp result: %d\n",ft_memcmp(s1_1, s1_2, n1));
// 	printf("memcmp result: %d\n",memcmp (s2_1, s2_2, n2));
// }
