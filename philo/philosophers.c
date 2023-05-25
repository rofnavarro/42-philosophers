/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:36:47 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/25 16:37:10 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_philos	*philo;

	if (arg_handler(argc, argv) == TRUE)
		return (EXIT_FAILURE);
	philo = (t_philos *)malloc(sizeof(t_philos) * ft_atol(argv[1]));
	init_handler(argv, &data, philo);
	create_threads(&data, philo);
	free_handler(&data, philo);
	return (EXIT_SUCCESS);
}
