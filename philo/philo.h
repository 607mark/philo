#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>


typedef struct s_time
{

} t_time;


typedef struct s_ph
{
	int	id;
	pthread_t th;
	bool	dead;
	bool	eating;
	int	meals;
	unsigned long long init_time;
	unsigned long long eat_time;
	pthread_mutex_t *left;
	pthread_mutex_t *right;

} t_ph;

typedef struct s_main_data
{
	unsigned long long	n_philos;
	unsigned long long	t_to_die;
	unsigned long long	t_to_eat;
	unsigned long long	t_to_sleep;
	unsigned long long	n_t_to_eat;
	bool	endless;
	bool	dead;

	pthread_mutex_t *forks;
	t_ph *philos;
	pthread_t		monitor;
	pthread_t		*threads;
} t_main_data;

int     ph_str_to_num(const char *s, unsigned long long *ret);
int	parse_input(int ac, char **av, t_main_data *data);
int print_err_return(char *s, int r);
int validate_input(t_main_data *data);
int init_simulation(t_main_data *data);
int free_heap_allocated(t_main_data *data);
#endif
