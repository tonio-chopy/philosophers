/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:24:28 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/22 12:24:37 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static int	all_philos_ate(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (data->nb_meals != -1
			&& data->philos[i].meals_eaten < data->nb_meals)
		{
			pthread_mutex_unlock(&data->death_mutex);
			return (0);
		}
		pthread_mutex_unlock(&data->death_mutex);
	}
	return (data->nb_meals != -1);
}

static int	check_any_death(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (data->simulation_end)
		{
			pthread_mutex_unlock(&data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->death_mutex);
		if (check_death(&data->philos[i], data))
			return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	usleep(100);
	while (1)
	{
		if (all_philos_ate(data))
		{
			pthread_mutex_lock(&data->death_mutex);
			data->simulation_end = 1;
			pthread_mutex_unlock(&data->death_mutex);
			return (NULL);
		}
		if (check_any_death(data))
			return (NULL);
		usleep(100);
	}
}

int	check_death(t_philo *philo, t_data *data)
{
	unsigned long	time;

	pthread_mutex_lock(&data->death_mutex);
	time = get_current_time();
	if (time - philo->last_meal > (unsigned long)data->time_to_die)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%ld %d died\n", time - data->start_time, philo->id);
		pthread_mutex_unlock(&data->print_mutex);
		data->simulation_end = 1;
		pthread_mutex_unlock(&data->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (0);
}
