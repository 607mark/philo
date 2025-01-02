/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:32:29 by mshabano          #+#    #+#             */
/*   Updated: 2024/12/20 20:32:31 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void wait_sim_to_run(t_ph *ph)
{
    while(access_status(0, 0, ph->data, &(ph->mutex)) != RUN)
    {
        printf("accessing status\n");
         usleep(50);
    }
}
void ph_think(t_ph *ph, int flag)
{
    display_msg(ph, "is thinking");
    if (ph->id % 2 && !flag)
    {
        ms_usleep(ph->data->t_to_eat + 1);
        return ;
    }                                                                                                                           
    if (ph->data->t_to_think > 0)
        ms_usleep(ph->data->t_to_think);
}

int ph_eat(t_ph *ph)
{
    pthread_mutex_lock(ph->left);
    display_msg(ph, "has taken a fork");
    pthread_mutex_lock(ph->right);
    display_msg(ph, "has taken a fork");
    display_msg(ph, "is eating");
    pthread_mutex_lock(&(ph->mutex));
    ph->last_meal = get_time();
    (ph->meals)++;
    pthread_mutex_unlock(&(ph->mutex));
    ms_usleep(ph->data->t_to_eat);
    pthread_mutex_unlock(ph->left);
    pthread_mutex_unlock(ph->right);
    return (0);
}
int ph_sleep(t_ph *ph)
{
    display_msg(ph, "is sleeping");
    ms_usleep(ph->data->t_to_sleep);
    return (0);
}
void    *philo_routine(void *p)
{
    t_ph *ph;
    ph = (t_ph *)p;
    wait_sim_to_run(ph);
    printf("all threads created\n");
    if (ph->id % 2)
        ph_think(ph, 0);
    ph->last_meal = get_time();
    while(access_status(0, 0, ph->data, &(ph->mutex)) == RUN)
    {
        if(ph_eat(ph))
            return 0;
        if (ph_sleep(ph))
            return 0;
        ph_think(ph, 1);
    }
    return (0);
}