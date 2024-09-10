/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 00:51:49 by noam              #+#    #+#             */
/*   Updated: 2024/09/10 13:42:05 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

bool	init_philos(t_philosopher **philo, t_table *table,
								pthread_mutex_t **chopsticks)
{
	int	i;

	i = -1;
	*philo = malloc(table->nb_of_philo * sizeof(t_philosopher));
	if (!(*philo))
		return (free_n_exit(NULL, *chopsticks, table, MALLOC_ERROR));
	while (++i < table->nb_of_philo)
	{
		(*philo)[i].name = i + 1;
		(*philo)[i].first_chopstick = &(*chopsticks)[i];
		(*philo)[i].second_chopstick = &(*chopsticks)
		[(i + 1) % table->nb_of_philo];
		(*philo)[i].table = table;
		(*philo)[i].last_meal = get_time();
		(*philo)[i].meal_count = 0;
		(*philo)[i].is_alive = true;
	}
	return (true);
}
