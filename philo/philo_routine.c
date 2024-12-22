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
        usleep(50);
    return (1);
}
void ph_think(t_ph *ph, int flag)
{
    unsigned long long t_t_think;

    t_t_think = 0;
    if (p->id % 2 && !flag)
    {
        display_msg(ph, char "is thinking");
        return (ms_usleep(1));
    }
    t_t_think = ph->t_to_die - ph->t_to_eat - ph->t_to_sleep;
    ms_usleep(t_t_think / 2);
}

int ph_eat(t_ph *ph)
{

}
int ph_sleep(t_ph *ph)
{
    
}
void    *philo_routine(void *p)
{
    t_ph *ph;
    
    ph = (t_ph *)p;
    wait_for_threads_creation(ph);
    if (ph->id % 2)
        ph_think(ph, 0);
    while(access_status(0, 0, ph->data) == RUN)
    {
        if(ph_eat(ph))
            return ;
        if (ph_sleep(ph))
            return ;
        ph_think(ph);
    }

}