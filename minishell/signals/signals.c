/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:48:14 by mwin              #+#    #+#             */
/*   Updated: 2026/02/13 12:39:37 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//when EOF is reached, or ctrl_d gets pressed
int	ctrl_d(char *input_string)
{
	if (!input_string)
	{
		return (1);
	}
	return (0);
}

/* Function to print a newline and reset the prompt
1. rl_on_new_line: used to tell the shell that,
	it has moved to a new, empty line
2. rl_replace_line: replaces the current content of
	the input line buffer with an empty string and,
	does not clear the undo history for that line.
3. rl_redisplay(): used to update display of shell */
void	ctrl_c(int signal)
{
	(void)signal;
	g_sigint = 1;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/* This function is to ensure that when Ctrl-C and Ctrl-\ are pressed,
	Ctrl-C: cancels current input BUT shell STILL runs
	CTRL-\: does nth + ensures child processes can still run normally */
/* Explanations of functions used:
	->sigemptyset: initialises a signal set to be empty
	->sa_int.sa_flags: set to 0 means no special flags
		flags are used to specify behaviour of signal handling process
	->sigaction has 3 variables
		-1st: Signal to watch out for
		-2nd: pointer to struct for new action aka what to do now
		-3rd: used to access previous action for the signal,
			-if NULL action not saved
	->SIG_IGN - ignore particular signal
		-aka when ctrl-\ pressed, signal ignored */
void	initialise_signals(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sa_int.sa_handler = ctrl_c;
	sigaction(SIGINT, &sa_int, NULL);
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_flags = 0;
	sa_quit.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa_quit, NULL);
}

void	initialise_exec_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

/* Function is used to ensure child process handles SIGINT & SIGQUIT to default
Function needs child processes to "behave like bash" according to subject
Subject only asks for diff signal behaviour in interactive mode
SIG_DFL - default signals used for child process
2 sets of sigaction needed for CtrlC & ctrl-\ pressed
signals are independent, one sigaction per signal

Function is to be used with pipex's child processes
1. "empties" the signal mask using sigemptyset
2. Reset flags using sa.sa_flags = 0;
3. CTRL-C aka SIGINT signal pressed, it terminates the child aka interrupt
4. CTRL-\ aka SIGQUIT signal pressed, it quits the child
 */
void	initialise_child_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_DFL;
	sigaction(SIGQUIT, &sa, NULL);
}
