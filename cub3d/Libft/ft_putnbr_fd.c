/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:09:52 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/24 18:23:31 by smariapp         ###   ########.fr       */
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

static int	ft_pow(int num, int exp)
{
	int	base;

	base = num;
	while (exp > 1)
	{
		num *= base;
		exp--;
	}
	if (exp == 0)
		num = 1;
	return (num);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		digits;
	int		num;
	char	temp[1];
	int		divisor;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	digits = ft_digits(n);
	while (digits > 0)
	{
		divisor = ft_pow(10, digits - 1);
		num = n / divisor;
		temp[0] = num + '0';
		write (fd, temp, 1);
		n %= divisor;
		digits --;
	}
}

/* #include <stdio.h>
int main()
{
	ft_putnbr_fd(-2147483648, 1);
} */
