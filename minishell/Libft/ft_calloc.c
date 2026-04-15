/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:52:19 by mwin              #+#    #+#             */
/*   Updated: 2025/05/24 16:19:18 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdint.h>
// #include <stdio.h>
// #include <string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if ((size != 0) && (nmemb > (SIZE_MAX / size)))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

// int main(void)
// {
//     size_t n = 16;
//     char *std = calloc(n, 1);
//     char *mine = ft_calloc(n, 1);

//     if (!std || !mine) {
//         printf("Allocation failed.\n");
//         return 1;
//     }

//     if (memcmp(std, mine, n) == 0)
//         printf("Memory is correctly zero-initialized and matches calloc.\n");
//     else
//         printf("Memory differs — check your ft_calloc implementation.\n");

//     free(std);
//     free(mine);
//     return 0;
// }
