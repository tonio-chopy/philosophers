/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:03:33 by alaualik          #+#    #+#             */
/*   Updated: 2025/04/26 17:22:49 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	ft_error(char *message)
{
	printf("%s", message);
	return (1);
}

int	ft_free_and_exit(pthread_t *philo, t_philo *philo_data, char *message)
{
	if (philo)
		free(philo);
	if (philo_data)
		free(philo_data);
	return (ft_error(message));
}

void	ft_free(pthread_t *philo, t_philo *philo_data)
{
	if (philo)
		free(philo);
	if (philo_data)
		free(philo_data);
}

int	ft_validate_args(char **av)
{
    int	i;

    i = 1;
    while (av[i])
    {
        if (!ft_is_valid_number(av[i]))
            return (0);
        i++;
    }
    return (1);
}

int	ft_is_valid_number(char *str)
{
    int	i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
