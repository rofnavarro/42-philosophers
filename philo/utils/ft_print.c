/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:52:57 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/31 16:18:10 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_status(t_philos *philo, char *status)
{
	long long	t;

	pthread_mutex_lock(philo->data->death);
	t = ft_time() - philo->data->time_start;
	if (*philo->dead == FALSE)
	{
		printf("%lld %d %s", ft_time() - philo->data->time_start, \
					philo->id, status);
		pthread_mutex_unlock(philo->data->death);
	}
	else
		printf("%lld %d died\n", ft_time() - philo->data->time_start, \
					philo->id);
}
