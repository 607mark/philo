/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:39:40 by mshabano          #+#    #+#             */
/*   Updated: 2024/12/20 20:39:42 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long timestamp_in_ms(t_data *data)
{
	return(get_time() - data->t_simulation_start);
}
unsigned long long get_time(void)
{
	struct timeval t;

	memset(&t, 0, sizeof(struct timeval));
	if (gettimeofday(&t, 0) == -1)
		return (print_err_return("gettimeofday() err", 0));
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
} 

int ms_usleep(unsigned long long ms)
{
	unsigned long long st;
	st = get_time();
	while(get_time() - st < ms)
		usleep(500);
	return (1);
}
