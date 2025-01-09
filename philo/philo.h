/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:28:11 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/09 15:41:52 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "error_messages.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_data	t_data;
typedef enum e_status
{
	INIT,
	RUN,
	INTERRUPT,
}	t_type;

typedef struct s_ph
{
	int					id;
	pthread_t			th;
	bool				dead;
	bool				eating;
	unsigned long long	meals;
	unsigned long long	last_meal;
	pthread_mutex_t		mutex;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	t_data				*data;
}	t_ph;

typedef struct s_data
{
	unsigned long long	n_philos;
	unsigned long long	n_philos_init;
	unsigned long long	t_to_die;
	unsigned long long	t_to_eat;
	unsigned long long	t_to_sleep;
	unsigned long long	n_t_to_eat;
	long long			t_to_think;
	bool				endless;
	t_type				status;
	unsigned long long	t_simulation_start;
	pthread_mutex_t		msg_mutex;
	bool				msg_mutex_init_status;
	pthread_mutex_t		status_mutex;
	bool				status_mutex_init_status;
	pthread_mutex_t		*forks;
	unsigned long long	n_fork_mutex_init;
	t_ph				*philos;
	pthread_t			monitor;
	pthread_t			*threads;
	unsigned long long	n_threads;

}	t_data;

// utils
int					ph_str_to_num(const char *s, unsigned long long *ret);
int					print_err_return(char *s, int r);
int					free_heap_allocated(t_data *data);

// input
int					parse_input(int ac, char **av, t_data *data);
int					validate_input(t_data *data);

// simulation
int					init_simulation(t_data *data);
int					run_simulation(t_data *data);

// mutex utils
void				display_msg(t_ph *ph, char *s);
void				wait_sim_to_run(t_data *data);
t_type				access_status(bool f, t_type type, t_data *d);
//routines
void				*philo_routine(void *p);
void				*monitor_routine(void *p);
int					ph_eat(t_ph *ph);

//time utils
unsigned long long	get_time(void);
int					ms_usleep(unsigned long long ms);
unsigned long long	timestamp_in_ms(t_data *data);

#endif
