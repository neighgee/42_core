/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:13:51 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/17 15:27:08 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* #include <stdio.h>
int main()
{
    printf("ft_isalpha(0): %d\n", ft_isdigit(0));
    printf("ft_isalpha('a'): %d\n", ft_isdigit('a'));
    printf("ft_isalpha('A'): %d\n", ft_isdigit('A'));
    printf("ft_isalpha('2'): %d\n", ft_isdigit('2'));

} */
