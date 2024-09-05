/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sticks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 00:21:59 by noam              #+#    #+#             */
/*   Updated: 2024/09/02 00:07:17 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

// void	free_forks(pthread_mutex_t **chopsticks, unsigned int nb_of_chopsticks)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (i < nb_of_chopsticks)
// 	{
// 		pthread_mutex_destroy(chopsticks[i]);
// 		i++;
// 	}
// 	free(*chopsticks);
// }

// bool	init_sticks(pthread_mutex_t **chopsticks, t_table *table)
// {
// 	// pthread_mutex_t	*chopsticks;
// 	unsigned int	i;

// 	i = 0;
// 	*chopsticks = malloc(table->nb_of_philo * sizeof(pthread_mutex_t));
// 	if (!(*chopsticks))
// 		return (false);
// 	while (i < table->nb_of_philo)
// 	{
// 		if (pthread_mutex_init(&(*chopsticks)[i], NULL) != 0)
// 		{
// 			free_forks(&(*chopsticks), i);
// 			return (false);
// 		}
// 		i++;
// 	}
// 	return (true);
// }

void	free_forks(t_cutlery **chopsticks, unsigned int nb_of_chopsticks)
{
	unsigned int	i;

	i = 0;
	while (i < nb_of_chopsticks)
	{
		pthread_mutex_destroy(&(*chopsticks)[i].mutex);
		i++;
	}
	free(*chopsticks);
}

bool	init_sticks(t_cutlery **chopsticks, t_table *table)
{
	// pthread_mutex_t	*chopsticks;
	int	i;

	i = 0;
	*chopsticks = malloc(table->nb_of_philo * sizeof(t_cutlery));
	if (!(*chopsticks))
		return (false);
	while (i < table->nb_of_philo)
	{		
		if (pthread_mutex_init(&(*chopsticks)[i].mutex, NULL) != 0)
		{
			free_forks(&(*chopsticks), i);
			return (false);	
		}
		(*chopsticks)[i].is_locked = false;

		
		// {
		// 	free_forks(&(*chopsticks), i);
		// 	return (false);
		// }
		i++;
	}
	return (true);
}
