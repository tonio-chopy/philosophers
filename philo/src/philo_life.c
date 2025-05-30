/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:27:35 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/30 16:38:23 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	handle_one_philo(t_philo *philo)
{
	safe_mutex_lock(philo->left_fork, philo->data);
	print_action(philo, "has taken a fork");
	while (1)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		if (philo->data->simulation_end)
		{
			pthread_mutex_unlock(&philo->data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
		usleep(100);
	}
	pthread_mutex_unlock(philo->left_fork);
}

int	take_forks_even(t_philo *philo)
{
	if (!safe_mutex_lock(philo->right_fork, philo->data))
		return (0);
	print_action(philo, "has taken a fork");
	if (!safe_mutex_lock(philo->left_fork, philo->data))
	{
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->data->death_mutex);
	print_action(philo, "has taken a fork");
	return (1);
}

int	take_forks_odd(t_philo *philo)
{
	if (!safe_mutex_lock(philo->left_fork, philo->data))
		return (0);
	print_action(philo, "has taken a fork");
	if (!safe_mutex_lock(philo->right_fork, philo->data))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->data->death_mutex);
	print_action(philo, "has taken a fork");
	return (1);
}

static int	philo_cycle(t_philo *philo)
{
	if (!handle_forks_and_eat(philo))
		return (0);
	if (philo->data->simulation_end)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	increment_meals(philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo_sleep(philo);
	if (philo->data->simulation_end)
		return (0);
	philo_think(philo);
	if (philo->data->simulation_end)
		return (0);
	return (1);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->nb_philo == 1)
	{
		handle_one_philo(philo);
		return (NULL);
	}
	if (philo->id % 2 != 0)
		safe_usleep(philo->time_to_eat, philo->data);
	while (1)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		if (philo->data->simulation_end || (philo->nb_times_to_eat != -1
				&& philo->meals_eaten >= philo->nb_times_to_eat))
		{
			pthread_mutex_unlock(&philo->data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
		if (!philo_cycle(philo))
			break ;
	}
	return (NULL);
}
