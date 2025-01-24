/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:32:29 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/16 18:48:58 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_think(t_ph *ph, int flag)
{
	long long	st;

	if (flag)
		display_msg(ph, "is thinking");
	if (ph->id % 2 && !flag)
	{
		st = get_time();
		while (get_time() - st < ph->data->t_to_eat / 2)
		{
			if (access_status(0, 0, ph->data) != RUN)
				return (1);
			usleep(50);
		}
		return (0);
	}
	return (0);
}

int	ph_sleep(t_ph *ph)
{
	long long	st;

	st = get_time();
	display_msg(ph, "is sleeping");
	while (get_time() - st < ph->data->t_to_sleep)
	{
		if (access_status(0, 0, ph->data) != RUN)
			return (1);
		usleep(50);
	}
	return (0);
}

void	*lonely_philo(t_ph *ph)
{
	pthread_mutex_lock(ph->left);
	display_msg(ph, "has taken a fork");
	pthread_mutex_unlock(ph->left);
	return (0);
}

void	*philo_routine(void *p)
{
	t_ph	*ph;

	ph = (t_ph *)p;
	wait_sim_to_run(ph->data);
	if (ph->data->n_philos == 1)
		return (lonely_philo(ph));
	pthread_mutex_lock(&(ph->mutex));
	ph->last_meal = get_time();
	pthread_mutex_unlock(&(ph->mutex));
	display_msg(ph, "is thinking");
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
		delay(1000);
	}
	return (NULL);
}
