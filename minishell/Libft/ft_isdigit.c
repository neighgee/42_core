/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:53:50 by mwin              #+#    #+#             */
/*   Updated: 2025/05/16 14:38:57 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c == '\0')
	{
		return (0);
	}
	if (!(c >= '0' && c <= '9'))
	{
		return (0);
	}
	return (2048);
}
// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	//Test with '9', '.', 'a', 'A', 48 (ASCII of 0), 64(ASCII of @)
// 	printf("Return value of ft_isdigit: %d\n", ft_isdigit(48));
// 	printf("Return value of isdigit: %d\n", isdigit(48));
// }
