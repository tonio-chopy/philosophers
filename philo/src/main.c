/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:09:11 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/05 21:08:40 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <pthread.h>

int	main(int ac, char **av)
{
	int				i;
	int				nb_philo;
	pthread_t		*philo;
	t_philo			*philo_data;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	int				all_done;
	unsigned long	start_time;

	if (ac != 5 && ac != 6)
	{
		printf("%sUsage: ./philo <number_of_philosophers> <time_to_die> %s", YELLOW, NC);
		printf("%s<time_to_eat> <time_to_sleep>%s ", YELLOW, NC);
		printf("%s[number_of_times_each_philosopher_must_eat]%s\n", YELLOW, NC);
		printf("%sAll arguments must be positive integers!%s\n", YELLOW, NC);
		return (1);
	}
	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= 0)
		{
			printf("%sError: All values must be greater than 0.%s\n", YELLOW, NC);
			return (1);
		}
		i++;
	}
	nb_philo = ft_atoi(av[1]);
	philo = malloc(nb_philo * sizeof(pthread_t));
	if (!philo)
		return (-1);
	philo_data = malloc(nb_philo * sizeof(t_philo));
	if (!philo_data)
	{
		free(philo);
		return (-1);
	}
	forks = malloc(nb_philo * sizeof(pthread_mutex_t));
	if (!forks)
	{
		free(philo);
		free(philo_data);
		return (-1);
	}
	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&print_mutex, NULL);
	i = 0;
	start_time = get_current_time();
	while (i < nb_philo)
	{
		philo_data[i].id = i + 1;
		philo_data[i].nb_philo = nb_philo;
		philo_data[i].time_to_die = ft_atoi(av[2]);
		philo_data[i].time_to_eat = ft_atoi(av[3]);
		philo_data[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			philo_data[i].nb_times_to_eat = ft_atoi(av[5]);
		else
			philo_data[i].nb_times_to_eat = -1;
		philo_data[i].forks = forks;
		philo_data[i].start_time = start_time;
		philo_data[i].last_meal = start_time;
		philo_data[i].meals_eaten = 0;
		philo_data[i].print_mutex = &print_mutex;
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_create(&philo[i], NULL, philo_life, &philo_data[i]) != 0)
			return (ft_free_and_exit(philo, philo_data,
					"Error: Thread creation failed\n"));
		i++;
	}
	while (1)
	{
		all_done = 1;
		i = 0;
		while (i < nb_philo)
		{
			if ((get_current_time() - philo_data[i].last_meal)
				> (unsigned long)philo_data[i].time_to_die)
			{
				pthread_mutex_lock(&print_mutex);
				printf("%s%lu %d died%s\n", BYELLOW,
					get_current_time() - philo_data[i].start_time,
					philo_data[i].id, NC);
				pthread_mutex_unlock(&print_mutex);
				return (ft_free_and_exit(philo, philo_data, ""));
			}
			if (philo_data[i].nb_times_to_eat != -1 && philo_data[i].meals_eaten < philo_data[i].nb_times_to_eat)
				all_done = 0;
			i++;
		}
		if (all_done && philo_data[0].nb_times_to_eat != -1)
			break ;
		usleep(10000);
	}
	i = 0;
	while (i < nb_philo)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
	ft_free(philo, philo_data);
	pthread_mutex_destroy(&print_mutex);
	return (0);
}
