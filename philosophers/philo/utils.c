/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:04:44 by mwin              #+#    #+#             */
/*   Updated: 2026/01/12 14:35:31 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v' || *nptr == '\f'
		|| *nptr == '\r' || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
		if (*nptr == '-' || *nptr == '+')
			return (0);
	}
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10 + (*nptr++ - '0');
	if ((sign == 1 && result > 2147483647LL)
		|| (sign == -1 && result > 2147483648LL))
		return (-1);
	return ((int)(result * sign));
}

static int	ft_isdigit(int c)
{
	if (c == '\0')
	{
		return (0);
	}
	if (!(c >= '0' && c <= '9'))
	{
		return (0);
	}
	return (2048);
}

int	string_isnum(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//struct timeval is a variable that contains the time in seconds & microseconds
//gettimeofday fills the variable current_time with the current time.
	//2nd paramter is for timezone, irrelevant here
	//returns 1 on failure
//current_time.tv_sec: seconds since Jan 1 1970
//current_time.tv_usec: microseconds in the current second
//1000000L: 1 million as a long integer
long	check_time_micros(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
		return (0);
	return (current_time.tv_sec * 1000000L + current_time.tv_usec);
}

//is_dead is 0 if there is no one dead, will change to 1 if someone died
void	action_in_intervals(long time_to_action, t_all_data *all_data)
{
	long	start_time;

	start_time = check_time_micros();
	while (!check_dead(all_data))
	{
		if (check_time_micros() - start_time >= time_to_action)
			break ;
		usleep(200);
	}
}
