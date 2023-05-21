/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:18:34 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/20 22:33:02 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	free_philos(t_program *program)
{
	int	i;

	i = -1;
	while (++i < program->num_of_philos)
	{
		free(program->philos[i]->thread);
		pthread_mutex_destroy(program->philos[i]->fork_left);
		free(program->philos[i]->fork_left);
		pthread_mutex_destroy(program->philos[i]->fork_right);
		free(program->philos[i]->fork_right);
		free(program->philos[i]);
	}
	free(program->philos);
}

void	program_mutex_destroy(t_program *program)
{
	pthread_mutex_destroy(&program->mutex_printer);
	pthread_mutex_destroy(&program->mutex_standby);
}

void	free_handler(t_program *program)
{
	free_philos(program);
	program_mutex_destroy(program);
}
