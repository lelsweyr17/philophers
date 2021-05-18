#include "philo_three.h"

void	take_a_fork(t_one *one)
{
	sem_wait(one->take_forks);
	sem_wait(one->fork);
	write_function(one, YELLOW FORK RESET);
	sem_wait(one->fork);
	write_function(one, YELLOW FORK RESET);
	sem_post(one->take_forks);
}

void	put_a_fork(t_one *one)
{
	sem_post(one->fork);
	sem_post(one->fork);
}
