/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:34:34 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/24 13:11:20 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	init_philos(t_data *data)
{
	int	i;

	data->time_start = time_stamp();
	i = -1;
	while (++i < data->total_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals = 0;
		data->philos[i].can_eat = TRUE;
		data->philos[i].time_last_meal = 0;
		data->philos[i].data = data;
		pthread_create(&(data->philos[i].thread), NULL, &philo_routine, \
						&(data->philos[i]));
		pthread_mutex_init(&(data->philos[i].fork_left), NULL);
		if (i == data->total_philos - 1)
			data->philos[i].fork_right = &(data->philos[0].fork_left);
		else
			data->philos[i].fork_right = &(data->philos[i + 1].fork_left);
	}
	i = -1;
	while (++i < data->total_philos)
		pthread_join(data->philos[i].thread, NULL);
}

static void	init_data(char **argv, t_data *data)
{
	data->total_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		data->max_meals = ft_atol(argv[5]);
	else
		data->max_meals = 0;
	data->meals_ate = 0;
	data->stop = FALSE;
	data->philos = (t_philos *)malloc(sizeof(t_philos) * data->total_philos);
	pthread_mutex_init(&(data->print), NULL);
	pthread_mutex_init(&(data->eat), NULL);
	pthread_mutex_init(&(data->dead), NULL);
}

void	init_handler(char **argv, t_data *data)
{
	init_data(argv, data);
	init_philos(data);
}
