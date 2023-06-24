/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:28:30 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/23 16:14:21 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	check_argc(int argc)
{
	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_argv(char **argv)
{
	int	i;

	i = 0;
	if (ft_atol(argv[1]) == 0 || ft_atol(argv[2]) == 0 || \
		ft_atol(argv[3]) == 0 || ft_atol(argv[4]) == 0)
		return (EXIT_FAILURE);
	while (argv[++i])
	{
		if (is_int(argv[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	arg_handler(int argc, char **argv)
{
	if (check_argc(argc) == EXIT_FAILURE || check_argv(argv) == EXIT_FAILURE)
	{
		printf("Wrong number of arguments or invalid arguments.\n");
		printf("Try: /philos [number_of_philosophers] [time_to_die] ");
		printf("[time_to_eat] [time_to_sleep] ");
		printf("[number_of_times_each_philosopher_must_eat (optional)]\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
