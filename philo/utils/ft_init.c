/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:34:34 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/21 22:26:54 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	init_data(char **argv, t_philos **philos)
{
	int	i;

	i = -1;
	philos = (t_philos **)malloc(sizeof(t_philos *) * ft_atol(argv[1]));
	while (++i < ft_atol(argv[1]))
	{
		philos[i] = (t_philos*)malloc(sizeof(t_philos));
		philos[i]->total_of_philos = ft_atol(argv[1]);
		philos[i]->num_id = i + 1;
		philos[i]->time_to_die = ft_atol(argv[2]);
		philos[i]->time_to_eat = ft_atol(argv[3]);
		philos[i]->time_to_sleep = ft_atol(argv[4]);
		if (argv[5])
			philos[i]->total_of_meals = ft_atol(argv[5]);
		else
			philos[i]->total_of_meals = 0;
		philos[i]->dead = FALSE;
		philos[i]->can_eat = FALSE;
		philos[i]->thread = malloc(sizeof(pthread_t));
		pthread_mutex_init(&philos[i]->fork_left, NULL);
		pthread_mutex_init(&philos[i]->fork_right, NULL);
		pthread_mutex_init(&philos[i]->mutex_handler, NULL);
		pthread_mutex_init(&philos[i]->mutex_printer, NULL);
	}
}

void	init_handler(char **argv, t_philos **philos)
{
	init_data(argv, philos);
}
