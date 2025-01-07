/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:07:21 by mshabano          #+#    #+#             */
/*   Updated: 2024/12/27 19:07:23 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *monitor_routine(void *p)
{
    t_data *d = (t_data *)p;
    unsigned long long i;
    unsigned long long current_time;
    
    while (access_status(0, 0, d) != RUN)
        usleep(100);    
    while (access_status(0, 0, d) == RUN)
    {
        i = 0;  
        current_time = get_time();
        while (i < d->n_philos)
        {
            pthread_mutex_lock(&((d->philos + i)->mutex));
            if (current_time - d->philos[i].last_meal >= d->t_to_die) 
            {
                display_msg(&d->philos[i], "died");
                access_status(1, INTERRUPT, d);
                pthread_mutex_unlock(&((d->philos + i)->mutex));
                return NULL;
            }
            pthread_mutex_unlock(&((d->philos + i)->mutex));
            i++;
        }
        i = 0;
        if (d->endless)
        {
            usleep(50);
            continue;
        }
        while (i < d->n_philos)
        {
            pthread_mutex_lock(&((d->philos + i)->mutex));
            if (!d->endless && d->philos[i].meals < d->n_t_to_eat)
            {
                pthread_mutex_unlock(&((d->philos + i)->mutex));
                break;
            }
            i++;
            pthread_mutex_unlock(&((d->philos + i)->mutex));
        }
        if (i == d->n_philos)
        {
            access_status(1, INTERRUPT, d);
            return NULL;
        }
         usleep(50);
    }
    return NULL;
}
