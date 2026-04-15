/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:18:39 by mwin              #+#    #+#             */
/*   Updated: 2025/05/20 20:57:12 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;

	if (n == 0 || dest == src)
		return (dest);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	if (char_dest < char_src)
	{
		while (n--)
			*char_dest++ = *char_src++;
	}
	if (dest > src)
	{
		char_dest += n - 1;
		char_src += n -1;
		while (n--)
		{
			*char_dest-- = *char_src--;
		}
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*src = NULL;
// 	char	*dest1 = NULL;
// 	char	*dest2 = NULL;

// 	printf("Before ft_memmove: dest = %s, src = %s\n\n", dest1, src);
// 	printf("Before memmove: dest = %s, src = %s\n\n", dest2, src);
// 	ft_memmove(dest1, src, 10);
// 	memmove(dest2, src, 0);
// 	printf("After ft_memmove: dest = %s, src = %s\n\n", dest1, src);
// 	printf("After memmove: dest = %s, src = %s\n\n", dest2, src);
// }
