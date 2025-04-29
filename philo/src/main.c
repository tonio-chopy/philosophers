/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:09:11 by alaualik          #+#    #+#             */
/*   Updated: 2025/04/23 22:06:26 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	int	i;

	if (ac != 6)
	{
		printf("Usage: ./philo <number_of_philosophers> ");
		printf("<time_to_die> <time_to_eat> <time_to_sleep> ");
		printf("<number_of_times_each_philosopher_must_eat>\n");
		printf("All arguments must be positive integers !\n");
		return (1);
	}
	i = 1;
	while (i < 6)
	{
		if (!validate_argument(av[i], i))
			return (1);
		i++;
	}
	return (0);
}
