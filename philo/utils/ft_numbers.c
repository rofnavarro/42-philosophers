/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:05:05 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/17 12:16:37 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == 45)
		i++;
	while (argv[i] != '\0')
	{
		if (argv[i] < 48 || argv[i] > 57)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

long int	ft_atol(char *argv)
{
	long int	number;
	int			i;
	int			signal;

	signal = 1;
	i = 0;
	number = 0;
	while (argv[i] >= 9 && argv[i] <= 13 || argv[i] == 32)
		i++;
	if (argv[i] == 43 || argv[i] == 45)
	{
		if (argv[i] == 45)
			signal *= -1;
	}
	while (argv[i] >= 48 && argv[i] <= 57)
	{
		number = (number * 10) + (argv[i] - 48);
		i++;
	}
	return (number * signal);
}

int	is_int(char *argv)
{
	long int	arg;

	if (is_number(argv) == FALSE)
		return (FALSE);
	arg = ft_atol(argv);
	if (arg > INT_MAX || arg < 0)
		return (FALSE);
	return (TRUE);
}
