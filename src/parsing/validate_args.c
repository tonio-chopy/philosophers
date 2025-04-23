/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:28:07 by alaualik          #+#    #+#             */
/*   Updated: 2025/04/23 22:09:59 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	validate_argument(char *arg, int arg_num)
{
	int	error;
	int	value;

	value = ft_atoi(arg, &error);
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
