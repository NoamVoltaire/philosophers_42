/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:31:40 by noam              #+#    #+#             */
/*   Updated: 2024/08/23 17:15:44 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* ************************************************************************** */

static void	take_chopsticks(t_philosopher *philo)
{
	if (philo->name % 2 == 0)
	{
		pthread_mutex_lock(philo->left_chopstick);
		write_action(philo, TOOK);
		pthread_mutex_lock(philo->right_chopstick);
		write_action(philo, TOOK);
	}
	else
	{
		pthread_mutex_lock(philo->right_chopstick);
		write_action(philo, TOOK);
		pthread_mutex_lock(philo->left_chopstick);
		write_action(philo, TOOK);
	}
}

/* ************************************************************************** */

static void	drop_chopsticks(t_philosopher *philo)
{
	if (philo->name % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_chopstick);
		write_action(philo, DROPPED);
		pthread_mutex_unlock(philo->left_chopstick);
		write_action(philo, DROPPED);
	}
	else
	{
		pthread_mutex_unlock(philo->left_chopstick);
		write_action(philo, DROPPED);
		pthread_mutex_unlock(philo->right_chopstick);
		write_action(philo, DROPPED);
	}
}

/* ************************************************************************** */

void	sleep_(t_philosopher *philo)
{
	write_action(philo, SLEEP);
	usleep(philo->table->time_to_sleep * 1000);
}

/* ************************************************************************** */

void	eat(t_philosopher *philo)
{
	take_chopsticks(philo);
	philo->last_meal = get_time();
	philo->meal_count++;
	write_action(philo, EAT);
	usleep(philo->table->time_to_eat * 1000);
	drop_chopsticks(philo);
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
	while (true)
	{
		pthread_mutex_lock(&philo->table->monitor);
		if (philo->table->should_stop)
		{
			pthread_mutex_unlock(&philo->table->monitor);
			break ;
		}
		pthread_mutex_unlock(&philo->table->monitor);
		eat(philo);
		sleep_(philo);
		write_action(philo, THINK);
	}
	return (NULL);
}
