/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:50:34 by noam              #+#    #+#             */
/*   Updated: 2024/08/14 19:30:17 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

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
	printf("philo numero %d\n philo numero %d\n", philos[0].name, philos[1].name);
	/*
	**	Here we will create the threads and start the simulation of the philosophers with
	**	a while loop that will check if the philosophers are alive and if they are not
	**	satiated or if they have not died of hunger.
	**  all of this with the help of the functions get_time() and usleep()
	
	*/		
	// printf("nb_of_philo: %u\ntime_to_die: %u\ntime_to_eat: %u\ntime_to_sleep: %u\nto_satiety: %u\n",
		// table.nb_of_philo, table.time_to_die, table.time_to_eat, table.time_to_sleep, table.to_satiety);
	return (EXIT_SUCCESS);
}