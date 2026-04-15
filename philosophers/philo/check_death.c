/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:03:53 by mwin              #+#    #+#             */
/*   Updated: 2026/01/09 00:04:03 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_all_data *all_data)
{
	int	check;

	pthread_mutex_lock(&all_data->dead_lock);
	check = all_data->is_dead;
	pthread_mutex_unlock(&all_data->dead_lock);
	return (check);
}

int	check_for_philo_death(t_all_data *all_data, int i, long time_lapsed)
{
	pthread_mutex_lock(&all_data->philo[i].meal_lock);
	time_lapsed = check_time_micros();
	if ((time_lapsed - all_data->philo[i].last_eaten) > all_data->time_to_die)
	{
		pthread_mutex_unlock(&all_data->philo[i].meal_lock);
		pthread_mutex_lock(&all_data->write_lock);
		pthread_mutex_lock(&all_data->dead_lock);
		if (!all_data->is_dead)
		{
			all_data->is_dead = 1;
			printf("%ld %zu died\n",
				(time_lapsed - all_data->program_start) / 1000,
				all_data->philo[i].philo_id);
		}
		pthread_mutex_unlock(&all_data->dead_lock);
		pthread_mutex_unlock(&all_data->write_lock);
		return (1);
	}
	pthread_mutex_unlock(&all_data->philo[i].meal_lock);
	return (0);
}

//Function to check if philosopher needs to die
	//Checks against last eaten and changes the is_dead counter to 1
	//Dead_lock -> locked when checking for updating is_dead counter
	//Write_lock not needed since it does that in print_actions
void	*dead_routine(void *arg)
{
	t_all_data		*all_data;
	unsigned int	i;
	long			time_lapsed;

	all_data = (t_all_data *)arg;
	pthread_mutex_lock(&all_data->write_lock);
	pthread_mutex_unlock(&all_data->write_lock);
	while (!check_dead(all_data))
	{
		i = 0;
		while (i < all_data->num_philosophers)
		{
			time_lapsed = check_time_micros();
			if (check_for_philo_death(all_data, i, time_lapsed))
				return (NULL);
			i++;
		}
		if (all_data->meal_init && meals_finished(all_data))
			return (pthread_mutex_lock(&all_data->dead_lock),
				all_data->is_dead = 1,
				pthread_mutex_unlock(&all_data->dead_lock), NULL);
		usleep(500);
	}
	return (NULL);
}
