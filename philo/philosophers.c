/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:36:47 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/31 16:21:05 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_philos	*philo;

	if (arg_handler(argc, argv) == TRUE)
		return (EXIT_FAILURE);
	data.death = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philo = (t_philos *)malloc(sizeof(t_philos) * ft_atol(argv[1]));
	init_handler(argv, &data, philo);
	create_threads(&data, philo);
	free_handler(&data, philo);
	free(data.death);
	free(philo);
	return (EXIT_SUCCESS);
}
