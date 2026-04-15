/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:16:19 by mwin              #+#    #+#             */
/*   Updated: 2025/05/23 12:24:12 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
// #include <stdio.h>
// #include <string.h>

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	new_s = (char *)malloc((s_len + 1) * sizeof(char));
	if (new_s == NULL)
		return (NULL);
	while (i < s_len)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

// int main(void)
// {
// 	char	*s = "Hello";
// 	char	*new_s1 = ft_strdup(s);
// 	char	*new_s2 = strdup(s);
// 	printf("Original: %s\n", s);
// 	printf("Duplicated: %s\n", new_s1);
// 	printf("Duplicated: %s\n", new_s2);
// 	free(new_s1);
// 	free(new_s2);
// }
