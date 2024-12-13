/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:17:42 by mshabano          #+#    #+#             */
/*   Updated: 2024/12/13 23:55:15 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	num_check(const char *s)
{
	int	i;
	
	i = 0;
	if (!s || *s == 0)
		return (print_err_return("input contains empty arguments\n", 1));
	while (*(s + i))
	{
		if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			i++;
			continue;
		}
		else
			return (print_err_return("input contains non-numeric characters\n", 1));
	}
	return (0);
}

int	ph_str_to_num(const char *s, uint64_t *ret)
{
	uint64_t	res;

	res = 0;
	if (num_check(s))
		return (1);
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		res = res * 10 + (*(s++) - '0');
		if (res > 184467440737095516)
			return (print_err_return("too big number in the input\n", 1));
	}
	*ret = res;
	return (0);
}
