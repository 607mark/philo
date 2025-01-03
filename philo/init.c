/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:44:44 by mshabano          #+#    #+#             */
/*   Updated: 2024/12/19 14:44:48 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int populate_philos(t_data *data)
{
    unsigned long long i;

    data->philos[0].left = &(data->forks[0]);
    if (data->n_philos > 1)
     data->philos[0].right = &(data->forks[data->n_philos - 1]);
    i = 1;
    while(i < data->n_philos - 1)
    {
        data->philos[i].left = &(data->forks[i]);
        data->philos[i].right = &(data->forks[i + 1]);
        i++;
    }
    data->philos[data->n_philos - 1].left = &(data->forks[data->n_philos - 1]);
    if (data->n_philos > 1)
        data->philos[data->n_philos - 1].right = &(data->forks[0]);
    return (0);

}
int init_forks(t_data *data)
{
    unsigned long long i;

    data->forks = malloc(data->n_philos * sizeof(pthread_mutex_t));
    if (!data->forks)
        return (1);
    i = 0;
    while ( i < data->n_philos)
    {
        if (pthread_mutex_init(&(data->forks[i]), NULL))
            return (1);
        i++;
        data->n_fork_mutex_init = i;
    } 
    return (0);
}
int init_philos(t_data *data)
{
   unsigned long long i;
    data->philos = malloc(data->n_philos * sizeof(t_ph));
    if (!data->philos)
        return (1);
    i = 0;
    memset(data->philos, 0, sizeof(t_ph) * data->n_philos);
    while(i < data->n_philos)
    {
        if (pthread_mutex_init(&(data->philos[i].mutex), NULL))
            return (1);
        data->philos[i].id = i;
        data->philos[i].data = (void *)data;
        i++;
    }
    return (0);
}

int malloc_threads(t_data *data)
{
    data->threads = malloc(data->n_philos * sizeof(pthread_t));
    if (!data->threads)
        return (1);
    return (0); 
}

int init_simulation(t_data *data)
{
    if (pthread_mutex_init(&(data->main_mutex), NULL))
            return (1);
    if (pthread_mutex_init(&(data->msg_mutex), NULL))
            return (1);
    if (pthread_mutex_init(&(data->status_mutex), NULL))
            return (1);
    if (init_philos(data))
        return (1);
    if (init_forks((data)))
        return (1);
    if (populate_philos(data))
        return (1);
    if (malloc_threads(data))
        return (1);
    return (0);
}