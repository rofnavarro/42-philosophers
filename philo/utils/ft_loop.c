/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:38:29 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/20 23:09:45 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	philo_died(t_program *program)
{
	int	i;

	i = -1;
	while (++i < program->num_of_philos)
	{
		if (program->philos[i]->dead == TRUE)
			return (TRUE);
	}
	return (FALSE);
}

void	program_loop(t_program *program)
{
	while (philo_died(program) == FALSE)
	{
		pthread_
	}
}
