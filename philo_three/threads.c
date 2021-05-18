#include "philo_three.h"

void	*life_cycle(void *all)
{
	t_all	*tmp;
	int		index;

	tmp = all;
	index = tmp->i;
	tmp->one[index].last_meal = 0;
	while (tmp->one[index].nbr_of_eats < tmp->philo->nbr_of_eats || \
	tmp->philo->nbr_of_eats == -1)
	{
		eating(&tmp->one[index]);
		if (tmp->one[index].nbr_of_eats == tmp->philo->nbr_of_eats)
			exit(STATUS_FULL);
		sleeping(&tmp->one[index]);
		thinking(&tmp->one[index]);
	}
	return (NULL);
}

int	create_threads(t_all *all)
{
	if (pthread_create(&all->t[all->i], NULL, life_cycle, all) != 0)
		return (1);
	pthread_detach(all->t[all->i]);
	if (pthread_create(&all->monitor->spy, NULL, philo_spy, all) != 0)
		return (1);
	pthread_join(all->monitor->spy, NULL);
	return (0);
}
