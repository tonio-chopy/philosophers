/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:11:44 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/30 16:00:42 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *nptr)
{
	int	sign;
	int	result;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

static int	ft_skip_spaces_and_sign(const char *str, int *i, int *error)
{
	int	sign;

	sign = 1;
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (!ft_isdigit(str[*i]))
		*error = 1;
	return (sign);
}

int	ft_atoi_error(const char *str, int *error)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	i = 0;
	*error = 0;
	sign = ft_skip_spaces_and_sign(str, &i, error);
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i++] - '0');
		if ((sign == 1 && res > INT_MAX)
			|| (sign == -1 && res > (long)INT_MAX + 1))
			*error = 1;
	}
	return ((int)(res * sign));
}
