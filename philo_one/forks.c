#include "philo_one.h"

void	take_a_fork(t_one *one)
{
	pthread_mutex_lock(one->fork_right);
	write_function(one, YELLOW FORK RESET);
	pthread_mutex_lock(one->fork_left);
	write_function(one, YELLOW FORK RESET);
}

void	put_a_fork(t_one *one)
{
	pthread_mutex_unlock(one->fork_right);
	pthread_mutex_unlock(one->fork_left);
}
