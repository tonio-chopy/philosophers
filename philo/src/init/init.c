/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:20:47 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/30 11:05:38 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	init_mutexes(t_data *data)
{
	int	i;

	data->forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (0);
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (0);
	return (1);
}

int	init_philosophers(t_data *data)
{
	int	i;

	data->philos = malloc(data->nb_philo * sizeof(t_philo));
	if (!data->philos)
		return (0);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i] = (t_philo){.id = i + 1, .nb_philo = data->nb_philo,
			.time_to_die = data->time_to_die, .time_to_eat = data->time_to_eat,
			.time_to_sleep = data->time_to_sleep,
			.nb_times_to_eat = data->nb_meals, .data = data,
			.left_fork = &data->forks[i], .right_fork = &data->forks[(i + 1)
			% data->nb_philo], .last_meal = data->start_time, .meals_eaten = 0,
			.print_mutex = &data->print_mutex};
		i++;
	}
	return (1);
}

int	init_data(t_data *data, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->nb_meals = -1;
	if (av[5])
		data->nb_meals = ft_atoi(av[5]);
	if (data->nb_philo <= 0)
		return (ft_error("Error: number_of_philosophers must be > 0\n"));
	if (data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
		return (ft_error("Error: time values must be > 0\n"));
	if (av[5] && data->nb_meals == 0)
		return (ft_error("Error: number_of_eat must be > 0\n"));
	data->simulation_end = 0;
	data->start_time = get_current_time();
	if (!init_mutexes(data) || !init_philosophers(data))
		return (0);
	return (1);
}
