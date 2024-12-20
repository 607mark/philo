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

typedef enum e_status
{
	INIT,
	RUN,
	INTERRUPt,
}	t_type;


typedef struct s_ph
{
	int	id;
	pthread_t th;
	bool	dead;
	bool	eating;
	int	meals;
	unsigned long long init_time;
	unsigned long long eat_time;
	pthread_mutex_t mutex;
	bool mutex_init_status;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
	void *data;
} t_ph;

typedef struct s_data
{
	unsigned long long	n_philos;
	unsigned long long	t_to_die;
	unsigned long long	t_to_eat;
	unsigned long long	t_to_sleep;
	unsigned long long	n_t_to_eat;
	bool	endless;
	t_type	status;

	pthread_mutex_t main_mutex;
	bool main_mutex_init_status;
	pthread_mutex_t *forks;
	unsigned long long n_fork_mutex_init;
	t_ph *philos;
	pthread_t		monitor;
	pthread_t		*threads;
	unsigned long long n_threads;
} t_data;

// Utils
t_type access_status(int f, t_type type, t_data *d);
int     ph_str_to_num(const char *s, unsigned long long *ret);
int print_err_return(char *s, int r);
int free_heap_allocated(t_data *data);

// Input
int	parse_input(int ac, char **av, t_data *data);
int validate_input(t_data *data);

// Simulation
int init_simulation(t_data *data);
int run_simulation(t_data *data);

//mutex utils
bool access_bool(bool f, bool value, void *p, t_data *d);


#endif
