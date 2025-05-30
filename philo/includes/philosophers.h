/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:33:20 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/30 17:33:22 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libs.h"

void	init_philos(t_philo *philos, t_args *args, pthread_mutex_t *forks);

char	not_dead(t_args *args);
void	*life(void *param);

void	create_all_threads(t_philo *philos, t_args *args);

char	check_input(int ac, char **argv, t_args *args);

void	write_error(char *str);
void	ft_usleep(long mls, t_args *args);
void	philo_printf(char *message, t_philo *philo, t_args *args, char force);
long	get_time(void);

void	*watch_philos(void *param);
#endif
