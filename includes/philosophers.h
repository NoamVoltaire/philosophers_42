/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:52:43 by noam              #+#    #+#             */
/*   Updated: 2024/08/09 19:05:02 by noam             ###   ########.fr       */
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

# define ERROR_MESSAGE "Error, should have nb_of_philosophers time_to_die time_to_eat time_to_sleep [nb_of_times_each_philosopher_must_eat] as args\n"
# define ERR_LEN 124
#endif