/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:36:47 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/21 15:08:56 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_philos	*philo;

	if (arg_handler(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data.dead = (int *)malloc(sizeof(int));
	philo = (t_philos *)malloc(sizeof(t_philos) * ft_atol(argv[1]));
	init_handler(argv, &data, philo);
	if (create_threads(&data, philo) == EXIT_FAILURE)
	{
		printf("Failed to create a thread\n");
		return (EXIT_FAILURE);
	}
	free_handler(&data, philo);
	free(philo);
	return (EXIT_SUCCESS);
}
