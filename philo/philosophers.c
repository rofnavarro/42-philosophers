/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:36:47 by rferrero          #+#    #+#             */
/*   Updated: 2023/05/20 12:48:28 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_program	program;
	
	if (arg_handler(argc, argv) == FALSE)
		return (EXIT_FAILURE);
	init_handler(argv, &program);
	for (int i = 0; i < program.num_of_philos; i++){
		printf("Philosopher n: %d", program.philos[i]->num_id);}
	free_handler(&program);
	return (EXIT_SUCCESS);
}
