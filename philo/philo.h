/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:13:25 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/05 20:33:59 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define YELLOW "\e[33m"
# define NC "\e[0m"
# define BYELLOW "\e[1;33m"

typedef struct s_philo
{
	int				id;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_to_eat;
	unsigned long	start_time;
	unsigned long	last_meal;
	int				meals_eaten;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_mutex;
}	t_philo;

int				ft_error(char *message);
int				ft_free_and_exit(pthread_t *philo,
					t_philo *philo_data, char *message);
void			ft_free(pthread_t *philo, t_philo *philo_data);
int				ft_validate_args(char **av);
int				ft_is_valid_number(char *str);
unsigned long	get_current_time(void);

int				ft_atoi_error(const char *str, int *error);
int				ft_atoi(const char *nptr);
int				is_valid_number(const char *str);
void			*philo_life(void *arg);
int				ft_isdigit(int c);
int				ft_isspace(int c);
int				check_args(char *arg);
int				validate_argument(char *arg, int arg_num);

#endif
