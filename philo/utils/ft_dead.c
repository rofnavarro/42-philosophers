/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:37:42 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/24 13:26:47 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_if_died(t_philos *philo)
{
	int	death;

	pthread_mutex_lock(&philo->dead->mutex_death);
	death = philo->dead->is_dead;
	pthread_mutex_unlock(&philo->dead->mutex_death);
	return (death);
}

int	is_dead(t_philos *philo)
{
	if (check_if_died(philo))
		return (TRUE);
	if (ft_time_diff(philo->time_last_meal, ft_time() - philo->data->start) >= \
		philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->dead->mutex_death);
		philo->dead->is_dead++;
		if (philo->dead->is_dead == 1)
			print_status(philo, "died", RED);
		pthread_mutex_unlock(&philo->dead->mutex_death);
		return (TRUE);
	}
	return (FALSE);
}
