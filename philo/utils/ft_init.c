/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:34:34 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/24 15:15:10 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_fork	*init_fork(int size)
{
	int		i;
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork) * size);
	if (!fork)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		fork[i].fork = 1;
		pthread_mutex_init(&fork[i].fork_mutex, NULL);
	}
	return (fork);
}

t_philos	*init_philos(t_data *data, t_fork **forks, t_death *dead)
{
	int			i;
	t_philos	*philos;

	philos = (t_philos *)malloc(sizeof(t_philos) * data->total_philos);
	i = -1;
	while (++i < data->total_philos)
	{
		philos[i].data = *data;
		philos[i].id = i + 1;
		philos[i].meals_ate = 0;
		philos[i].fork = *forks;
		philos[i].dead = dead;
	}
	return (philos);
}

t_death	*init_death(void)
{
	static t_death	dead;

	dead.is_dead = FALSE;
	pthread_mutex_init(&dead.mutex_death, NULL);
	return (&dead);
}

t_data	init_data(char **argv)
{
	t_data	data;

	data.total_philos = ft_atol(argv[1]);
	data.time_to_die = ft_atol(argv[2]);
	data.time_to_eat = ft_atol(argv[3]);
	data.time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		data.max_meals = ft_atol(argv[5]);
	else
		data.max_meals = -1;
	return (data);
}
