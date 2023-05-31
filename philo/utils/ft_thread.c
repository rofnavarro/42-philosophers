/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:18 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/31 16:23:47 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	create_threads(t_data *data, t_philos *philo)
{
	int	i;

	i = -1;
	while (++i < data->total_philos)
		pthread_create(&(philo[i].thread), NULL, &philo_routine, &philo[i]);
	i = -1;
	while (++i < data->total_philos)
		pthread_join(philo[i].thread, NULL);
}
