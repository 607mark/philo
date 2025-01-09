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

int	check_philo_state(t_data *d, int i, unsigned long long *time, bool *a_ate)
{
	pthread_mutex_lock(&(d->philos[i].mutex));
	if (*time - d->philos[i].last_meal >= d->t_to_die)
	{
		display_msg(&d->philos[i], "died");
		access_status(1, INTERRUPT, d);
		pthread_mutex_unlock(&(d->philos[i].mutex));
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
	unsigned long long	current_time;
	bool				all_ate;

	d = (t_data *)p;
	wait_sim_to_run(d);
	while (access_status(0, 0, d) == RUN)
	{
		i = -1;
		all_ate = true;
		current_time = get_time();
		while (++i < d->n_philos && access_status(0, 0, d) == RUN)
		{
			if (check_philo_state(d, i, &current_time, &all_ate))
				break ;
		}
		if (!d->endless && all_ate)
		{
			access_status(1, INTERRUPT, d);
			return (NULL);
		}
		usleep(50);
	}
	return (NULL);
}
