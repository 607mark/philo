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
	phread_mutex_lock(ph->data->main_mutex);
	if (access_status(ph->data->status == RUN))
		printf("%llu %llu %s", timestamp_in_ms(ph->data->t_simulation_start, ph->id, s));
	phread_mutex_unlock(ph->data->main_mutex);
}
bool access_bool(bool f, bool value, void *p, t_data *d)
{
    bool return_value;

    return_value = 0;
    phread_mutex_lock(d->main_mutex);
	if (!f)
		return_value = *(bool*)p;
	if (f)
		*(bool*)p = value;	
	phtead_mutex_unlock(d->main_mutex);
	return (return_value);
}

t_type access_status(bool f, t_type type, t_data *d)
{
	t_type return_value;

	return_value = 0;
	phread_mutex_lock(d->main_mutex);
	if (!f)
		return_value =d->status;
	if (f)
		d->status = type;	
	phtead_mutex_unlock(d->main_mutex);
	return (return_value);
}