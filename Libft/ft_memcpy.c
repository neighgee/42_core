/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:28:53 by mwin              #+#    #+#             */
/*   Updated: 2025/05/22 12:47:33 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;

	if (!dest && !src)
		return (NULL);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	while (n > 0)
	{
		*char_dest = *char_src;
		char_dest++;
		char_src++;
		n--;
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	src[10] = "šššš";
// 	char	dest1[10] = {0};
// 	char	dest2[10] = {0};

// 	printf("Before ft_memcpy: %s\n", dest1);
// 	printf("Before memcpy: %s\n", dest2);
// 	ft_memcpy(dest1, src, 6);
// 	memcpy(dest2, src, 6);
// 	printf("After ft_memcpy: %s\n", dest1);
// 	printf("After memcpy: %s\n", dest2);
// }
