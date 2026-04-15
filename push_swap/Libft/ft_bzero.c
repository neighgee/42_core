/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:14:13 by mwin              #+#    #+#             */
/*   Updated: 2025/05/16 14:34:33 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;

	dest = s;
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
}
// #include <stdio.h>
// #include <strings.h>
// int	main(void)
// {
// 	char	array1[10] = "ABCDE";
// 	char	array2[10] = "ABCDE";
// 	printf("Before ft_bzero: %s\n", array1);
// 	printf("Before bzero: %s\n", array2);
// 	ft_bzero(array1, 6);
// 	bzero(array2, 6);
// 	printf("After ft_bzero: %s\n", array1);
// 	printf("After bero: %s\n", array2);
// }
