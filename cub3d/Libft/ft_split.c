/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:54:34 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/20 17:16:07 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	inw;
	int	count;
	int	i;

	inw = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (inw && s[i] == c)
		{
			inw = 0;
		}
		else if (!inw && s[i] != c)
		{
			count += 1;
			inw = 1;
		}
		i++;
	}
	return (count);
}

static char	*ft_strchr_m(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	return ((char *)s);
}

int	ft_malloc_and_free(char	**arr, int i, char const *s, char *add)
{
	arr[i] = malloc((add - s + 1) * sizeof(char));
	if (!arr[i])
	{
		while (--i >= 0)
			free(arr[i]);
		free(arr);
		return (0);
	}
	arr[i][add - s] = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		div;
	char	*add;
	int		i;
	int		j;

	div = ft_word_count(s, c);
	i = 0;
	arr = malloc((div + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s && i < div)
	{
		while (*s == c)
			s++;
		add = ft_strchr_m(s, c);
		if (!ft_malloc_and_free(arr, i, s, add))
			return (NULL);
		j = 0;
		while (s < add && *s)
			arr[i][j++] = *s++;
		i++;
	}
	arr[div] = NULL;
	return (arr);
}

/* #include <stdio.h>
int main()
{
	char *str = " as d    f     ";
	char **arr = ft_split(str, ' ');
	int test = ft_word_count(str, ' ');
	int i;
	i = 0;
 	while (arr[i] != NULL)
	{
	   	printf("%s\n", arr[i]);	
		i++;
	}
printf("test: %d\n", test);
} */
