/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:18:34 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/23 23:59:35 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	free_forks(t_data *data, t_fork **fork)
{
	int	i;

	i = -1;
	while (++i < data->total_philos)
		pthread_mutex_destroy(&(*fork)[i].fork_mutex);
	free(*fork);
}

void	free_handler(t_fork *fork, t_philos *philo, t_data *data)
{
	pthread_mutex_destroy(&(*philo).dead->mutex_death);
	free_forks(data, &fork);
	free(philo);
}
