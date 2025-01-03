/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:08:44 by mshabano          #+#    #+#             */
/*   Updated: 2024/12/20 16:08:45 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void display_msg(t_ph *ph, char *s)
{
	pthread_mutex_lock(&(ph->mutex));
	if (ph->data->status == RUN)
		printf("%llu %u %s\n", timestamp_in_ms(ph->data), ph->id, s);
	pthread_mutex_unlock(&(ph->mutex));
}
bool access_bool(bool f, bool value, void *p, pthread_mutex_t *mutex)
{
    bool return_value;

    return_value = 0;
    pthread_mutex_lock(mutex);
	if (!f)
		return_value = *(bool*)p;
	if (f)
		*(bool*)p = value;	
	pthread_mutex_unlock(mutex);
	return (return_value);
}

t_type access_status(bool f, t_type type, t_data *d, pthread_mutex_t *mutex)
{
	t_type return_value;

	return_value = 0;
	pthread_mutex_lock(mutex);
	if (!f)
		return_value =d->status;
	if (f)
		d->status = type;	
	pthread_mutex_unlock(mutex);
	return (return_value);
}