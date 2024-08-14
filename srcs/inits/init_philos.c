/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 00:51:49 by noam              #+#    #+#             */
/*   Updated: 2024/08/12 14:12:35 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

bool	init_philos(t_philosopher **philo, t_table *table,
								pthread_mutex_t **chopsticks)
{
	unsigned int	i;

	i = 0;
	*philo = malloc(table->nb_of_philo * sizeof(t_philosopher));
	if (!(*philo))
		return (false);
	while (i < table->nb_of_philo)
	{
		(*philo)[i].name = i + 1;
		(*philo)[i].left_chopstick = &(*chopsticks)[i];
		(*philo)[i].right_chopstick = &(*chopsticks)[(i + 1) % table->nb_of_philo];
		(*philo)[i].table = table;
		i++;
	}
		// printf("philo numero %d\n philo numero %d\n", philo[0]->name, philo[1]->name);

	return (true);
}
