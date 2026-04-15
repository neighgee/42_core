/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:15:47 by mwin              #+#    #+#             */
/*   Updated: 2025/05/16 14:39:18 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c == '\0')
	{
		return (0);
	}
	if (c >= ' ' && c <= '~')
	{
		return (16384);
	}
	return (0);
}
// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	//Test with '\0', '9', ' ', '~', 'A', 48 (ASCII of 0), 64(ASCII of @)
// 	printf("Return value of ft_isprint: %d\n", ft_isprint(127));
// 	printf("Return value of isprint: %d\n", isprint(127));
// }
