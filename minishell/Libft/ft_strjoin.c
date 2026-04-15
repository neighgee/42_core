/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:41:58 by mwin              #+#    #+#             */
/*   Updated: 2025/10/08 21:54:02 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
// #include <stddef.h>
// #include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*combinedstring;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	combinedstring = (char *)malloc((len1 + len2 + 1) * sizeof (char));
	if (combinedstring == NULL)
		return (NULL);
	while (i < len1)
		combinedstring[i++] = *s1++;
	while (j < len2)
		combinedstring[i + j++] = *s2++;
	combinedstring[i + j] = '\0';
	return (combinedstring);
}

// int	main(void)
// {
// 	const char	*strs = {"apple"};
// 	const char	*sep = "_";
// 	char		*result;

// 	result = ft_strjoin(strs, sep);
// 	if (*result != '\0')
// 	{
// 		printf("%s\n", result);
// 		free(result);
// 	}
// }
