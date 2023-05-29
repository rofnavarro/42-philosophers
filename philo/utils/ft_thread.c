/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:18 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/28 23:14:37 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	check_full(t_philos	*philos)
{
	int	i;
	int	total_eaten;

	if (philos->data->max_meals != -1)
	{
		i = 0;
		while (i < philos->data->total_philos)
		{
			total_eaten = total_eaten + philos[i].meals_ate;
			i++;
		}
		if (total_eaten == philos->data->max_meals)
			*philos->dead = TRUE;
	}
}

void	check_starvation(t_philos *philos)
{
	int			i;
	long long	time;

	i = 0;
	while (i < philos->data->total_philos)
	{
		time = ft_time() - philos[i].time_last_meal;
		if ((int)time > philos->data->time_to_die)
		{
			print_status(philos, "has died\n");
			*philos->dead = TRUE;
			break ;
		}
		i++;
	}
}

void	is_dead(t_philos *philos)
{
	pthread_mutex_lock(philos->data->death);
	if (philos->data->total_philos == 1)
	{
		ft_sleep(philos->data->time_to_die);
		print_status(philos, "has died\n");
		*philos->dead = TRUE;
		return ;
	}
	check_starvation(philos);
	check_full(philos);
	pthread_mutex_unlock(philos->data->death);
}

void	create_threads(t_data *data, t_philos *philo)
{
	int	i;

	i = -1;
	while (++i < data->total_philos)
		pthread_create(&(philo[i].thread), NULL, &philo_routine, &philo[i]);
	while (*philo->dead == FALSE)
		is_dead(philo);
											printf("\n\n\nchegou aqui\n\n\n");
	i = -1;
	while (++i < data->total_philos)
		pthread_join(philo[i].thread, NULL);
}
