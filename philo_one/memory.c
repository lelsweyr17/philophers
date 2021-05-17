#include "philo_one.h"

int	get_memory_for_struct(t_all **all)
{
	*all = (t_all *)malloc(sizeof(t_all));
	(*all)->philo = (t_philo *)malloc(sizeof(t_philo));
	if (!all || !(*all)->philo)
		return (0);
	return (1);
}

int	get_heap_memory(t_all **all)
{
	(*all)->time = (t_time *)malloc(sizeof(t_time));
	(*all)->fork = (pthread_mutex_t *)malloc((*all)->philo->nbr_of_philos * \
	sizeof(pthread_mutex_t));
	(*all)->one = (t_one *)malloc((*all)->philo->nbr_of_philos * \
	sizeof(t_one));
	(*all)->t = (pthread_t *)malloc((*all)->philo->nbr_of_philos * \
	sizeof(pthread_t));
	(*all)->monitor = (t_monitor *)malloc(sizeof(t_monitor));
	(*all)->monitor->write = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	(*all)->monitor->last_meal = (long int *)malloc((*all)->philo->nbr_of_philos * sizeof(long int));
	if (!(*all)->time || !(*all)->fork || !(*all)->one || !(*all)->t || \
	!(*all)->monitor || !(*all)->monitor->write || 	!(*all)->monitor->last_meal)
		return (0);
	return (1);
}

void	free_all(t_all *all)
{
	free(all->philo);
	free(all->time);
	free(all->fork);
	free(all->one);
	free(all->t);
	free(all->monitor->write);
	free(all->monitor->last_meal);
	free(all->monitor);
	free(all);
}