/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:46:14 by mwin              #+#    #+#             */
/*   Updated: 2025/05/20 21:15:15 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <bsd/string.h>
// #include <stdio.h>
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if (dst == NULL && size == 0)
	{
		i = 0;
		if (src == NULL)
			return (0);
		while (src[i])
			i++;
		return (i);
	}
	dst_len = ft_strlen(dst);
	src_len = ft_strlen (src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while ((i < size - dst_len - 1) && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
// int	main(void)
// {
// 	char dst1[100] = "Hello ";
// 	char *src1 = "World";
// 	unsigned int	size1 = 10;
// 	unsigned int return_val1 = ft_strlcat(dst1, src1, size1);
// 	//Output should be Hello Wor, 11
// 	printf("ft_strlcat - Appended String: %s \n", dst1);
// 	printf("ft_strlcat - Total string length: %u \n", return_val1);

// 	char dst2[10] = "Hello ";
// 	char *src2 = "World";
// 	unsigned int	size2 = 10;
// 	unsigned int return_val2 = strlcat(dst2, src2, size2);
// 	//Output should be Hello Wor, 11
// 	printf("\n");
// 	printf("strlcat - Appended String: %s \n", dst2);
// 	printf("strlcat - Total string length: %u \n", return_val2);
// }
