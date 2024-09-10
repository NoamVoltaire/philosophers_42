/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:58:54 by nvoltair          #+#    #+#             */
/*   Updated: 2024/09/10 14:01:11 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"
#define MUTEX_ERROR "Error, mutex init failed\n"
#define MALLOC_ERROR "Error, malloc failed\n"
#define THREAD_ERROR "Error, thread creation failed\n"

static inline int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	free_n_exit(t_philosopher *philos, pthread_mutex_t *sticks,
						t_table *table, t_error status)
{
	const char	*error[3] = {MUTEX_ERROR, MALLOC_ERROR, THREAD_ERROR};

	if (sticks)
		free_forks(&sticks, table->nb_of_philo);
	if (philos)
		free(philos);
	if (table)
		pthread_mutex_destroy(&table->monitor);
	if (status)
	{
		write(2, error[status], ft_strlen(error[status]));
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
