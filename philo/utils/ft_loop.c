/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:38:29 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/24 15:00:17 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_routine(void *philo)
{
	t_philos	*tmp;
	pthread_t	t;

	tmp = (t_philos *)philo;
	if (tmp->id % 2 == 0)
		
}
