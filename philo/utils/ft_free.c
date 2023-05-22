/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:18:34 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/21 22:31:16 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	free_philos(t_philos **philos)
{
	int	i;
	int	total;

	total = philos[0]->total_of_philos;
	i = -1;
	while (++i < total)
	{
		free(philos[i]->thread);
		free(philos[i]);
	}
	free(philos);
}

void	philos_mutex_destroy(t_philos **philos)
{
	int	i;

	i = -1;
	while (++i < philos[0]->total_of_philos)
	{
		pthread_mutex_destroy(&philos[i]->fork_left);
		pthread_mutex_destroy(&philos[i]->fork_right);
		pthread_mutex_destroy(&philos[i]->mutex_handler);
		pthread_mutex_destroy(&philos[i]->mutex_printer);
	}
}

void	free_handler(t_philos **philos)
{
	// philos_mutex_destroy(philos);
	free_philos(philos);
}
