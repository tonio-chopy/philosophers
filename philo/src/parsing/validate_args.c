/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:28:07 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/05 21:08:36 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	validate_argument(char *arg, int arg_num)
{
	int	error;
	int	value;

	value = ft_atoi_error(arg, &error);
	if (error)
	{
		printf("Error :argument %d is not a valid integer\n", arg_num);
		return (0);
	}
	if (value < 0)
	{
		printf("Error: argument %d must be greater than 0\n", arg_num);
		return (0);
	}
	return (1);
}

unsigned long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
