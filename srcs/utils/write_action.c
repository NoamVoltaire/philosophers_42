/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:15:34 by noam              #+#    #+#             */
/*   Updated: 2024/09/10 17:26:56 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

#define EAT "is eating 🍥\n"
#define SLEEP "is sleeping 😴\n"
#define THINK "is thinking 🤔\n"
#define DEAD "is dead 😵\n"
#define TOOK "has taken a fork 🍴\n"
#define DROPPED "has dropped a fork 🍴\n"

void	write_action(t_philosopher *philo, t_state state)
{
	suseconds_t	time_mark;
	const char	*action[6] = {EAT, SLEEP, THINK, DEAD, TOOK, DROPPED};

	pthread_mutex_lock(&philo->table->monitor);
	if (philo->table->should_stop)
	{
		pthread_mutex_unlock(&philo->table->monitor);
		return ;
	}
	time_mark = get_time() - philo->start_time;
	printf("%ld %u %s", time_mark, philo->name, action[state]);
	pthread_mutex_unlock(&philo->table->monitor);
}
