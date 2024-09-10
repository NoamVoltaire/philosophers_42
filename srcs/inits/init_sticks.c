/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sticks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 00:21:59 by noam              #+#    #+#             */
/*   Updated: 2024/09/10 13:41:16 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/* ************************************************************************** */

void	free_forks(pthread_mutex_t **chopsticks, unsigned int nb_of_chopsticks)
{
	unsigned int	i;

	i = 0;
	while (i < nb_of_chopsticks)
	{
		pthread_mutex_destroy(&(*chopsticks)[i]);
		i++;
	}
	free(*chopsticks);
}

/* ************************************************************************** */

bool	init_sticks(pthread_mutex_t **chopsticks, t_table *table)
{
	int	i;

	i = 0;
	*chopsticks = malloc(table->nb_of_philo * sizeof(pthread_mutex_t));
	if (!(*chopsticks))
		return (free_n_exit(NULL, NULL, table, MALLOC_ERROR));
	while (i < table->nb_of_philo)
	{
		if (pthread_mutex_init(&(*chopsticks)[i], NULL) != 0)
			free_n_exit(NULL, *chopsticks, table, MUTEX_ERROR);
		i++;
	}
	return (true);
}
