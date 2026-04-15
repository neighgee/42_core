/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_pointer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:05:22 by mwin              #+#    #+#             */
/*   Updated: 2025/07/31 11:41:22 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(uintptr_t n, int is_upper)
{
	char	*base;
	int		count;

	count = 0;
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	else if (n >= 16)
		count += print_hex(n / 16, is_upper);
	ft_putchar_fd(base[n % 16], 1);
	return (count + 1);
}

int	print_pointer(void *pointer)
{
	uintptr_t	address;

	if (!pointer)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	address = (uintptr_t)pointer;
	ft_putstr_fd("0x", 1);
	return (2 + print_hex(address, 0));
}
