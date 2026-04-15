/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:18:26 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/16 16:01:47 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_malloc_emp(void)
{
	char	*ptr;

	ptr = malloc(1);
	ptr[0] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;
	size_t			length;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_malloc_emp());
	while (i < start)
		i++;
	length = ft_strlen(s) - start;
	if (length < len)
		len = length;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	j = i;
	i = 0;
	while (s[i] && i < len)
	{
		ptr[i] = s[j + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* #include <stdio.h>

int main()
{
	printf("%s\n", ft_substr("Happy Day", 100, 5));
	return (0);
} */
