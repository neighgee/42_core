/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:13:42 by mwin              #+#    #+#             */
/*   Updated: 2025/05/16 14:41:33 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;

	dest = s;
	while (n > 0)
	{
		*dest = (unsigned char)c;
		dest++;
		n--;
	}
	return (s);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	array1[10] = "12345";
// 	char	array2[10] = "12345";
// 	printf("Before ft_memset: %s\n", array1);
// 	printf("Before memset: %s\n", array2);
// 	ft_memset(array1, 255, 6);
// 	memset(array2, 255, 6);
// 	printf("After ft_memset: %s\n", array1);
// 	printf("After memset: %s\n", array2);
// }
