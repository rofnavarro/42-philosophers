/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:18 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/01 17:52:36 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	create_threads(t_data *data, t_philos *philo)
{
	int	i;

	i = -1;
	while (++i < data->total_philos)
	{
		if (pthread_create(&(philo[i].thread), NULL, &philo_routine, &philo[i]) != 0)
			return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < data->total_philos)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
