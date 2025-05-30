/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:09:11 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/29 09:35:49 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	print_usage(void)
{
	printf("%sUsage: ./philo <number_of_philosophers> <time_to_die> %s", YELLOW,
		NC);
	printf("%s<time_to_eat> <time_to_sleep>%s ", YELLOW, NC);
	printf("%s[number_of_times_each_philosopher_must_eat]%s\n", YELLOW, NC);
	printf("%sAll arguments must be positive integers!%s\n", YELLOW, NC);
	return (1);
}

static int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!validate_argument(av[i], i))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (print_usage());
	if (!check_args(ac, av))
		return (1);
	if (!init_data(&data, av))
		return (ft_error("Error: Initialization failed\n"));
	if (!create_threads(&data))
	{
		cleanup_data(&data);
		return (ft_error("Error: Thread creation failed\n"));
	}
	join_threads(&data);
	cleanup_data(&data);
	return (0);
}
