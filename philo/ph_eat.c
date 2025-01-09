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
	pthread_mutex_unlock(ph->left);
	pthread_mutex_unlock(ph->right);
	return (0);
}

int	lock_forks(t_ph *ph)
{
	usleep(20);
	pthread_mutex_lock(ph->left);
	display_msg(ph, "has taken a fork");
	if (ph->data->n_philos > 1)
		pthread_mutex_lock(ph->right);
	else
	{
		pthread_mutex_unlock(ph->left);
		return (1);
	}
	display_msg(ph, "has taken a fork");
	return (0);
}

int	ph_eat(t_ph *ph)
{
	if (lock_forks(ph))
		return (1);
	display_msg(ph, "is eating");
	pthread_mutex_lock(&(ph->mutex));
	ph->last_meal = get_time();
	(ph->meals)++;
	pthread_mutex_unlock(&(ph->mutex));
	if (access_status(0, 0, ph->data) != RUN)
	{
		unlock_forks(ph);
		return (1);
	}
	ms_usleep(ph->data->t_to_eat);
	unlock_forks(ph);
	return (0);
}
