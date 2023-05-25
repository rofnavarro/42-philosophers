/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:37:14 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/25 16:29:05 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define TRUE 1
# define FALSE 0

# define INT_MAX 2147483647
# define INT_MIN -2147483648

//  memset()
# include <string.h>

//  printf()
# include <stdio.h>

//  malloc()  free()
# include <stdlib.h>

//  write()  usleep()
# include <unistd.h>

//  gettimeofday()
# include <sys/time.h>

//  pthread_create()  pthread_detach()  pthread_join()  pthread_mutex_init()
//  pthread_mutex_destroy()  pthread_mutex_lock()  pthread_mutex_unlock()
# include <pthread.h>

//  structs
typedef enum e_actions
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_actions;

typedef struct s_data
{
	int					total_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_meals;
	long long			time_start;
	pthread_mutex_t		death;
}	t_data;

typedef struct s_philos
{
	int					id;
	int					*dead;
	int					meals_ate;
	long long			time_last_meal;
	t_data				*data;
	pthread_t			thread;
	pthread_mutex_t		fork_left;
	pthread_mutex_t		*fork_right;
}	t_philos;

//  utils/ft_arg_check.c
int			arg_handler(int argc, char **argv);

//  utils/ft_free.c
void		free_handler(t_data *data, t_philos *philo);

//  utils/ft_init.c
void		init_handler(char **argv, t_data *data, t_philos *philo);

//  utils/ft_loop.c
void		*philo_routine(void *philo);

//  utils/ft_numbers.c
long int	ft_atol(char *argv);
int			not_int(char *argv);

//  utils/ft_thread.c
void		create_threads(t_data *data, t_philos *philo);

//  utils/ft_time.c
long long	ft_time(void);
void		ft_sleep(int miliseconds);

#endif