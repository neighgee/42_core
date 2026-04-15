/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:41:28 by mwin              #+#    #+#             */
/*   Updated: 2025/10/02 20:23:07 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_ready = 0;

void	check_ready(int signals)
{
	(void)signals;
	g_ready = 1;
}

void	send_signal(pid_t server_pid, char character)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ready = 0;
		if ((character >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (!g_ready)
			pause();
		i--;
	}
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
	int					i;
	struct sigaction	noted;
	pid_t				server_pid;

	if (argc != 3)
	{
		ft_printf("Please write accordingly: ./client <server_pid> <string>\n");
		return (1);
	}
	ft_memset(&noted, 0, sizeof(noted));
	noted.sa_handler = check_ready;
	sigemptyset(&noted.sa_mask);
	sigaction(SIGUSR1, &noted, NULL);
	if (!check_pid(argv[1]))
		return (1);
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_signal(server_pid, (unsigned char)argv[2][i]);
		i++;
	}
	send_signal(server_pid, '\0');
	return (0);
}
