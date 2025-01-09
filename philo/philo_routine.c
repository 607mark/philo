/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:32:29 by mshabano          #+#    #+#             */
/*   Updated: 2024/12/20 20:32:31 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ph_think(t_ph *ph, int flag)
{
	if (access_status(0, 0, ph->data) != RUN)
		return (1);
	display_msg(ph, "is thinking");
	if (ph->id % 2 && !flag)
	{
		ms_usleep(ph->data->t_to_eat);
		return 0;
	}
	if (access_status(0, 0, ph->data) != RUN)
		return (1);																														   
	if (ph->data->t_to_think > 0)
		ms_usleep(ph->data->t_to_think);
	return (0);
}
int ph_sleep(t_ph *ph)
{
	if (access_status(0, 0, ph->data) != RUN)
		return (1);
	display_msg(ph, "is sleeping");
	ms_usleep(ph->data->t_to_sleep);
	return (0);
}
void *philo_routine(void *p)
{
	t_ph *ph;
	ph = (t_ph *)p;
	
	wait_sim_to_run(ph->data);
	pthread_mutex_lock(&(ph->mutex));
	ph->last_meal = get_time();
	pthread_mutex_unlock(&(ph->mutex));
	if (ph->id % 2)
		ph_think(ph, 0);
	
	while (access_status(0, 0, ph->data) == RUN)
	{
		// printf("=====%llu time\n", get_time() - ph->last_meal);
		// printf("=====%llu to die\n", ph->data->t_to_die);
		if (ph_eat(ph))
			break;
		if (ph_sleep(ph))
			break;
		if (ph_think(ph, 1))
			break;
	}
	return NULL;
}