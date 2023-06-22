/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:34:34 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/21 17:03:03 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_philos(t_data *data, t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < data->total_philos)
	{
		philos[i].data = data;
		philos[i].state = HUNGRY;
		philos[i].id = i + 1;
		philos[i].meals_ate = 0;
		philos[i].time_last_meal = ft_time();
		pthread_mutex_init(&philos[i].fork_right, NULL);
		philos[i].fork_left = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		philos[i].fork_left = &philos[((i + philos->data->total_philos - 1) %
									 philos->data->total_philos)].fork_right;
	}
}

void	init_data(char **argv, t_data *data)
{
	data->total_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		data->max_meals = ft_atol(argv[5]);
	else
		data->max_meals = -1;
	data->dead = FALSE;
	data->time_start = ft_time();
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->critical, NULL);
}

void	init_handler(char **argv, t_data *data, t_philos *philo)
{
	init_data(argv, data);
	init_philos(data, philo);
}
