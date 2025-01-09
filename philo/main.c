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

int destroy_philos_mutexes(t_data *data)
{
	unsigned long long i;

	i = 0;
	if (!data->philos)
		return(0);
	while (i < data->n_philos_init)
	{
		if (pthread_mutex_destroy(&data->philos[i].mutex))
			return (print_err_return("pthread_mutex_destroy(&data->philos[i]->mutex)\n", 1));
		i++;
	}
	return (0);
}

int destroy_forks(t_data *data)
{
	unsigned long long i;
	i = 0;
	if (!data)
		return (0);
	while (i < data->n_fork_mutex_init)
	{
		if (pthread_mutex_destroy(&data->forks[i]))
			return (print_err_return("pthread_mutex_destroy(&data->forks[i])\n", 1));
		i++;
	}
	return (0);
}

int destroy_mutexes(t_data *data)
{
	if (!data)
		return (0);
	if (data->msg_mutex_init_status && pthread_mutex_destroy(&data->msg_mutex))
		return (print_err_return("pthread_mutex_destroy(&data->msg_mutex)\n", 1));
	if (data->status_mutex_init_status && pthread_mutex_destroy(&data->status_mutex))
		return (print_err_return("pthread_mutex_destroy(&data->status_mutex)\n", 1));
	if (destroy_forks(data))
		return (1);
	if (destroy_philos_mutexes(data))
		return (1);
	return (0);
}

int finish_simulation( t_data *data)
{
	destroy_mutexes(data);
	free_heap_allocated(data);
	return (1);
}
int main(int ac, char **av)
{
	t_data data;

	if (parse_input(ac, av, &data))
		return(1);
	if (validate_input(&data))
		return (1);
	if (init_simulation(&data))
		return (finish_simulation(&data));
	if (run_simulation(&data) && finish_simulation(&data))
		return (1);
	finish_simulation(&data);
	return (0);
}
