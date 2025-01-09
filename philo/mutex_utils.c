/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:08:44 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/09 12:57:45 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_sim_to_run(t_data *data)
{
	while (access_status(0, 0, data) != RUN)
		usleep(100);
}

void	display_msg(t_ph *ph, char *s)
{
	pthread_mutex_lock(&(ph->data->msg_mutex));
	if (access_status(0, 0, ph->data) == RUN)
		printf("%llu %u %s\n", timestamp_in_ms(ph->data), ph->id + 1, s);
	pthread_mutex_unlock(&(ph->data->msg_mutex));
}

t_type	access_status(bool f, t_type type, t_data *d)
{
	t_type	return_value;

	return_value = 0;
	pthread_mutex_lock(&(d->status_mutex));
	if (!f)
		return_value = d->status;
	if (f)
		d->status = type;
	pthread_mutex_unlock(&(d->status_mutex));
	return (return_value);
}
