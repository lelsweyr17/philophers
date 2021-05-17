#include "philo_three.h"

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
	one->time = one->get_time->finish_time - one->get_time->start_time;
	if (!one->nbr_of_eats && one->eating)
		one->last_meal = 0;
	else if (one->nbr_of_eats && one->eating)
		one->last_meal = one->time;
	return (1);
}
