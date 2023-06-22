/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:57:38 by rferrero          #+#    #+#             */
/*   Updated: 2023/06/21 18:37:26 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_eating(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->critical);
	philo->state = HUNGRY;
	pthread_mutex_lock(philo->fork_left);
	print_status(philo, "has taken a fork\n", PURPLE);
	pthread_mutex_lock(&philo->fork_right);
	print_status(philo, "has taken a fork\n", ORANGE);
	print_status(philo, "is eating\n", LGREEN);
	ft_sleep(philo->data->time_to_eat);
	philo->time_last_meal = ft_time();
	philo->meals_ate++;
	pthread_mutex_unlock(&philo->data->critical);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(&philo->fork_right);
}

void	ft_sleeping(t_philos *philo)
{
	philo->state = SLEEPING;
	print_status(philo, "is sleeping\n", WHITE);
	ft_sleep(philo->data->time_to_sleep);
}

void	ft_thinking(t_philos *philo)
{
	philo->state = THINKING;
	print_status(philo, "is thinking\n", CYAN);
}

int	check_death(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->death);
	if (philo->data->max_meals != -1)
	{
		if (philo->meals_ate >= philo->data->max_meals)
			return (TRUE);
			
	}
	else
	{
		if (ft_time() - philo->time_last_meal >= philo->data->time_to_die)
			return (TRUE);
	}
	pthread_mutex_unlock(&philo->data->death);
	return (FALSE);
}

void	*philo_routine(void *philos)
{
	t_philos	*philo;

	philo = (t_philos *)philos;
	while (TRUE)
	{
		if (check_death(philo) == FALSE)
		{
			ft_eating(philo);
			ft_sleeping(philo);
			ft_thinking(philo);
		}
	}
}
