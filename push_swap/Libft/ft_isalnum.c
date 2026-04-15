/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:17:49 by mwin              #+#    #+#             */
/*   Updated: 2025/05/16 14:38:27 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c == '\0')
	{
		return (0);
	}
	if (!(ft_isalpha(c) || ft_isdigit(c)))
	{
		return (0);
	}
	return (8);
}
// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	//Test with '9', '.', 'a', 'A', 48 (ASCII of 0), 64(ASCII of @)
// 	printf("Return value of ft_isalnum: %d\n", ft_isalnum('A'));
// 	printf("Return value of isalnum: %d\n", isalnum('A'));
// }
