/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:33:47 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/30 17:33:48 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_error(char *str)
{
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
}

void	ft_usleep(long mls, t_args *args)
{
	if (!not_dead(args))
		return ;
	usleep(mls * 1000);
}

void	philo_printf(char *message, t_philo *philo, t_args *args, char force)
{
	long		time;

	if (!not_dead(args) && force == 0)
		return ;
	time = get_time();
	pthread_mutex_lock(&args->access_lock);
	if (args->beginning_time == 0)
		time = 0;
	else
		time -= args->beginning_time;
	pthread_mutex_unlock(&args->access_lock);
	pthread_mutex_lock(&args->write_lock);
	printf("%s%ld%s %d %s\n", YELLOW, time, NO_COLOR, philo->id, message);
	pthread_mutex_unlock(&args->write_lock);
}

long	get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}
