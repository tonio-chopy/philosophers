/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:33:32 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/30 17:33:33 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_mutex(t_args *args, pthread_mutex_t *forks)
{
	short int	i;

	i = -1;
	while (++i < args->n)
		pthread_mutex_init(&forks[i], NULL);
	pthread_mutex_init(&args->write_lock, NULL);
	pthread_mutex_init(&args->dead_lock, NULL);
	pthread_mutex_init(&args->eat_lock, NULL);
	pthread_mutex_init(&args->access_lock, NULL);
}

static void	init_remaining(t_philo *philo, t_args *args, short int i)
{
	philo->last_ate = 0;
	philo->meals = 0;
	philo->id = i + 1;
	philo->args = args;
}

void	init_philos(t_philo *philos, t_args *args, pthread_mutex_t *forks)
{
	short int	i;

	i = -1;
	init_mutex(args, forks);
	if (args->n == 1)
	{
		philos[0].fork_r = &forks[0];
		init_remaining(philos, args, 0);
		return ;
	}
	while (++i < args->n)
	{
		if (i < args->n - 1)
		{
			philos[i].fork_r = &forks[i];
			philos[i].fork_l = &forks[i + 1];
		}
		else
		{
			philos[i].fork_l = philos[0].fork_r;
			philos[i].fork_r = philos[i - 1].fork_l;
		}
		init_remaining(&philos[i], args, i);
	}
	args->philos = philos;
}
