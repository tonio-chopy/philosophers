/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:27:35 by alaualik          #+#    #+#             */
/*   Updated: 2025/04/30 10:47:07 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <sys/time.h>

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("%sphilo %d is thinking...%s\n",YELLOW ,philo->id ,NC);
	usleep(philo->time_to_eat * 1000);
	printf("%sphilo %d is eating...%s\n",BYELLOW, philo->id, NC);
	usleep(philo->time_to_sleep * 1000);
	printf("%sphilo %d is sleeping...%s\n",YELLOW, philo->id, NC);
	return (NULL);
}
