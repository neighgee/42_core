/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:48:01 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/16 15:59:06 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (*s != '\0')
		s++;
	if (c == '\0')
	{
		return ((char *) s);
	}
	else
	{
		s -= len;
		while (len >= 0)
		{
			if (s[len] == (char)c)
				return ((char *)&s[len]);
			len--;
		}
		return (NULL);
	}
}

/* #include <stdio.h>
#include <string.h>
int main()
{
	char c = 't';
	const char *s = "tripouille";

	printf("%s\n", ft_strrchr(s, c + 256));
	printf("%s\n", strrchr(s, c + 256));
} */
