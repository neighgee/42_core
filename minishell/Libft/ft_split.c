/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:13:22 by mwin              #+#    #+#             */
/*   Updated: 2025/05/22 13:38:48 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*malloc_sep_word(const char *s, char c)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	i = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_result(char **result, int i)
{
	while (i > 0)
	{
		i--;
		free (result[i]);
	}
	free (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	i = 0;
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = malloc_sep_word(s, c);
			if (!result[i])
				return (free_result(result, i), NULL);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	result[i] = NULL;
	return (result);
}

// #include <stdio.h>

// int main(void)
// {
// 	char str[] = "Hello-World-This-is-a-test";
// 	char sep = '-';
// 	char **result = ft_split(str, sep);

// 	if (result)
// 	{
// 		for (int i = 0; result[i]; i++)
// 		{
// 			printf("Word %d: %s\n", i, result[i]);
// 			free(result[i]);
// 		}
// 		free(result);
// 	}
// 	return 0;
// }
