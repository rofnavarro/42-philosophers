/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:34:34 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/20 13:59:22 by rferrero         ###   ########.fr       */
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
	pthread_mutex_init(&program->mutex_printer, NULL);
	pthread_mutex_init(&program->mutex_standby, NULL);
}

void	init_philos(t_program *program)
{
	int	i;

	program->philos = (t_philos **)malloc(sizeof(t_philos *) * \
						program->num_of_philos);
	i = -1;
	while (++i < program->num_of_philos)
	{
		program->philos[i] = (t_philos *)malloc(sizeof(t_philos));
		program->philos[i]->num_id = i + 1;
		program->philos[i]->meals = program->num_of_meals;
		program->philos[i]->dead = FALSE;
		program->philos[i]->can_eat = TRUE;
		program->philos[i]->thread = malloc(sizeof(pthread_t));
		program->philos[i]->fork_left = malloc(sizeof(pthread_mutex_t));
		program->philos[i]->fork_right = malloc(sizeof(pthread_mutex_t));
	}
	i = -1;
	while (++i < program->num_of_philos)
	{
		pthread_mutex_init(program->philos[i]->fork_left, NULL);
		pthread_mutex_init(program->philos[i]->fork_right, NULL);
	}
}

void	init_handler(char **argv, t_program *program)
{
	init_data(argv, program);
	init_philos(program);
}
