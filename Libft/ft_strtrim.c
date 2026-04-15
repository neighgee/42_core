/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:41:37 by mwin              #+#    #+#             */
/*   Updated: 2025/05/23 12:26:54 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
// #include <string.h>
// #include <stdio.h>

static int	is_charset(char c, const char *set)
{
	size_t	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*new_s1;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (s1[start] && is_charset(s1[start], set))
		start++;
	while (end > start && is_charset(s1[end - 1], set))
		end--;
	new_s1 = (char *)malloc(sizeof(char) * (end - start + 1));
	if (new_s1 == NULL)
		return (NULL);
	while (start < end)
	{
		new_s1[i] = s1[start];
		i++;
		start++;
	}
	new_s1[i] = '\0';
	return (new_s1);
}
//
// int main()
// {
// 	char s1[] = "Hello, World! This is a test.";
// 	char set[] = " ,.!";
// 	char *result = ft_strtrim(s1, set);

// 	if (result)
// 	{
// 		printf ("original string: %s\n", s1);
// 		printf ("set: %s\n", set);
// 		printf("new word: %s\n", result);
// 		free(result);  // Free the array of strings
// 	}
// 	return 0;
// }
