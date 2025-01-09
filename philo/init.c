/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:44:44 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/09 15:54:46 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	populate_philos(t_data *d)
{
	unsigned long long	i;

	i = 0;
	while (i < d->n_philos - 1)
	{
		d->philos[i].left = &(d->forks[i]);
		d->philos[i].right = &(d->forks[i + 1]);
		i++;
	}
	if (d->n_philos > 1)
		d->philos[d->n_philos - 1].right = &(d->forks[d->n_philos - 1]);
	d->philos[d->n_philos - 1].left = &(d->forks[0]);
	return (0);
}

int	init_forks(t_data *d)
{
	unsigned long long	i;

	d->forks = malloc(d->n_philos * sizeof(pthread_mutex_t));
	if (!d->forks)
		return (1);
	i = 0;
	while (i < d->n_philos)
	{
		if (pthread_mutex_init(&(d->forks[i]), NULL))
			return (1);
		i++;
		d->n_fork_mutex_init = i;
	}
	return (0);
}

int	init_philos(t_data *d)
{
	unsigned long long	i;

	d->philos = malloc(d->n_philos * sizeof(t_ph));
	if (!d->philos)
		return (1);
	i = 0;
	memset(d->philos, 0, sizeof(t_ph) * d->n_philos);
	while (i < d->n_philos)
	{
		if (pthread_mutex_init(&(d->philos[i].mutex), NULL))
			return (1);
		d->philos[i].id = i;
		d->philos[i].data = (void *)d;
		d->philos[i].last_meal = get_time();
		i++;
		d->n_philos_init = i;
	}
	return (0);
}

int	malloc_threads(t_data *d)
{
	d->threads = malloc(d->n_philos * sizeof(pthread_t));
	if (!d->threads)
		return (1);
	return (0);
}

int	init_simulation(t_data *d)
{
	if (pthread_mutex_init(&(d->msg_mutex), NULL))
		return (1);
	else
		d->msg_mutex_init_status = true;
	if (pthread_mutex_init(&(d->status_mutex), NULL))
		return (1);
	else
		d->status_mutex_init_status = true;
	if (init_philos(d))
		return (1);
	if (init_forks((d)))
		return (1);
	if (populate_philos(d))
		return (1);
	if (malloc_threads(d))
		return (1);
	return (0);
}
