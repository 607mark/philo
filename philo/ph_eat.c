/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:56:23 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/09 12:39:53 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	unlock_forks(t_ph *ph)
{
	if (ph->id % 2)
	{
		pthread_mutex_unlock(ph->right);
		pthread_mutex_unlock(ph->left);
	}
	else
	{
		pthread_mutex_unlock(ph->left);
		pthread_mutex_unlock(ph->right);
	}
	return (1);
}

int	lock_forks(t_ph *ph)
{
	if (ph->id % 2)
	{
		pthread_mutex_lock(ph->right);
		display_msg(ph, "has taken a fork");
		pthread_mutex_lock(ph->left);
		display_msg(ph, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(ph->left);
		display_msg(ph, "has taken a fork");
		pthread_mutex_lock(ph->right);
		display_msg(ph, "has taken a fork");
	}
	return (0);
}

int	ph_eat(t_ph *ph)
{
	long long	st;

	int i = 0;
	lock_forks(ph);
	st = get_time();
	pthread_mutex_lock(&(ph->mutex));
	ph->last_meal = get_time();
	pthread_mutex_unlock(&(ph->mutex));
	display_msg(ph, "is eating");
	while (get_time() - st < ph->data->t_to_eat)
	{
		if (!(i % 10) && access_status(0, 0, ph->data) != RUN)
			return (unlock_forks(ph));
		usleep(50);
		i++;
	}
	pthread_mutex_lock(&(ph->mutex));
	(ph->meals)++;
	pthread_mutex_unlock(&(ph->mutex));
	unlock_forks(ph);
	return (0);
}
