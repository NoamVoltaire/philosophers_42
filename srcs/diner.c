/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:31:40 by noam              #+#    #+#             */
/*   Updated: 2024/09/10 17:25:37 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* ************************************************************************** */

static void	take_chopsticks(t_philosopher *philo)
{
	pthread_mutex_lock(philo->first_chopstick);
	write_action(philo, TOOK);
	pthread_mutex_lock(philo->second_chopstick);
	write_action(philo, TOOK);
}

/* ************************************************************************** */

void	u_sleep(suseconds_t time)
{
	suseconds_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(10);
}

/* ************************************************************************** */

void	sleep_(t_philosopher *philo)
{
	write_action(philo, SLEEP);
	u_sleep(philo->table->time_to_sleep);
}

/* ************************************************************************** */

void	eat(t_philosopher *philo)
{
	take_chopsticks(philo);
	write_action(philo, EAT);
	u_sleep(philo->table->time_to_eat);
	pthread_mutex_unlock(philo->second_chopstick);
	pthread_mutex_unlock(philo->first_chopstick);
	pthread_mutex_lock(&philo->table->monitor);
	philo->meal_count++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->table->monitor);
}

/* ************************************************************************** */

void	*diner(void *void_philo)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)void_philo;
	if (philo->table->nb_of_philo == 1)
	{
		write_action(philo, TOOK);
		return (NULL);
	}
	if (philo->name % 2)
		u_sleep(10);
	while (true)
	{
		if (get_time() - philo->last_meal > philo->table->time_to_die)
			break ;
		if (philo->table->should_stop)
			break ;
		eat(philo);
		sleep_(philo);
		write_action(philo, THINK);
	}
	return (NULL);
}
