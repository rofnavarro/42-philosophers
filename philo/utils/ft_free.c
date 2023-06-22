/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:18:34 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/21 17:01:14 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	free_philos(t_data *data, t_philos *philo)
{
	int	i;

	i = -1;
	while (++i < data->total_philos)
	{
		pthread_mutex_destroy(&philo[i].fork_right);
		free(philo[i].fork_left);
	}
}

static void	free_data(t_data *data)
{
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->critical);
}

void	free_handler(t_data *data, t_philos *philo)
{
	free_philos(data, philo);
	free_data(data);
}
