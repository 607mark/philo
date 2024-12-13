/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:19:19 by mshabano          #+#    #+#             */
/*   Updated: 2024/12/13 23:56:01 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int ac, char **av)
{
	t_main_data data;

	if (init_philos(ac, av, &data))
		return(1);
	
	printf("%ld\n", data.n_philos);
	printf("%ld\n", data.t_to_die);
	printf("%ld\n", data.t_to_eat);
	printf("%ld\n", data.t_to_sleep);
	printf("%ld\n", data.n_t_to_eat);
	return (0);
}
