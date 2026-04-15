/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:20:31 by mwin              #+#    #+#             */
/*   Updated: 2025/05/10 16:46:13 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	char_c;

	char_c = (unsigned char)c;
	if (char_c >= 'a' && char_c <= 'z')
	{
		char_c = char_c - ('a' - 'A');
		return (char_c);
	}
	return (c);
}
// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int c1 = 97;
// 	int c2 = 97;

// 	printf("Before transformation, ft_toupper: %c\n", c1);
// 	printf("After transformation, ft_toupper: %d\n", ft_toupper(c1));
// 	printf("Before transformation, toupper: %c\n", c2);
// 	printf("After transformation, toupper: %d\n", toupper(c2));
// }
