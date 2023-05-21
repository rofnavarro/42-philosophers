/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:38:29 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/21 18:05:10 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*philo_routine(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	while (philo_died(philos) == FALSE)
	{

	}
}

static int	philo_died(t_philos *philos)
{
	if (philos->dead == TRUE)
		return (TRUE);
	return (FALSE);
}

void	program_loop(t_program *program)
{
	int	i;

	i = -1;
	while (++i < program->num_of_philos)
		pthread_create(program->philos[i]->thread, NULL, &philo_routine, \
		(void *)program->philos[i]);
	i = -1;
	while (++i < program->num_of_philos)
		pthread_join(program->philos[i]->thread, NULL);
}
