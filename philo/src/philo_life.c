/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:27:35 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/05 19:53:56 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <sys/time.h>

static void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->print_mutex);
	printf("%lu %d %s\n",
		get_current_time() - philo->start_time,
		philo->id, action);
	pthread_mutex_unlock(philo->print_mutex);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	int		left;
	int		right;

	philo = (t_philo *)arg;
	left = philo->id - 1;
	right = philo->id % philo->nb_philo;
	while (philo->nb_times_to_eat == -1
		|| philo->meals_eaten < philo->nb_times_to_eat)
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->forks[right]);
			print_action(philo, "has taken a fork");
			pthread_mutex_lock(&philo->forks[left]);
			print_action(philo, "has taken a fork");
		}
		else
		{
			pthread_mutex_lock(&philo->forks[left]);
			print_action(philo, "has taken a fork");
			pthread_mutex_lock(&philo->forks[right]);
			print_action(philo, "has taken a fork");
		}
		philo->last_meal = get_current_time();
		print_action(philo, "is eating");
		usleep(philo->time_to_eat * 1000);
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->forks[left]);
		pthread_mutex_unlock(&philo->forks[right]);
		print_action(philo, "is sleeping");
		usleep(philo->time_to_sleep * 1000);
		print_action(philo, "is thinking");
		usleep(100);
	}
	return (NULL);
}
