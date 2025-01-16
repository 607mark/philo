/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:32:29 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/12 00:17:49 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_think(t_ph *ph, int flag)
{
	display_msg(ph, "is thinking");
	if (ph->id % 2 && !flag)
	{
		ms_usleep(ph->data->t_to_eat);
		return (0);
	}
	return (0);
}

int	ph_sleep(t_ph *ph)
{
	display_msg(ph, "is sleeping");
	ms_usleep(ph->data->t_to_sleep);
	return (0);
}

void	*philo_routine(void *p)
{
	t_ph	*ph;

	ph = (t_ph *)p;
	wait_sim_to_run(ph->data);
	display_msg(ph, "is thinking");
	pthread_mutex_lock(&(ph->mutex));
	ph->last_meal = get_time();
	pthread_mutex_unlock(&(ph->mutex));
	if (ph->id % 2)
		ph_think(ph, 0);
	while (access_status(0, 0, ph->data) == RUN)
	{
		if (ph_eat(ph))
			break ;
		if (ph_sleep(ph))
			break ;
		if (ph_think(ph, 1))
			break ;
	}
	return (NULL);
}
