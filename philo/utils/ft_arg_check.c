/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:28:30 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/17 12:14:39 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	check_argc(int argc)
{
	if (argc != 5 && argc != 6)
		return (FALSE);
	return (TRUE);
}

static int	check_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (is_int(argv[i]) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

int	arg_handler(int argc, char **argv)
{
	if (check_argc(argc) == FALSE || check_argv(argv) == FALSE)
		return (FALSE);
	return (TRUE);
}
