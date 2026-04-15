/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:13:39 by mwin              #+#    #+#             */
/*   Updated: 2025/05/23 12:26:03 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
// #include <stdio.h>
// #include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
// int	main(void)
// {
// 	size_t n1 = 40;
// 	char	*s1_1 = "Hello World";
// 	char	*s1_2 = "Hello";

// 	size_t n2 = 40;
// 	char	*s2_1 = "Hello World";
// 	char	*s2_2 = "Hello";

// 	printf("ft_strncmp result: %d\n",ft_strncmp(s1_1, s1_2, n1));
// 	printf("strncmp result: %d\n",strncmp(s2_1, s2_2, n2));
// }
