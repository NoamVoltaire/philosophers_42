/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:52:43 by noam              #+#    #+#             */
/*   Updated: 2024/08/12 14:09:05 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

# define ERROR_MESSAGE "Error, should have nb_of_philosophers time_to_die\
 time_to_eat time_to_sleep [nb_of_times_each_philosopher_must_eat] as args\n"
# define ERR_LEN 124

typedef struct s_table
{
	unsigned int				nb_of_philo;
	unsigned int				time_to_die;
	unsigned int				time_to_eat;
	unsigned int				time_to_sleep;
	int							to_satiety;
}	t_table;

typedef struct s_philosopher
{
	int							name;
	pthread_t					thread;
	pthread_mutex_t				*left_chopstick;
	pthread_mutex_t				*right_chopstick;
	t_table						*table;
}	t_philosopher;

typedef enum e_state
{
	EAT,
	SLEEP,
	THINK,
	DEAD,

	TOOK,
	DROPPED,
}	t_state;

bool		args_valid(int ac, char **av);
bool		init_table(t_table *table, char **av);

bool		init_sticks(pthread_mutex_t **chopsticks, t_table *table);
bool		init_philos(t_philosopher **philo, t_table *table,
				pthread_mutex_t **chopsticks);


unsigned	int	ft_atoui(const char *str);


#endif