#include "philo_one.h"

int	get_start_time(t_all **all)
{
	if (gettimeofday(&(*all)->time->tv1, NULL) == -1)
		return (0);
	(*all)->time->start_time = (*all)->time->tv1.tv_sec * 1000 \
	+ (*all)->time->tv1.tv_usec / 1000;
	return (1);
}

int	get_time_of_action(t_one *one)
{
	if (gettimeofday(&one->get_time->tv2, NULL) == -1)
		return (0);
	one->get_time->finish_time = one->get_time->tv2.tv_sec * 1000 \
	+ one->get_time->tv2.tv_usec / 1000;
	if (one->nbr_of_eats == 0)
		one->last_eat = 0;
	else
		one->last_eat = one->get_time->finish_time + one->philo->time_to_eat;
	one->time = one->get_time->finish_time - one->get_time->start_time;
	return (1);
}
