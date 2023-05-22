/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:38:29 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/21 22:25:54 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*philo_routine(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	while (philo_died(philos) == FALSE)
	{
		if (philos->can_eat == TRUE)

	}
}

static int	philo_died(t_philos *philos)
{
	if (philos->dead == TRUE)
		return (TRUE);
	return (FALSE);
}

void	program_loop(t_philos **philos)
{
	int	i;

	i = -1;
	while (++i < philos[0]->total_of_philos)
		pthread_create(philos[i]->thread, NULL, &philo_routine, \
		(void *)philos[i]);
	i = -1;
	while (++i < philos[0]->total_of_philos)
		pthread_join(philos[i]->thread, NULL);
}
