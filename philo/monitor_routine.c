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
    t_data *data;
    data = (t_data *)p;
    printf("monitor routine here\n");
    p = p;
    ms_usleep(5000);
    access_status(1, INTERRUPT, data, &(data->main_mutex));
    return 0;
}
