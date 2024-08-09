/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:50:34 by noam              #+#    #+#             */
/*   Updated: 2024/08/09 18:05:51 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	main(int argc, char **argv)
{
	if ((args_valid(argc, argv)) && (init_args(argc, argv)))
		return (EXIT_FAILURE);
}