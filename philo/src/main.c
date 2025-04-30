/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:09:11 by alaualik          #+#    #+#             */
/*   Updated: 2025/04/30 10:10:09 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <pthread.h>

int	main(int ac, char **av)
{
	int			i;
	int			nb_philo;
	pthread_t	*philo;
	t_philo		*philo_data;

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
	i = 0;
	nb_philo = ft_atoi(av[1]);
	philo = malloc(nb_philo * sizeof(pthread_t));
	if (!philo)
		return (-1);
	philo_data = malloc(nb_philo * sizeof(t_philo));
	if (!philo_data)
		return (-1);
	while (i < nb_philo)
	{
		if (pthread_create(&philo[i], NULL, philo_life, &philo_data[i]) != 0)
			return (ft_free_and_exit(philo,
					philo_data, "Error: Thread creation failed\n"));
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	ft_free(philo, philo_data);
	return (0);
}
