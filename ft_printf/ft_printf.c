/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:38:02 by mwin              #+#    #+#             */
/*   Updated: 2025/07/31 11:44:19 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_characters(char character, va_list *arguments)
{
	if (character == 'c')
		return (print_char(va_arg(*arguments, int)));
	if (character == 's')
		return (print_string(va_arg(*arguments, char *)));
	if (character == 'd' || character == 'i')
		return (print_number(va_arg(*arguments, int)));
	if (character == 'u')
		return (print_unsigned(va_arg(*arguments, unsigned int)));
	if (character == 'x')
		return (print_hex(va_arg(*arguments, unsigned int), 0));
	if (character == 'X')
		return (print_hex(va_arg(*arguments, unsigned int), 1));
	if (character == 'p')
	{
		return (print_pointer(va_arg(*arguments, void *)));
	}
	if (character == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		i;
	int		to_print;

	i = 0;
	to_print = 0;
	va_start(arguments, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			to_print = to_print + handle_characters(format[i], &arguments);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			to_print++;
		}
		i++;
	}
	va_end(arguments);
	return (to_print);
}

// #include <stdio.h>

// int main(void)
// {
// 	int ret;

// 	ret = ft_printf(" %p %p ", (void *)0, (void *)0);
// 	ft_printf("\nft_printf returned: %d\n", ret);

// 	ret = printf(" %p %p ", (void *)0, (void *)0);
// 	printf("\nprintf returned: %d\n", ret);
// }
