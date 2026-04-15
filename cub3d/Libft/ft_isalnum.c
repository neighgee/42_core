/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:19:42 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/14 21:27:54 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/* #include <stdio.h>
int main()
{
    printf("ft_isalpha(0): %d\n", ft_isalnum(0));
    printf("ft_isalpha('a'): %d\n", ft_isalnum('a'));
    printf("ft_isalpha('A'): %d\n", ft_isalnum('A'));
    printf("ft_isalpha('2'): %d\n", ft_isalnum('2'));
	printf("ft_isalpha('`'): %d\n", ft_isalnum('`'));
	printf("ft_isalpha(' '): %d\n", ft_isalnum(' '));
} */
