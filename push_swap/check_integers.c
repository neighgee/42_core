/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_integers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:02:34 by mwin              #+#    #+#             */
/*   Updated: 2025/09/13 18:42:12 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(const char *n)
{
	int	i;

	i = 0;
	if (!n[i])
		return (error_msg(), 0);
	if (n[i] == '-' || n[i] == '+')
		i++;
	if (!n[i])
		return (error_msg(), 0);
	while (n[i])
	{
		if (n[i] < '0' || n[i] > '9')
			return (error_msg(), 0);
		i++;
	}
	return (1);
}

int	check_duplicate(int *input_array, int count, int number)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (input_array[i] == number)
			return (error_msg(), 1);
		i++;
	}
	return (0);
}

int	check_overflow(const char *n)
{
	long long	number;
	int			i;
	int			sign;

	number = 0;
	sign = 1;
	i = 0;
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i] && (n[i] >= '0' && n[i] <= '9'))
	{
		number = number * 10 + (n[i] - '0');
		if (sign == 1 && number > INT_MAX)
			return (error_msg(), 1);
		if (sign == -1 && - number < INT_MIN)
			return (error_msg(), 1);
		i++;
	}
	return (0);
}
