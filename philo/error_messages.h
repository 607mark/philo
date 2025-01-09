/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:24:43 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/09 15:48:57 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H
# define ERR_TOO_FEW "too few philos"
# define ERR_TOO_MANY "too many philos"
# define ERR_WR_ARGS "wrong number of args"
# define ERR_MUTEX_D_PH "pthread_mutex_destroy(&data->philos[i]->mutex)"
# define ERR_MUTEX_D_FORK "pthread_mutex_destroy(&data->forks[i])"
# define ERR_MUTEX_D_MSG "pthread_mutex_destroy(&data->msg_mutex)"
# define ERR_MUTEX_D_STATUS "pthread_mutex_destroy(&data->status_mutex)"
# define ERR_CREAT_PH_THR "error creating philo threads"
# define ERR_CREAT_MON_THR "error creating monitor thread"
# define ERR_JOIN_PH_THR "error joining philosopher thread"
# define ERR_JOIN_MON_THR "error joining monitor thread"
# define ERR_GET_TIME "gettimeofday() err"
# define ERR_INPUT_EMPTY "input contains empty arguments"
# define ERR_INPUT_NONNUM "input contains non-numeric chars"
# define ERR_INPUT_BIG "too big number in the input"
#endif
