/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:46:29 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/17 15:26:49 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strfound(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_ix(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen(s1) - 1;
	if (end < 0)
		end = 0;
	while (end >= 0 && s1[end] && ft_strfound(set, s1[end]) == 1)
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		arr;
	int		i;

	while (*s1 != '\0' && ft_strfound(set, *s1) == 1)
		s1++;
	arr = ft_ix(s1, set);
	i = 0;
	if (*s1 == '\0')
		ptr = (char *)malloc(1);
	else
		ptr = (char *)malloc(arr + 2);
	if (!ptr)
		return (NULL);
	while (i <= arr && *s1 != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/* 
#include <stdio.h>
int main()
{
	printf("%s\n", ft_strtrim("  * * br   * nsjd     *", " *"));
	printf("%s\n", ft_strtrim("  * *      *", " *"));
	printf("%s\n", ft_strtrim("bedjkjddk", " *"));
	printf("%s\n", ft_strtrim("a  * *      *a", " *"));
	printf("%s\n", ft_strtrim("2    wrgreg  ht s", ""));
	printf("%s\n", ft_strtrim("", "abcd"));
	printf("%s\n", ft_strtrim("aaaafaaaa", "abcd"));

} */