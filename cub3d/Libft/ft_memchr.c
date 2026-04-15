/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:07:10 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/14 21:31:45 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (n > 0)
	{
		ptr = (const unsigned char *)s;
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		s++;
		n--;
	}
	return (NULL);
}

/* #include <stdio.h>

int main()
{
	char s[20] = "baa baa black sheep";
	char  c = 'a';
	void *result = ft_memchr(s, c, 30);
	if (result != NULL)
		printf("found byte: %c\n", *(unsigned char *)result);
	else
		printf("not found\n");
} */
