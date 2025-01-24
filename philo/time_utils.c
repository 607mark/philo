/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:39:40 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/09 12:38:57 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	timestamp_in_ms(t_data *data)
{
	return (get_time() - data->t_simulation_start);
}

unsigned long long	get_time(void)
{
	struct timeval	t;

	memset(&t, 0, sizeof(struct timeval));
	if (gettimeofday(&t, 0) == -1)
		return (print_err_return(ERR_GET_TIME, 0));
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
