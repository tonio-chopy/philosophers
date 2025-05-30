/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <alaualik@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:02:02 by alaualik          #+#    #+#             */
/*   Updated: 2025/05/30 11:02:08 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_ulitoa(unsigned long n, char *buf)
{
	int	len;

	len = 0;
	if (n >= 10)
		len = ft_ulitoa(n / 10, buf);
	buf[len] = '0' + (n % 10);
	return (len + 1);
}

int	ft_itoa(int n, char *buf)
{
	int	len;

	len = 0;
	if (n >= 10)
		len = ft_itoa(n / 10, buf);
	buf[len] = '0' + (n % 10);
	return (len + 1);
}

void	ft_strcpy(char *dst, char *src, int *i)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dst[*i] = src[j];
		(*i)++;
		j++;
	}
}

void	print_action(t_philo *philo, char *action)
{
	char			buf[64];
	int				i;
	unsigned long	timestamp;

	i = 0;
	pthread_mutex_lock(philo->print_mutex);
	timestamp = get_current_time() - philo->data->start_time;
	i += ft_ulitoa(timestamp, buf + i);
	buf[i++] = ' ';
	i += ft_itoa(philo->id, buf + i);
	buf[i++] = ' ';
	ft_strcpy(buf, action, &i);
	buf[i++] = '\n';
	write(1, buf, i);
	pthread_mutex_unlock(philo->print_mutex);
}
