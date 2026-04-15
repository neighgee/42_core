/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:41:28 by mwin              #+#    #+#             */
/*   Updated: 2025/10/02 16:38:01 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(pid_t server_pid, char character, int seconds)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = ((character >> i) & 1);
		if (bit == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(seconds);
		i--;
	}
}

int	control_usleep(int str_len)
{
	if (str_len >= 2000)
		return (5000);
	else if (str_len >= 1000)
		return (4000);
	else if (str_len >= 500)
		return (2000);
	else
		return (250);
}

int	check_pid(const char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
		{
			ft_printf("Error: PID must be digit only!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		seconds;
	int		str_len;
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_printf("Please write accordingly: ./client <server_pid> <string>\n");
		return (1);
	}
	if (!check_pid(argv[1]))
		return (1);
	server_pid = ft_atoi(argv[1]);
	str_len = ft_strlen(argv[2]);
	seconds = control_usleep(str_len);
	i = 0;
	while (argv[2][i])
	{
		send_signal(server_pid, argv[2][i], seconds);
		i++;
	}
	send_signal(server_pid, '\0', seconds);
	return (0);
}
