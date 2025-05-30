/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:33:43 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/30 17:33:45 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	only_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = -1;
	while (argv[i])
	{
		while (argv[i][++j])
		{
			if (argv[i][0] == '-')
				return (2);
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (FALSE);
		}
		j = -1;
		i++;
	}
	return (TRUE);
}

static int	ft_atoi(char *str)
{
	int	num;
	int	i;
	int	sign;

	num = 0;
	i = 0;
	sign = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num *= 10;
		num += (int)(str[i] - '0');
		i++;
	}
	if (sign == 1)
		return (-num);
	return (num);
}

static char	store_args(int ac, char **argv, t_args *args)
{
	args->optional = 0;
	args->dead = 0;
	args->n = ft_atoi(argv[1]);
	args->time_die = ft_atoi(argv[2]);
	args->time_eat = ft_atoi(argv[3]);
	args->time_sleep = ft_atoi(argv[4]);
	if (ac == 6)
	{
		args->number_win = ft_atoi(argv[5]);
		args->optional = 1;
	}
	args->dead = 0;
	args->beginning_time = 0;
	return (TRUE);
}

char	check_input(int ac, char **argv, t_args *args)
{
	char	error_code;

	error_code = only_digits(argv);
	if (error_code == FALSE)
		return (write_error("Error\nOnly digits are allowed."), FALSE);
	else if (error_code == 2)
		return (write_error("Error\nOnly positive numbers are allowed."),
			FALSE);
	if (store_args(ac, argv, args) == FALSE)
		return (write_error("Error\nIssue with the arguments."), FALSE);
	if (args->n == 0)
		return (write_error("Error\nNo philosophers."), FALSE);
	if (args->n > 200)
		return (write_error("Error\nMore than 200 philosophers."), FALSE);
	return (TRUE);
}
