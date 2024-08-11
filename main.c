/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:50:34 by noam              #+#    #+#             */
/*   Updated: 2024/08/11 16:56:01 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!(args_valid(argc, argv)) || !(init_table(&table, argv)))
		return (EXIT_FAILURE);
	printf("nb_of_philo: %u\ntime_to_die: %u\ntime_to_eat: %u\ntime_to_sleep: %u\nto_satiety: %u\n",
		table.nb_of_philo, table.time_to_die, table.time_to_eat, table.time_to_sleep, table.to_satiety);
	return (EXIT_SUCCESS);
}