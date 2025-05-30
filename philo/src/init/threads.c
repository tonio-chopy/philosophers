/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:21:32 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/22 12:21:47 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	create_threads(t_data *data)
{
	int	i;

	data->threads = malloc(data->nb_philo * sizeof(pthread_t));
	if (!data->threads)
		return (0);
	data->start_time = get_current_time();
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].last_meal = data->start_time;
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->threads[i], NULL, PHILO_ROUTINE,
				&data->philos[i]) != 0)
			return (0);
		i++;
	}
	if (pthread_create(&data->monitor_thread, NULL, monitor_routine, data) != 0)
		return (0);
	return (1);
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
	pthread_join(data->monitor_thread, NULL);
}
