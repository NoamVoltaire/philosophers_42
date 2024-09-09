/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 00:51:49 by noam              #+#    #+#             */
/*   Updated: 2024/09/07 18:32:29 by noam             ###   ########.fr       */
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
		return (false);
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
