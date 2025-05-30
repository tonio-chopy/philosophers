/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:13:25 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/30 16:05:51 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define YELLOW "\e[33m"
# define NC "\e[0m"
# define BYELLOW "\e[1;33m"
# define PHILO_ROUTINE philo_life

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
	struct s_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	unsigned long	start_time;
	pthread_t		*threads;
	pthread_t		monitor_thread;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	int				simulation_end;
}					t_data;

// init functions
int					init_mutexes(t_data *data);
int					init_philosophers(t_data *data);
int					init_data(t_data *data, char **av);
int					create_threads(t_data *data);
void				join_threads(t_data *data);
void				cleanup_data(t_data *data);
void				destroy_mutexes(t_data *data);
void				*monitor_routine(void *arg);
int					check_death(t_philo *philo, t_data *data);

int					ft_error(char *message);
unsigned long		get_current_time(void);
void				safe_usleep(unsigned long duration, t_data *data);
int					safe_mutex_lock(pthread_mutex_t *mutex, t_data *data);
int					take_forks_even(t_philo *philo);
int					take_forks_odd(t_philo *philo);

int					ft_atoi(char *nptr);
int					ft_atoi_error(const char *str, int *error);
int					is_valid_number(const char *str);
void				*philo_life(void *arg);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					validate_argument(char *arg, int arg_num);
int					ft_ulitoa(unsigned long n, char *buf);
int					ft_itoa(int n, char *buf);
void				ft_strcpy(char *dst, char *src, int *i);
void				print_action(t_philo *philo, char *action);
void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				philo_think(t_philo *philo);
void				increment_meals(t_philo *philo);
int					handle_forks_and_eat(t_philo *philo);

#endif
