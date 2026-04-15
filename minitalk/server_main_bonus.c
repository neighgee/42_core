/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:47:19 by mwin              #+#    #+#             */
/*   Updated: 2025/09/22 11:26:19 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	reset(int *bit, unsigned char *ascii_char)
{
	*bit = 0;
	*ascii_char = 0;
}

static void	eight_bits(unsigned char *ascii_char, int *bit
	, pid_t *current_pid, pid_t client_pid)
{
	if (*ascii_char == '\0')
	{
		write(1, "\n", 1);
		reset(bit, ascii_char);
		*current_pid = 0;
		kill(client_pid, SIGUSR1);
	}
	else
	{
		write(1, ascii_char, 1);
		reset(bit, ascii_char);
		kill(client_pid, SIGUSR1);
	}
}

//SIGUSR1 mapped to bit 1
//SIGUSR 2 mapped to bit 0
void	handle_signal(int signal, siginfo_t *details, void *context)
{
	static int				bit;
	static unsigned char	ascii_char;
	static pid_t			current_pid;

	(void)context;
	if (current_pid != details->si_pid)
	{
		current_pid = details->si_pid;
		reset(&bit, &ascii_char);
	}
	if (signal == SIGUSR1)
		ascii_char |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
		eight_bits(&ascii_char, &bit, &current_pid, details->si_pid);
	else
		kill(details->si_pid, SIGUSR1);
}

static void	handle_ctrl_c(int signal)
{
	(void)signal;
	write(1, "\n[Server shutting down...]\n", 27);
	exit(0);
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	signals;
	struct sigaction	ctrl_c;

	ft_memset(&signals, 0, sizeof(signals));
	signals.sa_sigaction = handle_signal;
	signals.sa_flags = SA_SIGINFO;
	sigemptyset(&signals.sa_mask);
	sigaction(SIGUSR1, &signals, NULL);
	sigaction(SIGUSR2, &signals, NULL);
	ft_memset(&ctrl_c, 0, sizeof(ctrl_c));
	ctrl_c.sa_handler = handle_ctrl_c;
	sigemptyset(&ctrl_c.sa_mask);
	sigaction(SIGINT, &ctrl_c, NULL);
	server_pid = getpid();
	ft_printf("My PID is: %d\n", server_pid);
	while (1)
		pause();
	return (0);
}
