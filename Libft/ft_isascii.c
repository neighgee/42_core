/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:43:36 by mwin              #+#    #+#             */
/*   Updated: 2025/05/15 20:12:00 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	//Test with 129, '9', '.', 'a', 'A', 48 (ASCII of 0), 64(ASCII of @)
// 	printf("Return value of ft_isascii: %d\n", ft_isascii('\0'));
// 	printf("Return value of isascii: %d\n", isascii('\0'));
// }
