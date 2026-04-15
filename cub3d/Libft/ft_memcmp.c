/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:13:08 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/14 21:32:16 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*x1;
	unsigned char	*x2;

	x1 = (unsigned char *)s1;
	x2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*x1 != *x2)
			return (*x1 - *x2);
		x1++;
		x2++;
		n--;
	}
	return (0);
}

/* #include <stdio.h>
int main()
{
	char s1[9] = "12345678";
	char s2[11] = "1234567899";

	printf("diff s1,s2: %d\n",ft_memcmp(s1, s2, 2));
} */
