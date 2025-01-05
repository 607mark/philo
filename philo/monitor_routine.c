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
    t_data *d;
    unsigned long long i;
    bool all_ate_enough;
    
    d = (t_data *)p;
    
    while (access_status(0, 0, d) != RUN)
        usleep(100);    
    while (access_status(0, 0, d) == RUN)
    {
        i = 0;
        all_ate_enough = !d->endless;  
        
        while (i < d->n_philos)
        {
            pthread_mutex_lock(&((d->philos + i)->mutex));
            if ( get_time() - d->philos[i].last_meal > d->t_to_die)
            {
                display_msg(&d->philos[i], "died");
                access_status(1, INTERRUPT, d);
                pthread_mutex_unlock(&((d->philos + i)->mutex));
                return NULL;
            }
            // Check meals if not endless
            if (!d->endless && d->philos[i].meals < d->n_t_to_eat)
                all_ate_enough = false;
            pthread_mutex_unlock(&((d->philos + i)->mutex));
            i++;
        }
        
        // End if all philosophers ate enough
        if (all_ate_enough)
        {
            access_status(1, INTERRUPT, d);
            return NULL;
        }
        
        usleep(100);
    }
    return NULL;
}
