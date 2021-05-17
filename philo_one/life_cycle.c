#include "philo_one.h"

void	write_function(t_one *one, char *message)
{
	get_time_of_action(one);
	pthread_mutex_lock(one->write);
	printf(BOLD_FONT "%ld\t" RESET_BOLD, one->time);
	printf(CYAN "philo " BOLD_FONT "№%d\t" RESET_BOLD RESET, one->i + 1);
	printf("%s", message);
	pthread_mutex_unlock(one->write);
}

void	take_a_fork(t_one *one)
{
	int index;

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
	int index;

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

void	eating(t_one *one)
{
	take_a_fork(one);
	one->nbr_of_eats++;
	one->eating = 1;
	write_function(one, GREEN EAT RESET);
	my_usleep(one->philo->time_to_eat * 1000);
	one->eating = 0;
	put_a_fork(one);
}

void	sleeping(t_one *one)
{
	write_function(one, BLUE SLEEP RESET);
	my_usleep(one->philo->time_to_sleep * 1000);
}

void	thinking(t_one *one)
{
	write_function(one, MAGENTA THINK RESET);
}
