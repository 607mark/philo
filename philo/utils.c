/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:17:42 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/09 12:36:45 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_heap_allocated(t_data *data)
{
	free(data->forks);
	free(data->philos);
	free(data->threads);
	return (1);
}

static int	num_check(const char *s)
{
	int	i;

	i = 0;
	if (!s || *s == 0)
		return (print_err_return(ERR_INPUT_EMPTY, 1));
	while (*(s + i))
	{
		if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			i++;
			continue ;
		}
		else
			return (print_err_return(ERR_INPUT_NONNUM, 1));
	}
	return (0);
}

int	ph_str_to_num(const char *s, unsigned long long *ret)
{
	unsigned long long	res;

	res = 0;
	if (num_check(s))
		return (1);
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		res = res * 10 + (*(s++) - '0');
		if (res * 10 >= ULLONG_MAX)
			return (print_err_return(ERR_INPUT_BIG, 1));
	}
	*ret = res;
	return (0);
}
