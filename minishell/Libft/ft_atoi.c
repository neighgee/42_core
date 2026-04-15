/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:14:51 by mwin              #+#    #+#             */
/*   Updated: 2025/05/24 16:18:36 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	count_sign;

	result = 0;
	sign = 1;
	count_sign = 0;
	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v' || *nptr == '\f'
		|| *nptr == '\r' || *nptr == ' ')
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		count_sign++;
		if (*nptr == '-')
			sign = -sign;
		if (count_sign > 1)
			return (0);
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}
// int	main(void)
// {
// 	int res_val1;
// 	char inp_str1[100] = "   \t\t-123abc 55";
// 	res_val1 = ft_atoi(inp_str1);
// 	int res_val2;
// 	char inp_str2[100] = "   \t\t-123abc 55";
// 	res_val2 = atoi(inp_str2);
// 	printf("ft_atoi: Input = %s\nResulting Integer = %d\n",inp_str1, res_val1);
// 	printf("atoi: Input = %s\nResulting Integer = %d\n",inp_str2, res_val2);
// }
