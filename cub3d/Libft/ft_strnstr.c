/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:36:45 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/14 21:44:49 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;

	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (j + ft_strlen(little) <= len && big[j] != '\0')
	{
		i = 0;
		while (i < ft_strlen(little))
		{
			if (big[j + i] != little[i])
			{
				j++;
				break ;
			}
			i++;
			if (little[i] == '\0')
				return ((char *)&big[j]);
		}
	}
	return (NULL);
}

/* #include <stdio.h>
int main()
{
	char s1[9] = "12345678";
	char s2[30] = "112312345678 ";
	char *result = ft_strnstr(s1, s2, 209);

	printf("Result: %s\n",result);
} */
