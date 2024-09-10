/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_table.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:33:42 by noam              #+#    #+#             */
/*   Updated: 2024/09/10 17:38:34 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static inline bool	starved(t_philosopher *philo)
{
	return (((get_time() - philo->last_meal)
			>= philo->table->time_to_die));
}

/* ************************************************************************** */

static inline void	all_have_eaten(t_table *args)
{
	pthread_mutex_lock(&args->monitor);
	args->should_stop = true;
	printf("Every Philosopher had %d meals!\n", args->to_satiety);
	pthread_mutex_unlock(&args->monitor);
}

/* ************************************************************************** */

/* Checks if a philosopher has died, returns true if so,
Also checks if the philosher have eaten <to_satiety>,
and if so increments args.satisfied_philos and also checks */
static bool	is_philo_dead(t_table *args, t_philosopher *philo,
							int *satisfied_philos)
{
	pthread_mutex_lock(&args->monitor);
	if (args->to_satiety > 0 && philo->meal_count >= args->to_satiety)
		*satisfied_philos += 1;
	pthread_mutex_unlock(&args->monitor);
	if (starved(philo))
	{
		write_action(philo, DEAD);
		pthread_mutex_lock(&args->monitor);
		args->should_stop = true;
		pthread_mutex_unlock(&args->monitor);
		return (true);
	}
	return (false);
}

/* ************************************************************************** */

/* Function that watches the philosophers' activity */
static void	overseeing_diner(t_philosopher *philos, t_table *args)
{
	int	satisfied_philos;
	int	i;

	while (true)
	{
		i = -1;
		satisfied_philos = 0;
		while (++i < args->nb_of_philo)
		{
			if (is_philo_dead(args, &philos[i], &satisfied_philos))
				return ;
		}
		if (satisfied_philos == args->nb_of_philo)
			return (all_have_eaten(args));
		usleep(1000);
	}
}

/* ************************************************************************** */

bool	a_table(t_philosopher *philos, t_table *table, pthread_mutex_t *stick)
{
	int	i;

	i = -1;
	while (++i < table->nb_of_philo)
	{
		philos[i].start_time = get_time();
		if (pthread_create(&philos[i].thread,
				NULL, diner, (void *)&philos[i]) != 0)
			return (free_n_exit(philos, stick, table, THREAD_ERROR));
	}
	overseeing_diner(philos, table);
	i = -1;
	while (++i < table->nb_of_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (free_n_exit(philos, stick, table, THREAD_ERROR));
	}
	return (true);
}
