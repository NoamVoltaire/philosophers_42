/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:06:53 by noam              #+#    #+#             */
/*   Updated: 2024/08/11 14:27:03 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static inline bool	is_digit(char a)
{
	if ((a >= '0') && (a <= '9'))
		return (true);
	return (false);
}


static bool	are_digits(char **av)
{
	short	i;
	short	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!is_digit(av[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}


bool	args_valid(int ac, char **av)
{
	if ((ac != 5 && ac != 6) || !are_digits(av))
	{
		write(2, ERROR_MESSAGE, ERR_LEN);
		return (false);
	}
	return (true);
}

/*
int main (int ac, char **av)
{
	// if (ac != 5 && ac != 6)
	// 	printf("Error\n");
	// else
	// 	printf("%d\n", are_digits(av));
	// printf("%d\n", args_valid(ac, av));
	args_valid(ac, av);
	
}
*/