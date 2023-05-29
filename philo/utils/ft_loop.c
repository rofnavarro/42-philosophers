/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:38:29 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/28 23:07:13 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_eat(t_philos *philos, t_actions *status)
{
	if (*philos->dead == TRUE)
		return (TRUE);
	if (philos->data->total_philos == 1)
	{
		ft_sleep(philos->data->time_to_die);
		*philos->dead = TRUE;
		return (TRUE);
	}
	pthread_mutex_lock(&(philos->fork_left));
	pthread_mutex_lock(philos->fork_right);
	print_status(philos, "has taken a fork\n");
	print_status(philos, "has taken a fork\n");
	print_status(philos, "is eating\n");
	philos->meals_ate++;
	philos->time_last_meal = ft_time();
	pthread_mutex_lock(philos->data->death);
	ft_sleep(philos->data->time_to_eat);
	pthread_mutex_unlock(&(philos->fork_left));
	pthread_mutex_unlock(philos->fork_right);
	pthread_mutex_unlock(philos->data->death);
	return (FALSE);
}

int	ft_sleeping(t_philos *philos, t_actions *status)
{
	print_status(philos, "is sleeping\n");
	ft_sleep(philos->data->time_to_sleep);
	print_status(philos, "is thinking\n");
	return (FALSE);
}

void	*philo_routine(void *philo)
{
	t_philos	*philos;

	philos = (t_philos *)philo;
	while (1)
	{
		if (ft_eat(philos, &philos->status) == TRUE)
			break ;
		if (ft_sleeping(philos, &philos->status) == TRUE)
			break ;
		if (*philos->dead == TRUE)
			break ;
	}
	return (NULL);
}
