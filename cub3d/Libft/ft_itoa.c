/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:58:55 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/14 21:31:04 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

static void	ft_intlcpy(int n, char *dst, int size, int sign)
{
	if (sign == -1)
		dst[0] = '-';
	dst[size] = '\0';
	size--;
	while (size >= 0 + sign * sign)
	{
		dst[size] = n % 10 + '0';
		n /= 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*ptr;
	int		i;

	sign = 0;
	if (n == -2147483648)
	{
		ptr = malloc(12);
		ptr[0] = '-';
		ptr[1] = '2';
		ft_intlcpy(147483648, ptr + 2, 9, 0);
		return (ptr);
	}
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	i = ft_digits(n) + sign * sign;
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	ft_intlcpy(n, ptr, i, sign);
	return (ptr);
}

/* #include <stdio.h>

int main()
{
	printf("1: %s\n", ft_itoa(1));
	printf("-12345: %s\n", ft_itoa(-12345));
	printf("-2147483648: %s\n", ft_itoa(-2147483648));
} */
