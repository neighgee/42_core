/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:13:42 by mwin              #+#    #+#             */
/*   Updated: 2026/01/08 22:18:04 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Function is to create as much threads as philosophers
	//number of threads = number of philosophers
	//On success, return 1. On failure, return 0
//pthread_create needs 4 variables, it returns 0 on success
	//1st variable: pointer to a pthread_t variable
		//(help to reuse threads in other functions)
	//2nd variable: pointer for attributes -> NULL here (aka default attributes)
	//3rd variable: pointer to a function for the thread to begin executing
	//4th variable: argument to pass data to the function (aka 3rd variable)
		//for multiple arguments, build struct
		//& pass pointer to that structure as the argument
int	create_threads(t_all_data *all_data)
{
	unsigned int	i;

	i = 0;
	while (i < all_data->num_philosophers)
	{
		if (pthread_create(&all_data->philo[i].thread,
				NULL, full_routine, &all_data->philo[i]))
			return (0);
		all_data->threads_init++;
		i++;
	}
	return (1);
}

//Function is used to join threads, destroy mutexes, free memory
//pthread_join is used to wait for thread to finish & terminate
	//ensure that the program waits for the thread to finish
	//blocks the calling thread(thread that calls the method)
	//used to prevent zombie threads
		//zombie threads are created when threads are not joined
		//or detached to release its resources
//Mutexes are destroyed to prevent race conditions
void	term_threads_mut_mem(t_all_data *all_data)
{
	unsigned int	i;

	i = 0;
	while (all_data->philo && i < all_data->threads_init)
		pthread_join(all_data->philo[i++].thread, NULL);
	i = 0;
	while (all_data->forks && i < all_data->forks_init)
		pthread_mutex_destroy(&all_data->forks[i++]);
	i = 0;
	while (all_data->philo && i < all_data->num_philosophers)
		pthread_mutex_destroy(&all_data->philo[i++].meal_lock);
	if (all_data->write_init)
		pthread_mutex_destroy(&all_data->write_lock);
	if (all_data->dead_init)
		pthread_mutex_destroy(&all_data->dead_lock);
	if (all_data->forks)
		free(all_data->forks);
	if (all_data->philo)
		free(all_data->philo);
}

//return true if only 1 philosopher
int	one_philo_case(t_indv_philo *indv_philo)
{
	if (indv_philo->table->num_philosophers == 1)
	{
		pthread_mutex_lock(&indv_philo->table->forks[indv_philo->left_fork]);
		print_actions(indv_philo->table,
			indv_philo->philo_id, "has taken a fork");
		action_in_intervals(indv_philo->table->time_to_die, indv_philo->table);
		pthread_mutex_unlock(&indv_philo->table->forks[indv_philo->left_fork]);
		return (1);
	}
	return (0);
}

int	monitor_thread_start(t_all_data *all_data, pthread_t *dead_thread)
{
	unsigned int	i;

	i = 0;
	if (pthread_create(dead_thread, NULL, dead_routine, all_data))
	{
		pthread_mutex_unlock(&all_data->write_lock);
		term_threads_mut_mem(all_data);
		return (0);
	}
	if (!create_threads(all_data))
	{
		pthread_mutex_unlock(&all_data->write_lock);
		term_threads_mut_mem(all_data);
		return (0);
	}
	all_data->program_start = check_time_micros();
	while (i < all_data->num_philosophers)
	{
		pthread_mutex_lock(&all_data->philo[i].meal_lock);
		all_data->philo[i].last_eaten = all_data->program_start;
		pthread_mutex_unlock(&all_data->philo[i].meal_lock);
		i++;
	}
	return (1);
}

int	meals_finished(t_all_data *all_data)
{
	size_t	i;

	i = 0;
	while (i < all_data->num_philosophers)
	{
		pthread_mutex_lock(&all_data->philo[i].meal_lock);
		if (all_data->philo[i].meals_eaten < all_data->meal_init)
		{
			pthread_mutex_unlock(&all_data->philo[i].meal_lock);
			return (0);
		}
		pthread_mutex_unlock(&all_data->philo[i].meal_lock);
		i++;
	}
	return (1);
}
