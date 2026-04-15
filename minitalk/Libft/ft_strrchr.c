/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:16:35 by mwin              #+#    #+#             */
/*   Updated: 2025/05/23 12:26:22 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
// #include <string.h>
// #include <stdio.h>

char	*ft_strrchr(const char *s, int c)
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
		}
		i++;
	}
	if (char_c == '\0')
		return ((char *) &s[i]);
	return (pointer_s);
}
// int	main(void)
// {
// 	char	str1[100] = "Where is sigangapore?";
// 	int		c1 = 's';
// 	char	str2[100] = "Where is sigangapore?";
// 	int		c2 = 's';
// 	printf("ft_strrchr - Matched character: %s\n", ft_strrchr(str1, c1));
// 	printf("strrchr - Matched character: %s\n", strrchr(str2, c2));
// }
