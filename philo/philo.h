#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>


typedef struct s_ph
{
	pthread_t th;
	int	id;
	bool	dead;
	bool	eating;
	int	meals;
	uint64_t init_time;
	uint64_t eat_time;
} t_ph;

typedef struct s_main_data
{
	uint64_t	n_philos;
	uint64_t	t_to_die;
	uint64_t	t_to_eat;
	uint64_t	t_to_sleep;
	uint64_t	n_t_to_eat;
	bool	endless;
	bool	dead;
	t_ph *philos;

} t_main_data;

int     ph_str_to_num(const char *s, uint64_t *ret);
int	init_philos(int ac, char **av, t_main_data *data);
int print_err_return(char *s, int r);
#endif
