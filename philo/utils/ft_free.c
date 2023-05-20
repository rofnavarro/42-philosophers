/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:18:34 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/20 13:04:56 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philos_mutex_destroy(t_program *program)
{
	int	i;

	i = -1;
	while (program->philos[i])
	{
		pthread_mutex_destroy(program->philos[i]->fork_left);
		pthread_mutex_destroy(program->philos[i]->fork_right);
	}
}

void	free_philos(t_program *program)
{
	int	i;

	i = -1;
	while (++i < program->num_of_philos)
	{
		free(program->philos[i]->thread);
		free(program->philos[i]->fork_left);
		free(program->philos[i]->fork_right);
		free(program->philos[i]);
	}
	free(program->philos);
}

void	free_handler(t_program *program)
{
	// philos_mutex_destroy(program);
	free_philos(program);
}
