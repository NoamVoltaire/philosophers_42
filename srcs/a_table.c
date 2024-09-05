/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_table.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:33:42 by noam              #+#    #+#             */
/*   Updated: 2024/09/05 16:31:12 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"



static inline void	all_have_eaten(t_table *args)
{
	pthread_mutex_lock(&args->monitor);
	args->should_stop = true;
	pthread_mutex_unlock(&args->monitor);
	printf("Every Philosopher had %d meals!\n", args->to_satiety);
}

/* Checks if a philosopher has died, returns true if so,
Also checks if the philosher have eaten <to_satiety>,
and if so increments args.satisfied_philos and also checks */
static bool	is_philo_dead(t_table *args, t_philosopher *philo, int *satisfied_philos)
{
	if (args->to_satiety > 0 && philo->meal_count >= args->to_satiety)
		*satisfied_philos += 1;
	if (starved(philo))
	{
		// pthread_mutex_unlock(&args->monitor);
		write_action(philo, DEAD);
		pthread_mutex_lock(&args->monitor);
		args->should_stop = true;
		pthread_mutex_unlock(&args->monitor);
		return (true);
	}
	return (false);
}

/* Function that watches the philosophers' activity */
static void	overseeing_diner(t_philosopher *philos, t_table *args)
{
	int	satisfied_philos;
	int	i;

	satisfied_philos = 0;
	while (true)
	{
		i = -1;
		// pthread_mutex_lock(&args->monitor);
		while (++i < args->nb_of_philo)
		{
			if (is_philo_dead(args, &philos[i], &satisfied_philos))
				return ;
		}
		if (satisfied_philos == args->nb_of_philo)
			return (all_have_eaten(args));
		usleep(1000);
		// pthread_mutex_unlock(&args->monitor);
	}
}




bool	a_table(t_philosopher *philos,/* t_cutlery *chopsticks,*/
														t_table *table)
{
	/* make thread until all philos are in threads
	make function for eating routine, picking forks, thinking, sleeping etc
		inside of those will be the mutex lock and unlock and
		the func for writing the action to the terminal (with enum)

	make function for checking if the philo are alive, or if satiated
		will be a while loop
	
	then join the threads (end of the simulation)
	
	 */
	// void *((*diner)(void*));
	int	i;

	// void *(*_diner)(void *);
	// if (table->nb_of_philo % 2)
	// 	_diner = diner_even;
	// else
	// 	_diner = diner_even;
			
	i = -1;
	while (++i < table->nb_of_philo)
	{
		philos[i].start_time = get_time();
		if (pthread_create(&philos[i].thread, NULL, diner, (void *)&philos[i]) != 0)
			return (false);
	}
	overseeing_diner(philos, table);
	i = -1;
	while (++i < table->nb_of_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (false);
	}
	// free_forks(&chopsticks, table->nb_of_philo);
	return (true); 
}
