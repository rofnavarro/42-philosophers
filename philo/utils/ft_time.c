/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:48:50 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/24 13:48:47 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	ft_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	ft_time_diff(long long start, long long last)
{
	return (last - start);
}

int	psleep(t_philos *philo, int sleep_time)
{
	long long	start;
	long long	passed;

	start = ft_time();
	passed = 0;
	while (!is_dead(philo) && passed < sleep_time)
	{
		if (check_if_died(philo))
			return (TRUE);
		usleep(2000);
		passed = ft_time_diff(start, ft_time());
	}
	return (passed >= sleep_time);
}
