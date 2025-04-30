/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:27:35 by alaualik          #+#    #+#             */
/*   Updated: 2025/04/26 16:36:11 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <sys/time.h>

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo =(t_philo *)arg;
	printf("philo %d is thinking...\n", philo->id);
	usleep(philo->time_to_eat * 1000);
	printf("philo %d is eating...\n", philo->id);
	usleep(philo->time_to_sleep * 1000);
	printf("philo %d is sleeping...\n", philo->id);
	return (NULL);
}
