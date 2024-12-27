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

int wait_for_threads_creation(t_ph *ph)
{
    while(access_status(0, 0, ph->data) != RUN)
    {
        printf("accessing status\n");
         usleep(50);
    }
       
    return (0);
}
void ph_think(t_ph *ph, int flag)
{
    display_msg(ph, "is thinking");
    if (ph->id % 2 && !flag)
    {
        ms_usleep(1);
        return ;
    }
     
    if (ph->data->t_to_think > 0)
        ms_usleep(ph->data->t_to_think / 2);
}

int ph_eat(t_ph *ph)
{
    display_msg(ph, "is eating");
    ms_usleep(100);
    return (0);
}
int ph_sleep(t_ph *ph)
{
    display_msg(ph, "is sleeping");
    ms_usleep(100);
    return (0);
}
void    *philo_routine(void *p)
{
    t_ph *ph;
    ph = (t_ph *)p;
    wait_for_threads_creation(ph);
    printf("all threads created\n");
    if (ph->id % 2)
        ph_think(ph, 0);
    //while(access_status(0, 0, ph->data) == RUN)
    //{
        if(ph_eat(ph))
            return 0;
        if (ph_sleep(ph))
            return 0;
        ph_think(ph, 1);
  //  }
    return (0);
}