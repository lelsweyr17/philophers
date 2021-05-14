#include "philo_one.h"

void	write_function(t_one *one, char *message)
{
	get_time_of_action(one);
	pthread_mutex_lock(one->write);
	printf("%ld\t", one->time);
	printf("%d\t", one->i + 1);
	printf("%s", message);
	pthread_mutex_unlock(one->write);
}

void	eating(t_one *one)
{
	pthread_mutex_lock(one->fork_minor);
	// printf("%d - ", one->i - 1);
	// write_function(one, FORK);
	pthread_mutex_lock(one->fork_major);
	// printf("%d\t", one->i);
	one->eating = 1;
	// get_time_of_action(one);
	one->nbr_of_eats++;
	write_function(one, FORK);
	write_function(one, EAT);
	usleep(one->philo->time_to_eat * 1000);
	one->eating = 0;
	pthread_mutex_unlock(one->fork_major);
	pthread_mutex_unlock(one->fork_minor);
}

void	sleeping(t_one *one)
{
	// get_time_of_action(one);
	write_function(one, SLEEP);
	usleep(one->philo->time_to_sleep * 1000);
}

void	thinking(t_one *one)
{
	// get_time_of_action(one);
	write_function(one, THINK);
}
