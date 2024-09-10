/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:27:22 by noam              #+#    #+#             */
/*   Updated: 2024/09/10 13:33:12 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

bool	init_table(t_table *table, char **av)
{
	table->nb_of_philo = ft_atoui(av[1]);
	table->time_to_die = ft_atoui(av[2]);
	table->time_to_eat = ft_atoui(av[3]);
	table->time_to_sleep = ft_atoui(av[4]);
	if (pthread_mutex_init(&table->monitor, NULL) != 0)
		return (free_n_exit(NULL, NULL, NULL, MUTEX_ERROR));
	table->to_satiety = -1;
	if (av[5])
		table->to_satiety = ft_atoui(av[5]);
	if (table->nb_of_philo == 0 || table->to_satiety == 0)
	{
		write(2, "nb_of_philo and nb to_satiety must be > 0\n", 42);
		return (false);
	}
	table->should_stop = false;
	return (true);
}
