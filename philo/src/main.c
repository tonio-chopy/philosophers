/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:09:11 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/06 20:02:26 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_example(void)
{
	printf("%sUsage: ./philo <number_of_philosophers> %s", YELLOW, NC);
	printf("%s<time_to_die> %s", YELLOW, NC);
	printf("%s<time_to_eat> <time_to_sleep>%s ", YELLOW, NC);
	printf("%s[number_of_times_each_philosopher_must_eat]%s\n", YELLOW, NC);
	printf("%sAll arguments must be positive integers!%s\n", YELLOW, NC);
}

int	main(int ac, char **av)
{
	int				i;
	int				nb_philo;
	pthread_t		*philo;
	t_main			*main;
	t_philo			*philo_data;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	int				all_done;
	unsigned long	start_time;

	if (ac != 5 && ac != 6)
	{
		print_example();
		return (1);
	}
	main->i = 1;
	while (main->i < ac)
	{
		if (ft_atoi(av[main->i]) <= 0)
		{
			printf("%sError: All values must be greater than 0.%s\n", YELLOW, NC);
			return (1);
		}
		main->i++;
	}
	main->nb_philo = ft_atoi(av[1]);
	main->philo = malloc(main->nb_philo * sizeof(pthread_t));
	if (!main->philo)
		return (-1);
	main->philo_data = malloc(main->nb_philo * sizeof(t_philo));
	if (!main->philo_data)
	{
		free(main->philo);
		return (-1);
	}
	main->forks = malloc(main->nb_philo * sizeof(pthread_mutex_t));
	if (!main->forks)
	{
		free(main->philo);
		free(main->philo_data);
		return (-1);
	}
	main->i = 0;
	while (main->i < main->nb_philo)
	{
		pthread_mutex_init(&main->forks[main->i], NULL);
		main->i++;
	}
	pthread_mutex_init(&main->print_mutex, NULL);
	main->i = 0;
	main->start_time = get_current_time();
	while (main->i < main->nb_philo)
	{
		philo_data[main->i].id = main->i + 1;
		philo_data[main->i].nb_philo = main->nb_philo;
		philo_data[main->i].time_to_die = ft_atoi(av[2]);
		philo_data[main->i].time_to_eat = ft_atoi(av[3]);
		philo_data[main->i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			philo_data[main->i].nb_times_to_eat = ft_atoi(av[5]);
		else
			philo_data[main->i].nb_times_to_eat = -1;
		philo_data[main->i].forks = main->forks;
		philo_data[main->i].start_time = main->start_time;
		philo_data[main->i].last_meal = main->start_time;
		philo_data[main->i].meals_eaten = 0;
		philo_data[main->i].print_mutex = &main->print_mutex;
		main->i++;
	}
	main->i = 0;
	while (main->i < main->nb_philo)
	{
		if (pthread_create(&main->philo[main->i], NULL, philo_life, &main->philo_data[main->i]) != 0)
			return (ft_free_and_exit(main->philo, philo_data,
					"Error: Thread creation failed\n"));
		main->i++;
	}
	while (1)
	{
		main->all_done = 1;
		main->i = 0;
		while (main->i < main->nb_philo)
		{
			if ((get_current_time() - philo_data[main->i].last_meal)
				> (unsigned long)philo_data[main->i].time_to_die)
			{
				pthread_mutex_lock(&main->print_mutex);
				printf("%s%lu %d died%s\n", BYELLOW,
					get_current_time() - philo_data[main->i].start_time,
					philo_data[main->i].id, NC);
				pthread_mutex_unlock(&main->print_mutex);
				return (ft_free_and_exit(main->philo, philo_data, ""));
			}
			if (philo_data[main->i].nb_times_to_eat != -1 && philo_data[main->i].meals_eaten < philo_data[main->i].nb_times_to_eat)
				main->all_done = 0;
			main->i++;
		}
		if (main->all_done && philo_data[0].nb_times_to_eat != -1)
			break ;
		usleep(10000);
	}
	main->i = 0;
	while (main->i < main->nb_philo)
	{
		pthread_join(main->philo[main->i], NULL);
		main->i++;
	}
	main->i = 0;
	while (main->i < main->nb_philo)
	{
		pthread_mutex_destroy(&forks[main->i]);
		main->i++;
	}
	free(forks);
	ft_free(main->philo, philo_data);
	pthread_mutex_destroy(&main->print_mutex);
	return (0);
}
