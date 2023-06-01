/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:38:29 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/01 18:55:08 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*philo_routine(void *philo)
{
	t_philos	*philos;

	philos = (t_philos *)philo;
	while (TRUE)
	{
		pthread_mutex_lock(&philos->fork_left);
		print_status(philos, "has taken a fork\n", PURPLE);
		pthread_mutex_lock(philos->fork_right);
		print_status(philos, "has taken a fork\n", ORANGE);
		print_status(philos, "is eating\n", LGREEN);
		ft_sleep(philos->data->time_to_eat);
		philos->time_last_meal = ft_time();
		philos->data->meals_ate++;
		pthread_mutex_unlock(&philos->fork_left);
		pthread_mutex_unlock(philos->fork_right);

		if (philos->data->max_meals != -1)
		{
			pthread_mutex_lock(philos->data->death);
			if (philos->data->meals_ate < philos->data->max_meals);
				pthread_mutex_unlock(philos->data->death);
		}
		ft_sleep(philos->data->time_to_sleep);
		print_status(philos, "is sleeping\n", WHITE);

		print_status(philos, "is thinking\n", CYAN);
	}
	return (NULL);
}
