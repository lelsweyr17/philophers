#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <semaphore.h>
# include <fcntl.h> 
# include <sys/stat.h> 
# include <sys/time.h>

# define FORK		"has taken a fork\n"
# define EAT		"is eating\n"
# define SLEEP		"is sleeping\n"
# define THINK		"is thinking\n"
# define DIED		"died\n"

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"
# define BOLD_FONT	"\e[1m"
# define RESET_BOLD	"\e[0m"

typedef struct s_time
{
	struct timeval	tv1;
	struct timeval	tv2;
	long int		start_time;
	long int		finish_time;
}	t_time;

typedef struct s_monitor
{
	pthread_t		spy;
	int				dead;
	long int		*last_meal;
	long int		current_time;
	int				full_philo;
	sem_t	        *write;
}	t_monitor;

typedef struct s_philo
{
	int	nbr_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_of_eats;
}	t_philo;

typedef struct s_one
{
	int				i;
	int				nbr_of_eats;
	long int		time;
	long int		last_meal;
	int				eating;
	t_time			*get_time;
	t_philo			*philo;
	pthread_t		*t;
	sem_t	        *write;
	sem_t	        *fork;
	sem_t			*take_forks;
}	t_one;

typedef struct s_all
{
	int				i;
	t_philo			*philo;
	t_one			*one;
	t_time			*time;
	pthread_t		*t;
	sem_t	        *index;
	sem_t	        *fork;
	sem_t			*take_forks;
	t_monitor		*monitor;
}	t_all;

/* VALIDATION */
int		validation(int argc, char **argv);

/* INITIALISATION */
void	semaphore_init(t_all *all);
void	init_struct_each_philo(t_all *all);
void	init_params(t_philo *philo, char **argv);

/* MEMORY */
int		get_memory_for_struct(t_all **all);
int		get_heap_memory(t_all **all);
void	free_all(t_all *all);

/* THREADS */
int		create_threads(t_all *all);

/* LIFE CYCLE */
void	*life_cycle(void *one);
void	write_function(t_one *one, char *message);

/* TIME */
int		get_start_time(t_all **all);
int		get_time_of_action(t_one *one);

/* ACTIONS */
void	eating(t_one *one);
void	sleeping(t_one *one);
void	thinking(t_one *one);

/* UTILS */
int		ft_strlen(char *str);
int		ft_atoi(char *str);

/* MONITOR */
void	my_usleep(long int time_in_usec);
void	*philo_spy(void *all);

#endif