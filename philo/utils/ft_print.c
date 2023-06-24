/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:52:57 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/23 16:29:06 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_status(t_philos *philo, char *str, char *collour)
{
	pthread_mutex_lock(philo->print);
	printf("%s%lld %i %s\n", collour, ft_time_diff(philo->data->start, \
			ft_time()), philo->id, str);
	pthread_mutex_unlock(philo->print);
}

void	print_eating(t_philos *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%s%lld %i %s\n", LGREEN, ft_time_diff(philo->data->start, \
			ft_time()), philo->id, "has taken a fork");
	printf("%s%lld %i %s\n", PURPLE, ft_time_diff(philo->data->start, \
			ft_time()), philo->id, "is eating");
	pthread_mutex_unlock(philo->print);
	philo->time_last_meal = ft_time();
}
