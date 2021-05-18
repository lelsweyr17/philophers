#include "philo_two.h"

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
	(*all)->one = (t_one *)malloc((*all)->philo->nbr_of_philos * \
	sizeof(t_one));
	(*all)->monitor = (t_monitor *)malloc(sizeof(t_monitor));
	(*all)->monitor->last_meal = (long int *)malloc((*all)->philo->nbr_of_philos \
	* sizeof(long int));
	if (!(*all)->time || !(*all)->one || !(*all)->monitor || \
	!(*all)->monitor->last_meal)
		return (0);
	return (1);
}

void	free_all(t_all *all)
{
	free(all->philo);
	free(all->time);
	free(all->one);
	free(all->monitor->last_meal);
	free(all->monitor);
	free(all);
}
