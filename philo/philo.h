/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:13:25 by alaualik          #+#    #+#             */
/*   Updated: 2025/04/23 21:51:00 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>

// utils
int	ft_atoi(const char *str, int *error);
int	is_valid_number(const char *str);
int	ft_isdigit(int c);
int	ft_isspace(int c);
int	check_args(char *arg);
int	validate_argument(char *arg, int arg_num);

#endif
