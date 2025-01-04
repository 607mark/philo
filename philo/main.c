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

void print_util(t_data *data)
{
	unsigned long long i = 0;
	while(i < data->n_philos)
	{
		printf("philo #%d has:\n", data->philos[i].id);
		printf("left fork:%p\n", data->philos[i].left);
		printf("right fork:%p\n", data->philos[i].right);
		i++;
	}
}

int finish_simulation( t_data *data)
{
	free_heap_allocated(data);
	return (1);
}
int main(int ac, char **av)
{
	t_data data;

	if (parse_input(ac, av, &data))
		return(1);
	printf("%lld\n", data.n_philos);
	printf("%lld\n", data.t_to_die);
	printf("%lld\n", data.t_to_eat);
	printf("%lld\n", data.t_to_sleep);
	printf("%lld\n", data.n_t_to_eat);
	if (validate_input(&data))
		return (1);
	if (init_simulation(&data))
		return (free_heap_allocated(&data));
	if (run_simulation(&data) && finish_simulation(&data))
		return (1);
	finish_simulation(&data);
	






	/*
	print_util(&data);
	
	*/
	
	
	return (0);
}
