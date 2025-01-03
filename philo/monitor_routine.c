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

void    *monitor_routine(void *p)
{
    t_data *d;
    unsigned long long i;
    d = (t_data *)p;
    printf("monitor routine here\n");
    while(access_status(0, 0, d) != RUN)
    {
        printf("hui \n");
         usleep(100);
    }
    while (1)
    {
        i = 0;
        while (i < d->n_philos)
        {
            pthread_mutex_lock(&((d->philos + i)->mutex));
            if (get_time() - ((d->philos + i)->last_meal) > d->t_to_die)
                return((void *)access_status(1, INTERRUPT, d));
            pthread_mutex_unlock(&((d->philos + i)->mutex));
            i++;
        }
    }

    return 0;
}
