/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:52:43 by noam              #+#    #+#             */
/*   Updated: 2024/09/10 17:04:48 by nvoltair         ###   ########.fr       */
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

/* ************************************************************************** */

typedef struct s_table
{
	int							nb_of_philo;
	int							time_to_die;
	int							time_to_eat;
	int							time_to_sleep;
	int							to_satiety;
	pthread_mutex_t				monitor;
	bool						should_stop;

}	t_table;

typedef struct s_philosopher
{
	int							name;
	pthread_t					thread;
	pthread_mutex_t				*first_chopstick;
	pthread_mutex_t				*second_chopstick;
	t_table						*table;
	suseconds_t					last_meal;
	suseconds_t					start_time;
	int							meal_count;
	bool						is_alive;
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

typedef enum e_error
{
	MUTEX_ERROR,
	MALLOC_ERROR,
	THREAD_ERROR,
}	t_error;

/* ************************************************************************** */

unsigned	int	ft_atoui(const char *str);
suseconds_t	get_time(void);

/* ************************************************************************** */

bool		args_valid(int ac, char **av);
bool		init_table(t_table *table, char **av);

bool		init_sticks(pthread_mutex_t **chopsticks, t_table *table);
bool		init_philos(t_philosopher **philo, t_table *table,
					pthread_mutex_t **chopsticks);

/* ************************************************************************** */

bool		a_table(t_philosopher *philos, t_table *table,
					pthread_mutex_t *stick);

void		*diner(void *void_philo);

void		write_action(t_philosopher *philo, t_state state);

/* ************************************************************************** */

void		free_forks(pthread_mutex_t **chopsticks,
					unsigned int nb_of_chopsticks);
int			free_n_exit(t_philosopher *philos, pthread_mutex_t *sticks,
					t_table *table, t_error status);

/* ************************************************************************** */

#endif