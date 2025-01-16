/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:07:21 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/09 12:44:30 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_state(t_data *d, int i, bool *a_ate)
{
	pthread_mutex_lock(&(d->philos[i].mutex));
	if (get_time() - d->philos[i].last_meal > d->t_to_die)
	{
		pthread_mutex_lock(&(d->msg_mutex));
		access_status(1, INTERRUPT, d);
		printf("%llu %u %s\n", timestamp_in_ms(d), d->philos[i].id, "died");
		pthread_mutex_unlock(&(d->philos[i].mutex));
		usleep(500);
		pthread_mutex_unlock(&(d->msg_mutex));
		return (1);
	}
	if (!d->endless && d->philos[i].meals < d->n_t_to_eat)
		*a_ate = false;
	pthread_mutex_unlock(&(d->philos[i].mutex));
	return (0);
}

void	*monitor_routine(void *p)
{
	t_data				*d;
	unsigned long long	i;
	bool				all_ate;

	d = (t_data *)p;
	wait_sim_to_run(d);
	while (1)
	{
		i = -1;
		all_ate = true;
		while (++i < d->n_philos)
		{
			if (check_philo_state(d, i, &all_ate))
				return (NULL);
			usleep(100);
		}
		if (!d->endless && all_ate)
		{
			access_status(1, INTERRUPT, d);
			return (NULL);
		}
	}
	return (NULL);
}
