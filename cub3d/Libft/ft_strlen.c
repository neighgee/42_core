/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:51:10 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/14 21:44:05 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++ ;
	return (len);
}

/* #include <stdio.h>
int main()
{
	printf("apple: %zu\n", ft_strlen("apple"));
	printf("banana: %zu\n", ft_strlen("banana"));
	printf("pear: %zu\n", ft_strlen("pear"));
	printf("12345678 9: %zu\n", ft_strlen("12345678 9"));
} */
