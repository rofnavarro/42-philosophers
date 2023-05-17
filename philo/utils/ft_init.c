/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:34:34 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/17 13:30:54 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	init_data(char **argv, t_program *program)
{
	program->num_of_philos = ft_atol(argv[1]);
	program->time_to_die = ft_atol(argv[2]);
	program->time_to_eat = ft_atol(argv[3]);
	program->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		program->num_of_meals = ft_atol(argv[5]);
	else
		program->num_of_meals = 0;
}

void	init_handler(char **argv, t_program *program)
{
	init_data(argv, program);
	// init_philos(program);
}