/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:18:34 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/24 13:07:43 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	free_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->total_philos)
	{
		pthread_mutex_destroy(&(data->philos[i].fork_left));
		pthread_mutex_destroy(data->philos[i].fork_right);
	}
}

void	free_data(t_data *data)
{
	free(data->philos);
	pthread_mutex_destroy(&(data->print));
	pthread_mutex_destroy(&(data->eat));
	pthread_mutex_destroy(&(data->dead));
}

void	free_handler(t_data *data)
{
	free_philos(data);
	free_data(data);
}
