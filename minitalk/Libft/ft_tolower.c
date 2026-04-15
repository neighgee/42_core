/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:38:54 by mwin              #+#    #+#             */
/*   Updated: 2025/05/10 16:49:11 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	char_c;

	char_c = (unsigned char)c;
	if (char_c >= 'A' && char_c <= 'Z')
	{
		char_c = char_c - ('A' - 'a');
		return (char_c);
	}
	return (c);
}
// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int c1 = 65;
// 	int c2 = 65;

// 	printf("Before transformation, ft_tolower: %c\n", c1);
// 	printf("After transformation, ft_tolower: %d\n", ft_tolower(c1));
// 	printf("Before transformation, tolower: %c\n", c2);
// 	printf("After transformation, tolower: %d\n", tolower(c2));
// }
