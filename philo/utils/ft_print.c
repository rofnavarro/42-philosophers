/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:52:57 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/21 17:05:11 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_status(t_philos *philo, char *status, char *colour)
{
	long long	t;

	pthread_mutex_lock(&philo->data->death);
	t = ft_time() - philo->data->time_start;

	printf("%s%lld %d %s", colour, ft_time() - philo->data->time_start, \
			philo->id, status);
	pthread_mutex_unlock(&philo->data->death);
//	}
//	if (*philo->dead == TRUE)
//		printf("%s%lld %d died\n", RED, ft_time() - philo->data->time_start, \
					philo->id);
}
