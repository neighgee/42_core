/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:23:01 by mwin              #+#    #+#             */
/*   Updated: 2025/05/16 14:49:07 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <bsd/string.h>
// #include <stdio.h>
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while ((i < size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
// int	main(void)
// {
// 	char	dst1[100] = {0};
// 	char	*src1 = "Hello";
// 	unsigned int	size1 = 100;
// 	ft_strlcpy(dst1, src1, size1);
// 	//Output should be "Hello, 6"
// 	printf("ft_strlcpy - Src String: %s \n", src1);
// 	printf("ft_strlcpy - Copied String: %s \n", dst1);
// 	printf("ft_strlcpy-Total string length:%u \n", ft_strlcpy
// (dst1, src1, size1));

// 	char	dst2[100] = {0};
// 	char	*src2 = "Hello";
// 	unsigned int	size2 = 100;
// 	strlcpy(dst2, src2, size2);
// 	//Output should be "Hello, 6"
// 	printf("\n");
// 	printf("strlcpy - Src String: %s \n", src2);
// 	printf("strlcpy - Copied String: %s \n", dst2);
// 	printf("strlcpy - Total string length: %zu \n", strlcpy(dst2, src2, size2));
// }
