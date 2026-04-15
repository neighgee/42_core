/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:28:55 by mwin              #+#    #+#             */
/*   Updated: 2025/05/16 14:38:42 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c == '\0')
	{
		return (0);
	}
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
	{
		return (0);
	}
	return (1024);
}
// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	//Test with 'a', 'A', '1', '.', 65 (ASCII of A), 64(ASCII of @)
// 	printf("Return value of ft_isalpha: %d\n", ft_isalpha(c1));
// 	printf("Return value of isalpha: %d\n", isalpha(c1));
// }
