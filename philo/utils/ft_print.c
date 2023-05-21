/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:52:57 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/20 23:22:10 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_philo_action(t_program *program, int id, t_actions action)
{
	pthread_mutex_lock(&program->mutex_printer);
	if (action == FORK)
		printf("time %d has taken a fork\n", program->philos[id - 1]->num_id);
	else if (action == EAT)
		printf("time %d is eating\n", program->philos[id - 1]->num_id);
	else if (action == SLEEP)
		printf("time %d is sleeping\n", program->philos[id - 1]->num_id);
	else if (action == THINK)
		printf("time %d is thinking\n", program->philos[id - 1]->num_id);
	else if (action == DIE && program->philos[id - 1]->dead == TRUE)
		printf("time %d died\n", program->philos[id - 1]->num_id);
	pthread_mutex_unlock(&program->mutex_printer);
}
