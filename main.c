/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:50:34 by noam              #+#    #+#             */
/*   Updated: 2024/09/10 14:02:45 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

/*	**********************************************************************	*/

int	main(int argc, char **argv)
{
	t_table			table;
	t_philosopher	*philos;
	pthread_mutex_t	*chopsticks;

	philos = NULL;
	chopsticks = NULL;
	if (!(args_valid(argc, argv)) || !(init_table(&table, argv)))
		return (EXIT_FAILURE);
	if (!(init_sticks(&chopsticks, &table)) || !(init_philos(&philos, &table,
				&chopsticks)))
		return (EXIT_FAILURE);
	if (a_table(philos, &table, chopsticks) == false)
		return (EXIT_FAILURE);
	free_n_exit(philos, chopsticks, &table, 0);
	return (EXIT_SUCCESS);
}

/*	**********************************************************************	*/
