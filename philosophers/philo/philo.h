/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:21:05 by mwin              #+#    #+#             */
/*   Updated: 2026/01/08 21:10:43 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_indv_philo	t_indv_philo;
typedef struct s_all_data	t_all_data;

typedef struct s_indv_philo
{
	pthread_t		thread;
	pthread_mutex_t	meal_lock;
	size_t			philo_id;
	long			last_eaten;
	size_t			meals_eaten;
	size_t			left_fork;
	size_t			right_fork;
	t_all_data		*table;
}	t_indv_philo;

//forks is an array for all forks (same number as num of philosophers)
typedef struct s_all_data
{
	long			program_start;
	long			time_to_eat;
	long			time_to_die;
	long			time_to_sleep;
	size_t			num_philosophers;
	size_t			threads_init;
	pthread_mutex_t	*forks;
	size_t			forks_init;
	pthread_mutex_t	dead_lock;
	size_t			dead_init;
	pthread_mutex_t	write_lock;
	size_t			write_init;
	size_t			meal_init;
	int				is_dead;
	t_indv_philo	*philo;
}	t_all_data;

//utils functions
int		ft_atoi(const char *nptr);
int		string_isnum(char *str);
long	check_time_micros(void);
void	action_in_intervals(long time_to_action, t_all_data *all_data);

//eat_sleep_think functions
void	print_actions(t_all_data *all_data, size_t philo_id, char *msg);
void	*full_routine(void	*arg);

//threading functions
int		create_threads(t_all_data *all_data);
int		one_philo_case(t_indv_philo *indv_philo);
void	term_threads_mut_mem(t_all_data *all_data);
int		monitor_thread_start(t_all_data *all_data, pthread_t *dead_thread);
int		meals_finished(t_all_data *all_data);

//check_death functions
void	*dead_routine(void *arg);
int		check_dead(t_all_data *all_data);

#endif
