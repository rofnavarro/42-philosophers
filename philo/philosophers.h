/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:37:14 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/17 12:16:22 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define TRUE 0
# define FALSE 1

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

//  utils/ft_arg_check.c
int			arg_handler(int argc, char **argv);

//  utils/ft_numbers.c
long int	ft_atol(char *argv);
int			is_int(char *argv);

#endif