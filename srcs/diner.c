/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:31:40 by noam              #+#    #+#             */
/*   Updated: 2024/09/05 16:31:43 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* ************************************************************************** */

static void	take_chopsticks(t_philosopher *philo)
{

	pthread_mutex_lock(&philo->first_chopstick->mutex);
	write_action(philo, TOOK);
	pthread_mutex_lock(&philo->second_chopstick->mutex);
	write_action(philo, TOOK);
	
}

/* ************************************************************************** */

static void	drop_chopsticks(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->second_chopstick->mutex);
	// write_action(philo, DROPPED);
	pthread_mutex_unlock(&philo->first_chopstick->mutex);
	// write_action(philo, DROPPED);
	// if (philo->name % 2 == 0)
	// {
	// 	pthread_mutex_unlock(&philo->right_chopstick->mutex);
	// 	write_action(philo, DROPPED);
	// 	pthread_mutex_unlock(&philo->left_chopstick->mutex);
	// 	write_action(philo, DROPPED);
	// }
	// else
	// {
	// 	pthread_mutex_unlock(&philo->left_chopstick->mutex);
	// 	write_action(philo, DROPPED);
	// 	pthread_mutex_unlock(&philo->right_chopstick->mutex);
	// 	write_action(philo, DROPPED);
	// }
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
	// usleep(philo->table->time_to_sleep * 1000);
}

/* ************************************************************************** */

void	eat(t_philosopher *philo)
{
	take_chopsticks(philo);
	write_action(philo, EAT);
	u_sleep(philo->table->time_to_eat);
	// usleep(philo->table->time_to_eat * 1000);
	drop_chopsticks(philo);
	philo->meal_count++;
	philo->last_meal = get_time();
}

/* ************************************************************************** */
void	*diner_odd(void *void_philo)
{
	printf("odd\n");
	t_philosopher	*philo;
	double	think_time;
	

	think_time = 0.14159265358979323846264338327950288419716939937510;
	philo = (t_philosopher *)void_philo;
	if (philo->table->nb_of_philo == 1)
	{
		write_action(philo, TOOK);
		return (NULL);
	}
	// if (philo->name % 2)
	// 	u_sleep(10);
	while (true)
	{
		if(get_time()-philo->last_meal > philo->table->time_to_die)
			break;
		
		// pthread_mutex_lock(&philo->table->monitor);
		if (philo->table->should_stop)
		{
			// pthread_mutex_unlock(&philo->table->monitor);
			break ;
		}
		// pthread_mutex_unlock(&philo->table->monitor);

		think_time *= (philo->name) ;
		think_time = think_time - (int)think_time;
		
		
		usleep(think_time * 500);
		
		// if (roundp)
		// {
		// 	if(philo->name % 2)
		// 	{
				eat(philo);
				sleep_(philo);
		// 	}
		// 		else
		// 	{
		// 		write_action(philo, THINK);
		// 		usleep((philo->table->time_to_eat) * 1000 - 3500);
		// 	}
		// }
		
			write_action(philo, THINK);

		// write_action(philo, THINK);
		// roundp = (roundp + 1) % 2; 
	}
	return (NULL);
}

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
		if(get_time()-philo->last_meal > philo->table->time_to_die)
			break;
		
		// pthread_mutex_lock(&philo->table->monitor);
		if (philo->table->should_stop)
		{
			// pthread_mutex_unlock(&philo->table->monitor);
			break ;
		}
		// pthread_mutex_unlock(&philo->table->monitor);
		eat(philo);
		sleep_(philo);
		
		write_action(philo, THINK);
	}
	return (NULL);
}
