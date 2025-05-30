/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:03:33 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/30 11:03:31 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	ft_error(char *message)
{
	printf("%s", message);
	return (1);
}

void	safe_usleep(unsigned long duration, t_data *data)
{
	unsigned long	start;
	unsigned long	now;

	start = get_current_time();
	now = start;
	while (!data->simulation_end && now - start < duration)
	{
		usleep(10);
		now = get_current_time();
	}
}

int	safe_mutex_lock(pthread_mutex_t *mutex, t_data *data)
{
	while (!data->simulation_end)
	{
		if (pthread_mutex_trylock(mutex) == 0)
			return (1);
		usleep(10);
	}
	return (0);
}
