/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:05:24 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/30 14:05:28 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_eat(t_philo *philo)
{
	print_action(philo, "is eating");
	safe_usleep(philo->time_to_eat, philo->data);
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	safe_usleep(philo->time_to_sleep, philo->data);
}

void	philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
	safe_usleep(100, philo->data);
}

void	increment_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->death_mutex);
}

int	handle_forks_and_eat(t_philo *philo)
{
	int	ok;

	if (philo->id % 2 == 0)
		ok = take_forks_even(philo);
	else
		ok = take_forks_odd(philo);
	if (!ok)
		return (0);
	philo_eat(philo);
	return (1);
}
