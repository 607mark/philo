/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:18:51 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/09 12:52:45 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_err_return(char *s, int r)
{
	int	i;

	i = 0;
	write(2, "Error: ", 7);
	while (*(s + i))
		i++;
	write(2, s, i);
	write(2, "\n", 1);
	return (r);
}

int	validate_input(t_data *data)
{
	if (data->n_philos < 1)
		return (print_err_return(ERR_TOO_FEW, 1));
	if (data->n_philos > 300)
		return (print_err_return(ERR_TOO_MANY, 1));
	return (0);
}

int	parse_input(int ac, char **av, t_data *data)
{
	memset(data, 0, sizeof(t_data));
	data->status = INIT;
	if (ac < 5 || ac > 6)
		return (print_err_return(ERR_WR_ARGS, 1));
	if (ph_str_to_num(av[1], &(data->n_philos)))
		return (1);
	if (ph_str_to_num(av[2], &(data->t_to_die)))
		return (1);
	if (ph_str_to_num(av[3], &(data->t_to_eat)))
		return (1);
	if (ph_str_to_num(av[4], &(data->t_to_sleep)))
		return (1);
	if (ac == 5)
		data->endless = true;
	else
	{
		data->endless = false;
		if (ph_str_to_num(av[5], &(data->n_t_to_eat)))
			return (1);
	}
	return (0);
}
