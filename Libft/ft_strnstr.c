/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:44:16 by mwin              #+#    #+#             */
/*   Updated: 2025/05/22 13:07:18 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
// #include <stdio.h>
// #include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
	{
		return ((char *)big);
	}
	while ((i < len) && (big[i] != '\0'))
	{
		while (((i + j) < len) && little[j] != '\0' && big[i + j] == little[j])
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)&big[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char big1[100] = "Where is Sigangapore? It is in Singapwew Singapore 123";
// 	char *little1 = "Si";
// 	size_t len1 = 2;
// 	char big2[100] = "Where is Sigangapore? It is in Singapwew Singapore 123";
// 	char *little2 = "Si";
// 	size_t len2 = 2;

// 	printf("ft_strnstr - Substring: %s\n", ft_strnstr(big1, little1, len1));
// 	printf("strnstr - Substring: %s\n", strnstr(big2, little2, len2));
// }
