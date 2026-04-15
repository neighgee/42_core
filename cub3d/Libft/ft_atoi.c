/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:23:53 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/15 17:22:35 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (ft_strncmp(nptr, "-2147483648", 12) == 0)
		return (-2147483648);
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + *nptr - '0';
		nptr++;
	}
	return (sign * result);
}
/* #include <stdio.h>
#include <string.h>
int main()
{
	//char e[] = {9, 10, 11, 12, 13, 0};

	printf("+1: %d\n", ft_atoi("+1"));
	printf("--1234: %d\n", ft_atoi("--1234"));
	printf("++1234: %d\n", ft_atoi("++1234"));
	printf("-  2147483648: %d\n", ft_atoi("-  2147483648"));
	printf("  -2147483648: %d\n", ft_atoi("  -2147483648"));

} */