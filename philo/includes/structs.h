/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:33:26 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/30 17:34:30 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libs.h"

typedef struct s_args	t_args;

typedef struct s_philo
{
	long			last_ate;
	int				meals;
	short int		id;
	pthread_t		thread;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	t_args			*args;
}					t_philo;

typedef struct s_args
{
	char			optional;
	char			dead;
	int				n;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				number_win;
	long			last_meal;
	long			beginning_time;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	access_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_args;

#endif
