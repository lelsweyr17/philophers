#include "philo_one.h"

void	take_a_fork(t_one *one)
{
	int	index;

	index = one->i;
	if (index % 2)
	{
		pthread_mutex_lock(one->fork_right);
		write_function(one, YELLOW FORK RESET);
		pthread_mutex_lock(one->fork_left);
		write_function(one, YELLOW FORK RESET);
	}
	else
	{
		pthread_mutex_lock(one->fork_left);
		write_function(one, YELLOW FORK RESET);
		pthread_mutex_lock(one->fork_right);
		write_function(one, YELLOW FORK RESET);
	}
}

void	put_a_fork(t_one *one)
{
	int	index;

	index = one->i;
	if (index % 2)
	{
		pthread_mutex_unlock(one->fork_left);
		pthread_mutex_unlock(one->fork_right);
	}
	else
	{
		pthread_mutex_unlock(one->fork_right);
		pthread_mutex_unlock(one->fork_left);
	}
}