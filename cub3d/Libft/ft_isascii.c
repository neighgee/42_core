/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:31:43 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/20 16:25:47 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	c = (unsigned char)c;
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* #include <stdio.h>
int main()
{
	printf("ft_isascii('!'): %d\n", ft_isascii('!'));
	printf("ft_isascii('1'): %d\n", ft_isascii('1'));
	printf("ft_isascii('~'): %d\n", ft_isascii('~'));
	printf("ft_isascii('t'): %d\n", ft_isascii('~'));
} */
