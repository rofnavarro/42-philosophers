/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:28:30 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/24 14:42:16 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	check_argc(int argc)
{
	if (argc != 5 && argc != 6)
		return (TRUE);
	return (FALSE);
}

static int	check_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (not_int(argv[i]) == TRUE)
			return (TRUE);
	}
	return (FALSE);
}

int	arg_handler(int argc, char **argv)
{
	if (check_argc(argc) == TRUE || check_argv(argv) == TRUE)
	{
		printf("Wrong number of arguments.\n");
		printf("Try: /philos [number_of_philosophers] [time_to_die] ");
		printf("[time_to_eat] [time_to_sleep] ");
		printf("[number_of_times_each_philosopher_must_eat (optional)]\n");
		return (TRUE);
	}
	return (FALSE);
}
