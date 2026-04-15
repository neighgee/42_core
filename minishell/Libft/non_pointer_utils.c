/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_pointer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:04:36 by mwin              #+#    #+#             */
/*   Updated: 2025/08/14 15:41:35 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_string(char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (i);
}

int	print_number(int number)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	if (number == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (number < 0)
	{
		count = 1;
		nbr = (unsigned int)(-(long)number);
	}
	else
		nbr = (unsigned int)number;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	ft_putnbr_fd(number, 1);
	return (count);
}

int	print_unsigned(unsigned int number)
{
	unsigned int	nbr;
	int				count;

	nbr = number;
	count = 0;
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (nbr >= 10)
		count += print_unsigned(nbr / 10);
	ft_putchar_fd('0' + (nbr % 10), 1);
	count++;
	return (count);
}
