/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:51:10 by mwin              #+#    #+#             */
/*   Updated: 2025/05/17 18:17:09 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*pointer_s;
	char	char_c;
	int		i;

	i = 0;
	pointer_s = NULL;
	char_c = (char)c;
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
// int	main(void)
// {
// 	char	str1[100] = "Where is Sigangapore?";
// 	int		c1 = 'S';
// 	char	str2[100] = "Where is Sigangapore?";
// 	int		c2 = 'S';
// 	printf("ft_strchr - Matched character: %s\n", ft_strchr(str1, c1));
// 	printf("strchr - Matched character: %s\n", strchr(str2, c2));
// }
