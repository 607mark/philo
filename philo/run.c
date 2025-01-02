/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:04:38 by mshabano          #+#    #+#             */
/*   Updated: 2024/12/19 19:04:40 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*static int join_simulation_th(t_data *d, pthread_t *th, long long n)
{
    while(--n >= 0)
        pthread_join(th[n], 0);
    if (++n == 0)
        pthread_join(d->monitor, 0);
    else
        return (1);
    return (0);
}
*/
static int create_monitor_th(t_data *d)
{
    if (pthread_create(&(d->monitor), 0, monitor_routine, d))
        return (1);
    printf("monitor created\n");
    return (0);
}
static int create_ph_th(t_ph *ph, pthread_t *th, t_data *d)
{
    unsigned long long n;
    unsigned long long *i;

    i = &(d->n_threads);
    n= d->n_philos;
    while (*i < n)
    {
        if (pthread_create(&(th[*i]), 0, philo_routine, &(ph[*i])))
            return (1);
        else
            (*i)++;
        printf("phino %llu created\n", *i);
    }
    return (0);
}


int run_simulation(t_data *d)
{
    if (create_ph_th(d->philos, d->threads, d))
        return (print_err_return("error creating philo threads\n", 1));
    if (create_monitor_th(d))
        return (print_err_return("error creating monitor thread\n", 1));
    if ((d->t_to_die - d->t_to_eat - d->t_to_sleep) > 0)
        d->t_to_think = (d->t_to_die - d->t_to_eat - d->t_to_sleep) / 2;
     d->t_simulation_start = get_time();
    access_status(1, RUN, d, &(d->main_mutex));
    ms_usleep(10000);
   // if (join_simulation_th(d, d->threads, d->n_threads))
  //      return (print_err_return("error joining threads\n", 1));
    return (0);
}   
