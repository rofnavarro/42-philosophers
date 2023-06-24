/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:36:47 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/24 14:35:39 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_fork		*fork;
	t_data		data;
	t_death		*dead;
	t_philos	*philo;

	if (arg_handler(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fork = init_fork(ft_atol(argv[1]));
	if (!fork)
		return (EXIT_FAILURE);
	data = init_data(argv);
	dead = init_death();
	philo = init_philos(&data, &fork, dead);
	if (create_threads(&philo) == EXIT_FAILURE)
	{
		printf("Failed to create a thread\n");
		return (EXIT_FAILURE);
	}
	free_handler(fork, philo, &data);
	return (EXIT_SUCCESS);
}
