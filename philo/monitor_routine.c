/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:07:21 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/18 23:27:52 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_state(t_data *d, int i, bool *a_ate)
{
	pthread_mutex_lock(&(d->philos[i].mutex));
	if (get_time() - d->philos[i].last_meal > d->t_to_die)
	{
		access_status(1, INTERRUPT, d);
		pthread_mutex_lock(&(d->msg_mutex));
		printf("%llu %u %s\n", timestamp_in_ms(d), d->philos[i].id, "died");
		pthread_mutex_unlock(&(d->philos[i].mutex));
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
	usleep(500);
	while (1)
	{
		delay(1000);
		usleep(500);
		i = -1;
		all_ate = true;
		while (++i < d->n_philos)
		{
			if (check_philo_state(d, i, &all_ate))
				return (NULL);
		}
		if (!d->endless && all_ate)
		{
			access_status(1, INTERRUPT, d);
			return (NULL);
		}
	}
	return (NULL);
}
