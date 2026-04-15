/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:59:19 by mwin              #+#    #+#             */
/*   Updated: 2026/01/12 14:36:06 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Overall: 
//1. Initialises an array for forks, 
//set up counter for how many forks has been initialised
//2. Initialises mutexes for deadlock & writelock
//set up counter for the number of write & dead locks
//3. Returns 1 on success, 0 on failure
//NOTE: pthread_mutext_init returns 0 on success!
	//pthread_mutext_init 2nd variable is to assign certain attributes
	//eg of attributes
		//(deadlocking, deadlock detecting,how robust it is
		//robust meaning how good it protects against errors)
int	initialise_mutexes(t_all_data *all_data)
{
	unsigned int	i;

	i = 0;
	all_data->forks = malloc(sizeof(pthread_mutex_t)
			* all_data->num_philosophers);
	if (!all_data->forks)
		return (0);
	while (i < all_data->num_philosophers)
	{
		if (pthread_mutex_init(&all_data->forks[i], NULL))
			return (0);
		all_data->forks_init++;
		i++;
	}
	if (pthread_mutex_init(&all_data->dead_lock, NULL))
		return (0);
	all_data->dead_init = 1;
	if (pthread_mutex_init(&all_data->write_lock, NULL))
		return (0);
	all_data->write_init = 1;
	return (1);
}

//Function is to initialise all the data in linked list
//Right fork calculation is to enforce circle table
//last philo right fork is first philo's left fork (circular)
int	initialise_philos(t_all_data *all_data)
{
	unsigned int	i;

	i = 0;
	all_data->philo = malloc(sizeof(t_indv_philo) * all_data->num_philosophers);
	if (!all_data->philo)
		return (0);
	while (i < all_data->num_philosophers)
	{
		all_data->philo[i].philo_id = i + 1;
		all_data->philo[i].left_fork = i;
		all_data->philo[i].right_fork = (i + 1) % all_data->num_philosophers;
		all_data->philo[i].last_eaten = 0;
		all_data->philo[i].table = all_data;
		all_data->philo[i].meals_eaten = 0;
		if (pthread_mutex_init(&all_data->philo[i].meal_lock, NULL))
			return (0);
		i++;
	}
	return (1);
}

int	valid_args(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		printf("Wrong Number of Arguments!\n");
		return (0);
	}
	if (!string_isnum(argv[1]) || !string_isnum(argv[2])
		|| !string_isnum(argv[3]) || !string_isnum(argv[4]))
	{
		printf("Wrong Type of Arguments!\n");
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
	{
		printf("Inputs should be postive integers and ");
		printf("only up to INT MAX!\n");
		return (0);
	}
	if (argc == 6 && (!string_isnum(argv[5]) || ft_atoi(argv[5]) <= 0))
	{
		printf("Last argument is wrong!\n");
		return (0);
	}
	return (1);
}

//Function is to simultaneously initialise all the data
//Meal_init is for number of times philo must eat
int	init_mut_indv_data(t_all_data *all_data, int argc, char **argv)
{
	all_data->num_philosophers = ft_atoi(argv[1]);
	all_data->time_to_die = ft_atoi(argv[2]) * 1000;
	all_data->time_to_eat = ft_atoi(argv[3]) * 1000;
	all_data->time_to_sleep = ft_atoi(argv[4]) * 1000;
	all_data->meal_init = 0;
	if (argc == 6)
		all_data->meal_init = ft_atoi(argv[5]);
	all_data->is_dead = 0;
	if (!initialise_mutexes(all_data))
	{
		term_threads_mut_mem(all_data);
		return (0);
	}
	if (!initialise_philos(all_data))
	{
		term_threads_mut_mem(all_data);
		return (0);
	}
	return (1);
}

//check for valid arguments(eg. numbers) & convert to integers
//convert inputs to microseconds
	//-> usleep and gettimeofday are in microseconds
//microseconds give more room for delay in thread scheduling
int	main(int argc, char *argv[])
{
	pthread_t	dead_thread;
	t_all_data	*all_data;

	if (!valid_args(argc, argv))
		return (1);
	all_data = malloc((sizeof(t_all_data)));
	if (!all_data)
		return (1);
	memset(all_data, 0, sizeof(t_all_data));
	if (!init_mut_indv_data(all_data, argc, argv))
	{
		free(all_data);
		return (1);
	}
	pthread_mutex_lock(&all_data->write_lock);
	if (!monitor_thread_start(all_data, &dead_thread))
	{
		free(all_data);
		return (1);
	}
	pthread_mutex_unlock(&all_data->write_lock);
	pthread_join(dead_thread, NULL);
	term_threads_mut_mem(all_data);
	free(all_data);
	return (0);
}
