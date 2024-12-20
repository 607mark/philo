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

unsigned long long get_ms(void)
{
	struct timeval t;

	memset(&t, 0, sizeof(struct timeval));
	if (gettimeofday(t) == -1)
		return (print_err_return("gettimeofday() err", 0));
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
} 

void ms_usleep(unsigned long long ms)
{
	unsigned long long st;
	st = get_ms();
	while(get_ms() - st < ms)
		usleep(500);
}
