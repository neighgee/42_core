/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:23:19 by mwin              #+#    #+#             */
/*   Updated: 2026/01/09 00:32:31 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Function checks if
	//anyone died
	//returns if someone died
	//if not it prints out status
//write lock is used to prevent jumbled up
//lines of threads eating/sleeping/thinking
//meal lock is used to prevent other philosophers from eating jic someone died
//%ld is used to print long interger types
//%zu is used to print size_t data types
void	print_actions(t_all_data *all_data, size_t philo_id, char *msg)
{
	long	time;

	pthread_mutex_lock(&all_data->write_lock);
	pthread_mutex_lock(&all_data->dead_lock);
	if (all_data->is_dead)
	{
		pthread_mutex_unlock(&all_data->dead_lock);
		pthread_mutex_unlock(&all_data->write_lock);
		return ;
	}
	pthread_mutex_unlock(&all_data->dead_lock);
	time = check_time_micros() - all_data->program_start;
	printf("%ld %zu %s\n", time / 1000, philo_id, msg);
	pthread_mutex_unlock(&all_data->write_lock);
}

//action_in_intervals used instead of usleep,
//usleep only guarantees min sleep, not exact, might miss a death
static void	sleep_sequence(t_indv_philo *indv_philo)
{
	print_actions(indv_philo->table, indv_philo->philo_id, "is sleeping");
	action_in_intervals(indv_philo->table->time_to_sleep, indv_philo->table);
}

static void	thinking_sequence(t_indv_philo *indv_philo)
{
	print_actions(indv_philo->table, indv_philo->philo_id, "is thinking");
}

//Odd index philo eats first to reduce starvation, take left first
//
static void	eating_sequence(t_indv_philo *indv_philo)
{
	if (one_philo_case(indv_philo))
		return ;
	if (indv_philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&indv_philo->table->forks[indv_philo->right_fork]);
		pthread_mutex_lock(&indv_philo->table->forks[indv_philo->left_fork]);
	}
	else
	{
		pthread_mutex_lock(&indv_philo->table->forks[indv_philo->left_fork]);
		pthread_mutex_lock(&indv_philo->table->forks[indv_philo->right_fork]);
	}
	print_actions(indv_philo->table, indv_philo->philo_id, "has taken a fork");
	print_actions(indv_philo->table, indv_philo->philo_id, "has taken a fork");
	print_actions(indv_philo->table, indv_philo->philo_id, "is eating");
	pthread_mutex_lock(&indv_philo->meal_lock);
	indv_philo->last_eaten = check_time_micros();
	pthread_mutex_unlock(&indv_philo->meal_lock);
	action_in_intervals(indv_philo->table->time_to_eat, indv_philo->table);
	pthread_mutex_lock(&indv_philo->meal_lock);
	indv_philo->meals_eaten++;
	pthread_mutex_unlock(&indv_philo->meal_lock);
	pthread_mutex_unlock(&indv_philo->table->forks[indv_philo->right_fork]);
	pthread_mutex_unlock(&indv_philo->table->forks[indv_philo->left_fork]);
}

//Overall: Function is to allow odd philos to take forks first
	//While is_dead counter is 0 (aka no one is dead),
	//philosophers eat->sleep->think
//Function to be used with pthread_create,
	//so must be in [[void *function(void *)]] syntax
	//the above syntax is required by pthread_create
	//pthread_create requires function to return NULL
//arg casted to struct -> this is to allow usage with diff types of variables
void	*full_routine(void	*arg)
{
	t_indv_philo	*indv_philo;

	indv_philo = (t_indv_philo *)arg;
	pthread_mutex_lock(&indv_philo->table->write_lock);
	pthread_mutex_unlock(&indv_philo->table->write_lock);
	if (indv_philo->philo_id % 2 == 0)
		usleep(indv_philo->table->time_to_eat / 4);
	while (!check_dead(indv_philo->table))
	{
		eating_sequence(indv_philo);
		sleep_sequence(indv_philo);
		thinking_sequence(indv_philo);
		usleep(1000);
	}
	return (NULL);
}
